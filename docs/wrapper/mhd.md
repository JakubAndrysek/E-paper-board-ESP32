# Odjezdy MHD

Tento modul vytvářím ve spolupráci s&nbsp;[IDSJMK](https://idsjmk.cz/). Díky čemuž jsem získal neomezený přístup k&nbsp;veřejnému API na webu [https://mapa.idsjmk.cz](https://mapa.idsjmk.cz/).

Více informací [v&nbsp;aplikaci](../aplikace/mhd.md)


## Odjezd ze zastávky s&nbsp;[ID 1146 a&nbsp;pozicí 1](https://mapa.idsjmk.cz/api/Departures?stopid=1146&postid=1)

![](../media/aplikace/mhd-web.png)

## Výstupní JSON

```json
{
    "data": {
      "StopID": 1146,
      "Message": "VÝLUKA PŘÍZŘENICE: Linky 49 a N94 jsou ukončeny v Dolních Heršpicích. Náhradní dopravu do Přízřenic a Modřic zajišťují linky x49 a x94. Více na www.dpmb.cz.\n\nVÝLUKA BĚLOHORSKÁ: Linky 55 a N98 jedou v úseku Dělnický dům - Vlkova ve směru do Líšně odklonem přes Malou Klajdovku.",
      "PostList": [
        {
          "PostID": 1,
          "Name": "1;1.kolej",
          "Departures": [
            {
              "LineName": "N89",
              "FinalStop": "Kníničky, U Luhu",
              "IsLowFloor": true,
              "TimeMark": "18min"
            },
            {
              "LineName": "N92",
              "FinalStop": "Černého",
              "IsLowFloor": true,
              "TimeMark": "18min"
            },
            {
              "LineName": "N95",
              "FinalStop": "Kamenný vrch",
              "IsLowFloor": true,
              "TimeMark": "18min"
            },
            {
              "LineName": "N97",
              "FinalStop": "Jírovcova",
              "IsLowFloor": true,
              "TimeMark": "18min"
            }
          ]
        }
      ],
      "FromCache": false,
      "Warning": "Downloading data using automated tools is forbidden, for API access contact Kordis JMK. Automatizované stahování dat není povolené, pro přístup k API kontaktujte Kordis JMK.",
      "Error": ""
    },
    "status": "ok",
    "time": "2022-05-15"
}
```