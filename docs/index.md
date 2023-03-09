# E-paper panel

## Cíl projektu

Cílem tohoto projektu je navrhnout a vytvořit univerzální domácí panel. Hlavním úkolem tohoto panelu je zobrazovat aktuální odjezdy městské hromadné dopravy. Díky bezdrátovému připojení na WiFi a komunikací se zpracujícím servery je displej schopen zobrazit jakékoliv údaje a zjednodušit tak uživateli přístupnost ke každodenním informacím.

### Součásti systému:

- [x] [odjezdy MHD - Brno](aplikace/mhd.md)
- [x] [nejnovější známky ze školy](aplikace/sol-znamky.md)
- [x] [předpověď počasí Alojz](aplikace/alojz.md)
- [x] [využití strojů ve FabLabu](aplikace/fablab.md)
- [ ] [aktuální školní rozvrh](aplikace/sol-rozvrh.md)
- [ ] …

![demo](media/aplikace/salinaApp.jpeg)

## Základní informace

Domácí panel je postaven na modulu [LilyGo-T5-Epaper](https://github.com/Xinyuan-LilyGO/LilyGo-T5-Epaper-Series) který tvoří velmi významnou kombinaci mezi výkonným mikrokontrolérem ESP32 a&nbsp;tříbarevným E-paper displejem.

### ESP32

ESP32 je výkonný mikrokontrolér, který disponuje konektivitou WiFi a&nbsp;Bluetooth.

### E-paper displej

Do svého projektu jsem si zvolil decentní tříbarevný displej s&nbsp;velikostí 2,7 palců. Který má rozlišení 264 na 176 pixelů.

![demo](media/panel/case.jpeg)