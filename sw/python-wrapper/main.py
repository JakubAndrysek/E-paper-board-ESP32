import requests
from bs4 import BeautifulSoup
from lxml import etree
from pprint import pprint
import json
from flask import Flask, request, abort
from dotenv import dotenv_values
from skola_online import SkolaOnline
from fablab import Fablab
from salina import Salina
from functools import wraps

app = Flask(__name__)

# Source: https://coderwall.com/p/4qickw/require-an-api-key-for-a-route-in-flask-using-only-a-decorator
# The actual decorator function
def require_appkey(view_function):
    @wraps(view_function)
    # the new, post-decoration function. Note *args and **kwargs here.
    def decorated_function(*args, **kwargs):
        config = dotenv_values(".env")
        if request.args.get('api_key') and request.args.get('api_key') == config['API_KEY']:
            return view_function(*args, **kwargs)
        else:
            abort(401)
    return decorated_function

# http://127.0.0.1:5000/marksLast/?api_key=
@app.route('/marksLast/')
@require_appkey
def marksLastFlask():
	"""! @brief URL pro získání posledních známek.
	
	@return JSON s posledními známkami
	"""
	username = request.args.get('username')

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
	"""! @brief URL pro získání známek podle předmětu.
	
	@return JSON se známkami podle předmětu
	"""

	return json.dumps({"error": "Neni implementovano :-("})

	# username = request.args.get('username')
	# password = request.args.get('password')
	# file .env
	# USERNAME=username
	# PASSWORD=password
	config = dotenv_values(".env")

	try:
		sol = SkolaOnline(config["USERNAME"], config["PASSWORD"])
		subject = request.args.get('subject')
		lastMarks = sol.getLastMarksBySubject(subject)

		lastMarksJsonArr = []
		for mark in lastMarks:
			print(mark)
			lastMarksJsonArr.append(mark.__dict__)
		return json.dumps(lastMarksJsonArr)

	except Exception as e:
		print(e)
		return json.dumps({"error": str(e)})



# http://127.0.0.1:5000/fablabNow/
@app.route('/fablabNow/')
def fablabNowFlask():
	"""! @brief URL pro získání aktuálního stavu strojů ve Fsblabu.
	@return JSON s aktuálním stavem strojů ve Fsblabu
	"""

	return json.dumps({"error": "Neni implementovano :-("})

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


@app.route('/salina')
def salinaFlask():
	params = request.args.get('params')

	try:
		salina = Salina()
		salinaStop = salina.getSalinaStop("1272")
		return json.dumps(salinaStop)
	except Exception as e:
		print(e)
		return json.dumps({"error": str(e)})


if __name__ == '__main__':
	"""! @brief Spouštění aplikace.
	Hlavní funkce aplikace - spouští Flask server.
	"""

	app.run(host="0.0.0.0")
	# app.run(debug=True, host="0.0.0.0")
