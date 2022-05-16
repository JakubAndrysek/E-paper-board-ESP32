# Technologie

Jedním z&nbsp;cílů, které jsem si pro tento projekt vytyčil bylo vyzkoušet si nové technologie a&nbsp;prozkoumat jejich možnosti.
Během tvorby projektu jsem si procvičil práci v&nbsp;pěti programovacích a&nbsp;značkovacích jazycích.

## Panel

Software pro zobrazovací panel jsem tvořil v&nbsp;jazyce [C++](https://en.wikipedia.org/wiki/C%2B%2B).
Při&nbsp;návrhu aplikačních modulů jsem využil dědičnosti, díky které je velmi jednoduché rozšiřovat aplikace a&nbsp;doplňovat do nich společné vlastnosti. 

## Wrapper

Wrapper tvoří komunikační vrstvu mezi panelem a&nbsp;zdrojovými servery.
Pro jeho vytvoření jsem zvolil jazyk [Python](https://www.python.org/) a&nbsp;knihovnu [Flask](https://flask.palletsprojects.com/).
Ta zprostředkovává webový server, který přijímá požadavky z&nbsp;panelu a&nbsp;vrací JSON odpověď.
O&nbsp;HTTP dotazy se stará knihovna [requests](https://docs.python-requests.org/en/master/).


## Dokumentace
Pro tvorbu dokumentace jsem zvolil nástroj [MkDocs](https://mkdocs.org/), který se mi osvědčil na předchozích projektech.
MkDocs je nástroj vytvořený v&nbsp;jazyce Python a&nbsp;existuje do něj velké množství rozšiřujících pluginů.

![](media/sw/dokumentace.png)

### MkDoxy

[MkDoxy]() je můj doplněk&nbsp;do MkDocs, který má za úkol vytvářet kódovou dokumentaci.
Plugin je postaven na populárním nástroji [Doxygen](https://www.doxygen.org/), který vygeneruje XML soubory, ze kterých následně vzniká API dokumentace zdrojového kódu.