# Závěr

Vytyčené cíle projektu se mi podařilo splnit.
Aplikace zvládá zobrazovat data z&nbsp;několika aplikací.
Primární úkol, tedy přehledně a&nbsp;jednoduše prezentovat odjezdy MHD v&nbsp;Brně, panel zvládá výborně.
Každá aplikace si také hlídá poslední čas aktualizace a&nbsp;v&nbsp;případě potřeby sama vyvolá překreslení nových dat.

# Budoucí vývoj

Celý projekt jsem navrhl tak, aby bylo možně ho jednoduše rozšiřovat a v případě potřeb upravovat.
Pro přidání nové služby je nutné vytvořit pouze odvozený wrapper, který zpracuje konkrétní data služby a rozšířit panel o jednu virtuální obrazovku.

![](../media/panel/front.jpeg)