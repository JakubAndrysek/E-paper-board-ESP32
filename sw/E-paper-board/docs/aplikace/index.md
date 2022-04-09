# Aplikace

Cílem projektu je navrhnout a vyrobit univerzální domácí panel, který zajistí přehledné a rychlé zobrazování každodenních informací.

## Co to má umět

Řídící systém displeje by měl být univerzální a zvládat zobrazit jakákoliv data ve formátu JSON. Tento formát jsem zvolil, protože je velmi rozšířený a několik z požadovaných služeb již toto rozhraní nabízí.

Pro zbylé webové aplikace, které nedisponují veřejným API ve formátu JSON bude nutné navrhnout malý server, který bude periodicky data z webů zpracovávat a zprostředkovávat je v použitelném formátu JSON.