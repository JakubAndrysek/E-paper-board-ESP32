# Vstupy panelu

Na mé desce LilyGo jsou připojena tři uživatelská tlačítka a jedno tvrdé reset tlačítko. Tento vstupní modul by měl zajišťovat příjem podnětů, která následně vyvolají změny v aplikaci. První tlačítko slouží k přepínání aplikací (modulů) na displeji. Zbylá dvě tlačítka slouží k

Po stisknutí tlačítka je automaticky zavolán callback neboli zpětné volání, které je specifické pro každou aplikaci.

dojde k překreslení displeje. Druhým řídícím prvkem je ubíhající čas. Panel si automaticky hlídá čas a v přednastavenou periodu vyvolá obnovení a aktualizaci dat.