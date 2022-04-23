import requests
from bs4 import BeautifulSoup
from lxml import etree
from pprint import pprint
import json
from flask import Flask, request, abort
from dotenv import dotenv_values

class SkolaOnlineLoginException(Exception):
	def __init__(self, message=""):
		self.message = f"SkolaOnline Login Exception: {message}"
		super().__init__(self.message)


class GetRequestException(Exception):
	def __init__(self, message="Get Request Exception"):
		self.message = message
		super().__init__(self.message)


class LastMark:
	date: str  # date of the last mark
	subject: str  # subject of the last mark
	mark: int  # mark of the last mark

	def __init__(self, date: str, subject: str, mark: str):
		self.date = date
		self.subject = subject
		self.mark = mark

	def __str__(self):
		return f"{self.date} {self.subject} {self.mark}"


class SkolaOnline:
	def __init__(self, name: str, pwd: str):
		self.name = name
		self.pwd = pwd
		self.urlBase = "https://aplikace.skolaonline.cz/SOL/App/"

		self.webSession = requests.Session()
		self.__logInSol()

	def __logInSol(self):
		url = 'https://aplikace.skolaonline.cz/SOL/Prihlaseni.aspx'
		data = {"__EVENTTARGET": "dnn$ctr994$SOLLogin$btnODeslat", "__EVENTARGUMENT": "", "__VIEWSTATE": "",
				"__VIEWSTATEGENERATOR": "", "__VIEWSTATEENCRYPTED": "", "__PREVIOUSPAGE": "", "__EVENTVALIDATION": "",
				"dnn$dnnSearch$txtSearch": "", "JmenoUzivatele": self.name, "HesloUzivatele": self.pwd, "ScrollTop": "",
				"__dnnVariable": "", "__RequestVerificationToken": "", }

		postLogin = self.webSession.post(url, data=data)
		if postLogin.status_code != 200:
			raise SkolaOnlineLoginException(f"status_code = {postLogin.status_code}")

	def __getRequest(self, urlBase, params=None):
		getMarks = self.webSession.get(urlBase + params)
		if getMarks.status_code == 200:
			return getMarks.text
		else:
			raise GetRequestException()

	def getTimeTable(self):
		html = self.__getRequest("https://aplikace.skolaonline.cz/SOL/App", "/Kalendar/KZK001_KalendarTyden.aspx")
		soup = BeautifulSoup(html, 'html.parser')

		# htmlTable = soup.find(id="CCADynamicCalendarTable")
		htmlTables = soup.findAll("table", attrs={'class': 'DctInnerTableType10'})

		for table in htmlTables:
			sub = table.contents[1].contents[1].contents[0].text
			xclass = table.contents[1].contents[1].contents[1].contents[0]
			room = table.contents[1].contents[1].contents[1].contents[2]
			print(f"{sub} -> {room}")

		domTable = etree.HTML(str(soup))
		# domTable = etree.HTML(html)
		table = domTable.xpath('//*[@id="CCADynamicCalendarTable"]')
		name = domTable.xpath('//*[@id="LBLStudent"]')
		test = domTable.xpath('//*[@id="C34353962#1#2#2"]/span[1]')

		return domTable

	def getMarks(self):
		rawMarks = self.__getRequest("https://aplikace.skolaonline.cz/SOL/App", "/Hodnoceni/KZH001_HodnVypisStud.aspx")
		return rawMarks

	def getLastMarks(self):
		html = self.__getRequest("https://aplikace.skolaonline.cz/SOL/App", "/Spolecne/KZZ010_RychlyPrehled.aspx")
		domTable = etree.HTML(str(html))
		table = domTable.xpath('//*[@id="ctl00_bodyFooter_boxHodnVypisStud_ctl00_Content"]/table')

		if not table:
			raise SkolaOnlineLoginException("Bad username or password")

		lastMarks = []
		for tableRow in table[0]:
			if tableRow.tag == "tr":
				if tableRow[2][0][0].text:
					mark = tableRow[2][0][0].text
				else:
					mark = tableRow[2][0][0][0].text
				lastMarks.append(LastMark(tableRow[0].text, tableRow[1].text, mark))

		return lastMarks


app = Flask(__name__)


# http://127.0.0.1:5000/marksLast/
@app.route('/marksLast/')
def marksLastFlask():
	# username = request.args.get('username')
	# password = request.args.get('password')
	# print(username, password)

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
	# print(username, password)

	# file .env
	# USERNAME=username
	# PASSWORD=password
	config = dotenv_values(".env")

	# try:
	# 	sol = SkolaOnline(config["USERNAME"], config["PASSWORD"])
	# 	timeTable = sol.getTimeTable()
	#
	# 	# lastMarksJsonArr = []
	# 	# for mark in lastMarks:
	# 	# 	print(mark)
	# 	# 	lastMarksJsonArr.append(mark.__dict__)
	# 	return json.dumps(lastMarksJsonArr)
	#
	# except Exception as e:
	# 	print(e)
	# 	return json.dumps({"error": str(e)})
	return json.dumps({"error": "Neni implementovano :-("})

if __name__ == '__main__':
	app.run(host="0.0.0.0")
