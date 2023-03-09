# E-paper panel

<p align="center">
<a href="https://hits.seeyoufarm.com"><img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FJakubAndrysek%2FE-paper-board-ESP32&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true"/></a>
<img src="https://img.shields.io/github/license/JakubAndrysek/E-paper-board-ESP32?style=flat-square">
</p>

Cílem tohoto projektu je navrhnout a vytvořit univerzální domácí panel. Hlavním úkolem tohoto panelu je zobrazovat aktuální odjezdy městské hromadné dopravy. Díky bezdrátovému připojení na WiFi a komunikací se zpracujícím servery je displej schopen zobrazit jakékoliv údaje a zjednodušit tak uživateli přístupnost ke každodenním informacím.

Součásti systému:

- [x] [odjezdy MHD - Brno](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/mhd)
- [x] [nejnovější známky ze školy](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/sol-znamky)
- [x] [předpověď počasí Alojz](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/alojz)
- [x] [využití strojů ve FabLabu](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/fablab)
- [ ] [aktuální školní rozvrh](https://jakubandrysek.github.io/E-paper-board-ESP32/aplikace/sol-rozvrh)
- [ ] …

<a href="https://jakubandrysek.github.io/E-paper-board-ESP32/" target="_blank"><h3 align="center">DOKUMENTACE</h3></a>

![demo](docs/media/aplikace/salinaApp.jpeg)
## Základní informace

Domácí panel je postaven na modulu [LilyGo-T5-Epaper](https://github.com/Xinyuan-LilyGO/LilyGo-T5-Epaper-Series) který tvoří velmi významnou kombinaci mezi výkonným mikrokontrolérem ESP32 a tříbarevným E-paper displejem.

### ESP32

ESP32 je výkonný mikrokontrolér, který disponuje konektivitou WiFi a Bluetooth.

### E-paper displej

Do svého projektu jsem si zvolil decentní tříbarevný displej s velikostí 2,7 palců. Tento displej má rozlišení 264 na 176 bodů.

![demo](docs/media/panel/case.jpeg)

## Více informací v [kompletní dokumentaci](https://jakubandrysek.github.io/E-paper-board-ESP32/)