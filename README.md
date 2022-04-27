# E-paper panel

Cílem tohoto projektu je navrhnout a vytvořit univerzální domácí panel. Hlavním úkolem tohoto panelu je zobrazovat aktuální odjezdy městské hromadné dopravy. Díky bezdrátovému připojení na WiFi a komunikací se zpracujícím servery je displej schopen zobrazit jakékoliv údaje a zjednodušit tak uživateli přístupnost ke každodenním informacím.

Součásti systému:

- [x] [odjezdy MHD - Brno](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/mhd)
- [x] [nejnovější známky ze školy](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/sol-znamky)
- [x] [předpověď počasí Alojz](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/alojz)
- [ ] [aktuální školní rozvrh](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/sol-rozvrh)
- [ ] [využití strojů ve FabLabu](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/fablab)
- [ ] …

![demo](docs/media/panel/ttgo-front.png)
## Základní informace

Domácí panel je postaven na modulu [LilyGo-T5-Epaper](https://github.com/Xinyuan-LilyGO/LilyGo-T5-Epaper-Series) který tvoří velmi velmi významnou kombinaci mezi výkonným mikrokontrolérem ESP32 a tříbarevným E-paper displejem.

### ESP32

ESP32 je výkonný mikrokontrolér, který disponuje konektivitou WiFi a Bluetooth.

### E-paper displej

Do svého projektu jsem si zvolil decentní tříbarevný displej s velikostí 2,7 palců. Tento displej má rozlišení 264 na 176 bodů.

## Více informací v [kompletní dokumentaci](https://jakubandrysek.github.io/E-paper-board-ESP32/)