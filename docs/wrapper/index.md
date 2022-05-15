# Wrapper

Wrapper je naprogramovaný v jazyce Python pomocí knihovny [Flask](https://flask.palletsprojects.com).

Wrapper překládá webová data do jednoduše zpracovatelného formátu pro E-paper panel.
Wrapper stáhne data z webu, zpracuje je a odešle ve formátu JSON.

## Web scraping

Wrapper pro získání dat z internetu využívá [Web scraping](https://en.wikipedia.org/wiki/Web_scraping) [en].

Jedná se o strojové čtení dat z webových stránek. 

Více informací o [web scrapingu](https://naucse.python.cz/2020/pydata-ostrava-jaro/pydata/webscraping/)

# Moduly wreapperu

Wrapper se skládá z aplikačních modulů.
Každý aplikace na E-paper panelu má svůj modul pro zpracování dat.
Na základě URL dotazu se zavolá správný modul, předají se mu přijaté parametry a vrátí se výsledek ve formátu JSON.

Jednotlivé moduly jsou popsány v následujících kapitolách.