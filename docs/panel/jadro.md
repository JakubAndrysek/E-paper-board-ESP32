# Jádro aplikace

Řízení chodu aplikace zajišťuje třída `Manager`.

Třída manager nejdříve inicializuje všechny [vstupy](./vstup.md) a&nbsp;následně naváže komunikaci s&nbsp;[displejem](./vykreslovani.md). 
Poté manager zaregistruje všechny aplikace a&nbsp;spustí první z&nbsp;nich.


## Aplikace

Celý modul aplikací jsem navrhoval objektivně orientovaný a&nbsp;využívá tedy dědičnosti.

## Rodičovská aplikace

Rodičovská aplikace obsahuje základní atributy a&nbsp;metody které jsou společné pro všechny potomky.

Výchozí aplikace si také drží dva callbacky.
1. na zavolání webového dotazu, který získá JSON soubor pro budoucí zpracování
2. callback na nové překreslení displeje. Využívá se při zmáčknutí tlačítka.

Rodičovská aplikace se také většinou stará o&nbsp;aktualizaci displeje - `update()`. Volá virtuální metodu `showDataOnDisplay()` která je nadefinovaná potomky Aplikace.
Každá aplikace si také drží svůj název s&nbsp;popisem pro účely debugování v&nbsp;metodě `toString()`.

## Potomci Aplikace


Jednotlivé aplikace dědí základní atributy a&nbsp;metody z&nbsp;rodiče `Aplikace`.
Díky tomu mají všechny aplikace stejné rozhraní a&nbsp;jde volat například `update()` nad polem všech aplikací.

### Tlačítka

Každá aplikace musí ve své implementaci definovat virtuální metody reagující na stisk tlačítek.

### Vykreslení

Metodu `showDataOnDisplay()` si definuje každá aplikace podle sebe. Slouží k&nbsp;hlavnímu zobrazení dat na displej.

Více o&nbsp;[vykreslovaní na displej](./vykreslovani.md).

### Pomocné metody

Kromě těchto standardních metod si každá aplikace přidává svoje doplňující, které zjednodušují práci.

Jde například o&nbsp;metodu, která vykreslí jeden řádek se známkou. 
Tato metoda je poté volána opakovaně podle počtu známek v&nbsp;JSON souboru. 


