import requests
from bs4 import BeautifulSoup
from lxml import etree
from pprint import pprint
from universal import GetRequestException


class Machine:
	name: str  # date of the last mark
	status: str  # subject of the last mark

	def __init__(self, name, status):
		self.name = name
		self.status = status

	def __str__(self):
		return f"{self.name} - {self.status}"


class Fablab:
	def __init__(self):
		self.urlBase = "https://now.fablabbrno.cz/"

	def __getRequest(self):
		getMarks = requests.get(self.urlBase)
		if getMarks.status_code == 200:
			return getMarks.text
		else:
			raise GetRequestException()

	def getMachinesStatus(self):
		html = self.__getRequest()
		domTable = etree.HTML(str(html))
		table = domTable.cssselect('div.machine')

		machinesArr = []

		for machine in table:
			print(etree.tostring(machine, encoding="unicode", pretty_print=True))
			name = machine.cssselect('h3')[0].text
			status = machine.cssselect('p')[0].text
			if machine.cssselect('p.span')[0]:
				status += machine.cssselect('p.span')[0].text
			machinesArr.append(Machine(name, status))

		# machinesArr.append(Machine("Speedy 400", "available"))
		# machinesArr.append(Machine("Termolis", "available"))

		return machinesArr
		#
		# lastMarks = []
		# for tableRow in table[0]:
		# 	if tableRow.tag == "tr":
		# 		if tableRow[2][0][0].text:
		# 			mark = tableRow[2][0][0].text
		# 		else:
		# 			mark = tableRow[2][0][0][0].text
		# 		lastMarks.append(LastMark(tableRow[0].text, tableRow[1].text, mark))
		return lastMarks
