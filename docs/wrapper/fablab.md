# FabLab now

FabLab Wrapper zpracovává data o obsazenosti komunitní dílny FabLab a o využití místních strojů.
Wrapper stáhne data	z webu [Fablab NOW](https://now.fablabbrno.cz/) a zpracuje je.

# Zpracování dat

Webová stránka je v HTML kódu, který pomocí knihovny LXML rozparsuji.
Následně program prochází po jednotlivých záznamech o stroji a zjišťuje, zda je obsazen.
Výsledky se ukládají do tříd, ze kterých se vytváří výsledný JSON.


![](../media/aplikace/fablab-web.png)

## Vstupní HTML data

```html
...
<div class="machine green"><h3>3D  Maria</h3> <p>— available</p></div>
<div class="machine green"><h3>3D  Niki</h3> <p>— available</p></div>
<div class="machine red"><h3>3D  Pavlína</h3> <p>— working</p> (5 days)</div>
<div class="machine red"><h3>3D  Tereza</h3> <p>— working</p> (4 days)</div>
...
```

## Formát JSON souboru

```json
{
    "data": {
        "members": "0-2",
        "machines": [
            {
                "name": "Bruska",
                "status": "— available"
            },
            {
                "name": "Innovis V5",
                "status": "— available"
            },
            {
                "name": "Ohýbačka",
                "status": "— available"
            },
			...
        ],
        "printers": [
            {
                "name": "3D  Maria",
                "status": "— working (3 hours)"
            },
            {
                "name": "3D  Niki",
                "status": "— available"
            },
            {
                "name": "3D  Pavlína",
                "status": "— working (5 days)"
            },
            {
                "name": "3D  Tereza",
                "status": "— working (4 days)"
            }
			...
        ]
    },
    "status": "ok",
    "time": "2022-05-15"
}
```