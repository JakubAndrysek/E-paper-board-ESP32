import requests
from bs4 import BeautifulSoup
from lxml import etree
from pprint import pprint
import json
from flask import Flask, request, abort
from dotenv import dotenv_values
from skola_online import SkolaOnline
from fablab import Fablab

app = Flask(__name__)


# http://127.0.0.1:5000/marksLast/
@app.route('/marksLast/')
def marksLastFlask():
	# username = request.args.get('username')
	# password = request.args.get('password')
	# file .env
	# USERNAME=username
	# PASSWORD=password
	config = dotenv_values(".env")

	try:
		sol = SkolaOnline(config["USERNAME"], config["PASSWORD"])
		lastMarks = sol.getLastMarks()

		lastMarksJsonArr = []
		for mark in lastMarks:
			print(mark)
			lastMarksJsonArr.append(mark.__dict__)
		return json.dumps(lastMarksJsonArr)

	except Exception as e:
		print(e)
		return json.dumps({"error": str(e)})

# http://127.0.0.1:5000/marksSubject/
@app.route('/marksSubject/')
def marksSubjectFlask():
	# username = request.args.get('username')
	# password = request.args.get('password')
	# file .env
	# USERNAME=username
	# PASSWORD=password
	# config = dotenv_values(".env")
	return json.dumps({"error": "Neni implementovano :-("})


# http://127.0.0.1:5000/fablabNow/
@app.route('/fablabNow/')
def fablabNowFlask():
	try:
		fablab = Fablab()
		machinesStat = fablab.getMachinesStatus()

		lastMarksJsonArr = []
		for machine in machinesStat:
			print(machine)
			lastMarksJsonArr.append(machine.__dict__)
		return json.dumps(lastMarksJsonArr)

	except Exception as e:
		print(e)
		return json.dumps({"error": str(e)})

if __name__ == '__main__':
	app.run(host="0.0.0.0")
