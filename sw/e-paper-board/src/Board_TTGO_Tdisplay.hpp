/**
 * @file Board_TTGO_Tdisplay.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Konfigurace TTGO T-display
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#define EPD_MOSI                (23)
#define EPD_MISO                (-1)
#define EPD_SCLK                (18)
#define EPD_CS                  (5)

#define EPD_BUSY                (4)
#define EPD_RSET                (16)
#define EPD_DC                  (17)

#define SDCARD_CS               (13)
#define SDCARD_MOSI             (15)
#define SDCARD_MISO             (2)
#define SDCARD_SCLK             (14)

#define BUTTON_LEFT             (37)
#define BUTTON_MIDDLE           (38)
#define BUTTON_RIGHT            (39)

#define IIS_WS                  (25)
#define IIS_BCK                 (26)
#define IIS_DOUT                (19)

#define ICS43434_WS             (33)
#define ICS43434_BCK            (32)
#define ICS43434_DIN            (27)

#define I2C_SDA                 (21)
#define I2C_SCL                 (22)

#define BUTTONS                 {37,38,39}
#define BUTTON_COUNT            (3)

#define LED_PIN                 (22)
#define LED_ON                  (HIGH)

#define ADC_PIN                 (35)

// #define _HAS_ADC_DETECTED_
// #define _HAS_LED_
// #define _HAS_SPEAKER_
// #define _HAS_SDCARD_
