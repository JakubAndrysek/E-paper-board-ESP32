from pprint import pprint
import json



class Salina:
	"""! @brief """
	def __init__(self):
		"""! @brief Konstruktor pro vytvoření instance třídy Salina."""
		self.file = "salina.json"


	def getSalinaStop(self, stopParams):
		"""! @brief 
		"""

		with open(self.file, 'r') as departuresJson:
			departures = json.loads(departuresJson)
			return departures[stopParams]