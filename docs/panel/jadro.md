# Jádro aplikace

Řízení chodu aplikace zajišťuje třída `Manager`.

Třída manager nejdříve inicializuje všechny [vstupy](./vstup.md) a následně naváže komunikaci s [displejem](./vykreslovani.md). 
Poté manager zaregistruje všechny aplikace a spustí první z nich.


## Aplikace

Celý modul aplikací jsem navrhoval objektivně orientovaný a využívá tedy dědičnosti.

## Rodičovská aplikace

Rodičovská aplikace obsahuje základní atributy a metody které jsou společné pro všechny potomky.

Výchozí aplikace si také drží dva callbacky.
1. na zavolání webového dotazu, který získá JSON soubor pro budoucí zpracování
2. callback na nové překreslení displeje. Využívá se při zmáčknutí tlačítka.

Rodičovská aplikace se také většinou stará o aktualizaci displeje - `update()`. Volá virtuální metodu `showDataOnDisplay()` která je nadefinovaná potomky Aplikace.
Každá aplikace si také drží svůj název s popisem pro účely debugování v metodě `toString()`.

## Potomci Aplikace


Jednotlivé aplikace dědí základní atributy a metody z rodiče `Aplikace`.
Díky tomu mají všechny aplikace stejné rozhraní a jde volat například `update()` nad polem všech aplikací.

### Tlačítka

Každá aplikace musí ve své implementaci definovat virtuální metody reagující na stisk tlačítek.

### Vykreslení

Metodu `showDataOnDisplay()` si definuje každá aplikace podle sebe. Slouží k hlavnímu zobrazení dat na displej.

Více o [vykreslovaní na displej](./vykreslovani.md).

### Pomocné metody

Kromě těchto standardních metod si každá aplikace přidává svoje doplňující, které zjednodušují práci.

Jde například o metodu, která vykreslí jeden řádek se známkou. 
Tato metoda je poté volána opakovaně podle počtu známek v JSON souboru. 


