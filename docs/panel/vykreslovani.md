# Vykreslování panelu

O&nbsp;práci s&nbsp;displejem se stará knihovna [GxEPD](https://github.com/ZinggJM/GxEPD), která je obalená mojí třídou `DisplayManager`.

![](../media/panel/ttgo-front.png)

## [GxEPD](https://github.com/ZinggJM/GxEPD)

Univerzální knihovna GxEPD pro práci s&nbsp;mnoha E-paper displeji je založená a&nbsp;velmi rozšířené knihovně [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library).
Tato knihovna zvládá řídit více než 20 různých E-paper displejů s&nbsp;rozlišným počtem barev.
Komunikace mezi knihovnou a&nbsp;displejem probíhá skrze sběrnici SPI.

## [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

Tato univerzální knihovna se využívá jako základ pro většinu dalších knihoven, které pracují s&nbsp;různými displeji.

Knihovně totiž stačí zadefinovat jakým způsobem má vykreslovat jeden bod a&nbsp;čáru (horizontální + vertikální) a&nbsp;s&nbsp;těmito metodami již dokáže vykreslovat všemožné tvary.

## Virtuální displej

Díky univerzálnosti `Adafruit GFX` knihovny je možně testovat vykreslování i&nbsp;na počítači.
Pro otestování jsem využil projekt [Adafruit_GFX_dummy_display](https://github.com/croutor/Adafruit_GFX_dummy_display).

![](../media/panel/virtualni-displej.png)

![](../media/panel/virtualni-ukazka.jpg)