from pprint import pprint
import json
import requests


class Alojz:
    """! @brief """

    def __init__(self):
        """! @brief Konstruktor pro vytvoření instance třídy Alojz."""
        self.url = "https://lovecka.info/YrNoProvider1/alojz/alojz"

    def getWeather(self, params):
        """! @brief Vrací data o počasí ze serveru Alojz

        @param params: example: ?alojzId=brno&lat=49.195060&lon=16.606837&alt=237 as array {"alojzId": "brno", "lat": 49.195060, "lon": 16.606837, "alt": 237}
        @return: Počasí ze serveru alojz (https://github.com/petrbrouzda/YrNoProvider)
        """
        response = requests.get(self.url, params=params)
        return response.json()
