# FabLab now

### Ve vývoji

![](../media/aplikace/fablab-web.png)

## Vstupní HTML data

```html
...
<div class="machine red"><h3>3D  Anicka</h3> <p>— working</p> (3 days)</div>
<div class="machine orange"><h3>3D  Arthemis</h3> <p>— <span title="Důvod: Vadna PINDA">out of order<span></p></div>
<div class="machine green"><h3>3D  Calypso MM</h3> <p>— available</p></div>
<div class="machine green"><h3>3D  Iris</h3> <p>— available</p></div>
<div class="machine red"><h3>3D  Lucia</h3> <p>— working</p> (22 min)</div>
<div class="machine red"><h3>3D  Maria</h3> <p>— working</p> (44 hours)</div>
<div class="machine green"><h3>3D  Niki</h3> <p>— available</p></div>
...
```

## Formát JSON souboru

```json
[
	{
		"machine": "3D  Anicka",
		"status": "working",
		"time": "(3 days)"
	},
	{
		"machine": "3D  Arthemis",
		"status": "out of order",
		"time": ""
	},	
	{
		"machine": "3D  Calypso MM",
		"status": "available",
		"time": ""
	},
	...	
]
```