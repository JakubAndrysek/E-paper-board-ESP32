# Předpověď počasí Alojz

Stránka [Alojz.cz](https://alojz.cz/brno) je mezi českými bastlíří velmi populární.
Bohužel však v poslední době v některých případech vrací chybná data.
Proto vývojář Petr Brouzda navrhl svoji alternativu postavenou na také na webu Alojz, ale při nefunkčnosti služby se zobrazí data přímo z norského meteo radaru [Yr.no](https://www.yr.no/).

![](../media/aplikace/alojz.png)

## YrNoProvider

Projekt na [GitHubu](https://github.com/petrbrouzda/YrNoProvider)

Data pro [Brno](https://lovecka.info/YrNoProvider1/alojz/alojz?alojzId=brno&lat=49.195060&lon=16.606837&alt=237) (`...alojz?alojzId=brno&lat=49.195060&lon=16.606837&alt=237`)

```json
{
  "data": {
    "code": 200,
    "prefer": "day1",
    "version": "v1",
    "command": "GET",
    "url_id": "-",
    "day1": {
      "today_tomorrow": "Dnes",
      "string": "Vezmi si mikinu a deštník. Dopoledne 10-14 °C, déšť 0.4 mm. Odpoledne 10-16 °C, déšť 5.7 mm, až 2.7 mm srážek za hodinu!",
      "created": "2022-04-24 00:37:31"
    },
    "day2": {
      "today_tomorrow": "Zítra",
      "string": "",
      "created": "2022-04-24 00:37:31"
    },
  },
  "status": "ok",
  "time": "2022-04-24"
}
```