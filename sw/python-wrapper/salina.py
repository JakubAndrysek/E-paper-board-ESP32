from pprint import pprint
import json
import requests


class Salina:
    """! @brief """

    def __init__(self):
        """! @brief Konstruktor pro vytvoření instance třídy Salina."""
        self.url = "https://mapa.idsjmk.cz/api/Departures"

    def getDepartures(self, params):
        """! @brief

        @params stop_id ID zastávky example: ?stopid=1146&postid=1 as array {'stopid': '1146', 'postid': '1'}
        @return vrátí odjezdy šalin ze zastávky
        """
        response = requests.get(self.url, params=params)
        return response.json()
