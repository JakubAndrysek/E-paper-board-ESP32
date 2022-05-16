# Wrapper

Wrapper je naprogramovaný v&nbsp;jazyce Python pomocí knihovny [Flask](https://flask.palletsprojects.com).

Wrapper překládá webová data do jednoduše zpracovatelného formátu pro E-paper panel.
Wrapper stáhne data z&nbsp;webu, zpracuje je a&nbsp;odešle ve formátu JSON.

## Web scraping

Wrapper pro získání dat z&nbsp;internetu využívá [Web scraping](https://en.wikipedia.org/wiki/Web_scraping) [en].

Jedná se o&nbsp;strojové čtení dat z&nbsp;webových stránek. 

Více informací o&nbsp;[web scrapingu](https://naucse.python.cz/2020/pydata-ostrava-jaro/pydata/webscraping/)

# Moduly wreapperu

Wrapper se skládá z&nbsp;aplikačních modulů.
Každý aplikace na E-paper panelu má svůj modul pro zpracování dat.
Na základě URL dotazu se zavolá správný modul, předají se mu přijaté parametry a&nbsp;vrátí se výsledek ve formátu JSON.

Jednotlivé moduly jsou popsány v&nbsp;následujících kapitolách.