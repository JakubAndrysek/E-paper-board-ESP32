import requests
from bs4 import BeautifulSoup
from lxml import etree, html
from universal import GetRequestException

normalizeString = lambda text: text\
    .replace('\u2013', '-')\
    # .replace('', ' ')\
    # .replace('â', ' ')\
    # .replace('—', '')


class Machine:
    """! @brief Uchovává informace o stroji."""
    name: str  # date of the last mark
    status: str  # subject of the last mark

    def __init__(self, name, status):
        """! @brief Konstruktor pro vytvoření instance třídy Machine.
        @param name název stroje
        @param status stav stroje
        """

        # název stroje
        self.name = normalizeString(name)

        # stav stroje
        self.status = normalizeString(status)

    def __str__(self):
        """! @brief Vrací řetězec s informacemi o známkách."""
        return f"{self.name} - {self.status}"


class FablabNow:
    """! @brief Uchovává informace o aktuálních známkách."""

    members: int  # počet lidí ve Fablabu
    printers: list  # seznam tiskáren
    machines: list  # seznam strojů

    def __init__(self, members, printers, machines):
        """! @brief Konstruktor pro vytvoření instance třídy FablabNow.
        @param people počet lidí ve Fablabu
        @param machines seznam strojů
        """
        # počet lidí ve Fablabu
        self.members = normalizeString(members)

        # seznam tiskáren
        self.printers = printers

        # seznam strojů
        self.machines = machines

    def __str__(self):
        """! @brief Vrací řetězec s informacemi o známkách."""
        return f"{self.members} people in Fablab, , {len(self.printers)} printers, {len(self.machines)} machines"


class Fablab:
    """! @brief Získává data z webu Fablab now"""

    def __init__(self):
        """! @brief Konstruktor pro vytvoření instance třídy Fablab."""
        self.urlBase = "https://now.fablabbrno.cz/"

    def __getRequest(self):
        """! @brief Vrací HTML stránku.
        @return HTML stránka
        @throws GetRequestException
        """
        getMarks = requests.get(self.urlBase)
        if getMarks.status_code == 200:
            return getMarks.content
        else:
            raise GetRequestException()

    def getMachinesStatus(self):
        """! @brief Vrací objekt FablabNow.

        @return objekt FablabNow
        """

        htmlReq = self.__getRequest()
        tree = html.fromstring(htmlReq)

        members = tree.xpath("//p[contains(@class, 'onsite')]/b/text()")[0]
        machines = tree.xpath("//div[contains(@class, 'machine')]")
        printerArray = []
        machinesArr = []

        # / html / body / div[2] / p

        for machine in machines:
            # print(etree.tostring(machine, encoding="unicode", pretty_print=True))
            try:
                name = machine.xpath("./h3/text()")[0]
                status = machine.xpath("./p/text()")[0]
                if statusEx := machine.xpath("./p")[0].tail:
                    status += str(statusEx)
                if name[:2] == "3D":
                    printerArray.append(Machine(name, status))
                else:
                    machinesArr.append(Machine(name, status))
            except IndexError as e:
                continue

        return FablabNow(members, printerArray, machinesArr)
