# Aplikace

Cílem projektu je navrhnout a&nbsp;vyrobit univerzální domácí panel, který zajistí přehledné a&nbsp;rychlé zobrazování každodenních informací.

## Co to má umět

Řídící systém displeje by měl být univerzální a&nbsp;zvládat zobrazit jakákoliv data ve formátu JSON. Tento formát jsem zvolil, protože je velmi rozšířený a&nbsp;několik z&nbsp;požadovaných služeb již toto rozhraní nabízí.

Pro zbylé webové aplikace, které nedisponují veřejným API ve formátu JSON bude nutné navrhnout malý server, který bude periodicky data z&nbsp;webů zpracovávat a&nbsp;zprostředkovávat je v&nbsp;použitelném formátu JSON.