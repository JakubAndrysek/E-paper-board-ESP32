# Abstraktní logika panelu

Pro návrh této aplikace jsem chtěl využít nejlepších prostředků a technických možností, s tím ale přichází problém s testováním a kontrolou všech vnitřních prvků.

Aplikaci jsem proto vytvořil jako abstraktní model, který přijímá podněty a data &quot;zvenčí&quot;, následně je uvnitř pomocí algoritmů transformuje a na konec odevzdává zpět ven pro zobrazovací část. Díky tomuto modelu je tuto část aplikace možné testovat odděleně bez nutnosti konkrétního hardwaru.