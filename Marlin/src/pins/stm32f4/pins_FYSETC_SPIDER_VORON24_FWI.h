#pragma once

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "FYSETC SPIDER"
#endif
#ifndef DEFAULT_MACHINE_NAME
  #define DEFAULT_MACHINE_NAME BOARD_INFO_NAME
#endif

//
// EEPROM Emulation
//
#if NO_EEPROM_SELECTED
  #undef NO_EEPROM_SELECTED
  //#define FLASH_EEPROM_EMULATION
  //#define SRAM_EEPROM_EMULATION
  #define I2C_EEPROM
#endif

#if ENABLED(I2C_EEPROM)
  #define MARLIN_EEPROM_SIZE              0x1000  // 4KB
#endif

// Avoid conflict with TIMER_TONE defined in variant
#define STEP_TIMER 10

//
// Endstops
//
/* FWI: Correct Labeling:
#define X_MIN_PIN       PB14
#define X_MAX_PIN       PA1
#define Y_MIN_PIN       PB13
#define Y_MAX_PIN       PA2
#define Z_MIN_PIN       PA0
#define Z_MAX_PIN       PA3
*/ 
// Replaced by: as wiring is different in my build, X/Y Endstops are swapped (connected the X/Y endstops to the MIN connectors instead of the MAX connectors.)
#define X_MIN_PIN       PA1
#define X_MAX_PIN       PB14
#define Y_MIN_PIN       PA2
#define Y_MAX_PIN       PB13
#define Z_MIN_PIN       PA0
#define Z_MAX_PIN       PA3


//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN   PA3
#endif


//
// Steppers
//
#define X_STEP_PIN		PE11
#define X_DIR_PIN		PE10
#define X_ENABLE_PIN	PE9
#define X_CS_PIN	    PE7

#define Y_STEP_PIN		PD8
#define Y_DIR_PIN		PB12
#define Y_ENABLE_PIN	PD9
#define Y_CS_PIN	    PE15

#define Z_STEP_PIN		PD12
#define Z_DIR_PIN		PC4
#define Z_ENABLE_PIN	PE8
#define Z_CS_PIN	    PA15

#define Z2_STEP_PIN		PD14
#define Z2_DIR_PIN		PD13
#define Z2_ENABLE_PIN	PD15
#define Z2_CS_PIN	    PD10

#define Z3_STEP_PIN		PE6
#define Z3_DIR_PIN		PC13
#define Z3_ENABLE_PIN	PE5
#define Z3_CS_PIN	    PC14

#define Z4_STEP_PIN		PE2
#define Z4_DIR_PIN		PE4
#define Z4_ENABLE_PIN	PE3
#define Z4_CS_PIN	    PC15

#define E0_STEP_PIN		PD5
#define E0_DIR_PIN		PD6
#define E0_ENABLE_PIN	PD4
#define E0_CS_PIN	    PD7

#if HAS_TMC_UART
    #define X_SERIAL_TX_PIN PE7
    #define X_SERIAL_RX_PIN X_SERIAL_TX_PIN

    #define Y_SERIAL_TX_PIN PE15
    #define Y_SERIAL_RX_PIN Y_SERIAL_TX_PIN

    #define Z_SERIAL_TX_PIN PA15
    #define Z_SERIAL_RX_PIN Z_SERIAL_TX_PIN

    #define Z2_SERIAL_TX_PIN PD10
    #define Z2_SERIAL_RX_PIN Z2_SERIAL_TX_PIN

    #define Z3_SERIAL_TX_PIN PC14
    #define Z3_SERIAL_RX_PIN Z3_SERIAL_TX_PIN

    #define Z4_SERIAL_TX_PIN PC15
    #define Z4_SERIAL_RX_PIN Z4_SERIAL_TX_PIN

    #define E0_SERIAL_TX_PIN PD7
    #define E0_SERIAL_RX_PIN E0_SERIAL_TX_PIN
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#define TMC_USE_SW_SPI
#if ENABLED(TMC_USE_SW_SPI)
    #ifndef TMC_SW_MOSI
        #define TMC_SW_MOSI     PE14
    #endif
    #ifndef TMC_SW_MISO
        #define TMC_SW_MISO     PE13
    #endif
    #ifndef TMC_SW_SCK
        #define TMC_SW_SCK      PE12
    #endif
#endif

//
// Fans
//
#ifndef FAN_PIN
    #define FAN_PIN     PB1
#endif
#ifndef FAN1_PIN    // Use FAN1 As Exhaust Fan - on E1 heater output (PC8)
    #define FAN1_PIN    PC8
#endif
#ifndef FAN2_PIN
    #define FAN2_PIN    PB0
#endif

// Use FAN2 as Controller Fan.
#ifndef CONTROLLER_FAN_PIN
    #define CONTROLLER_FAN_PIN   PB2
#endif

//
// Heaters
//
#ifndef HEATER_0_PIN
    #define HEATER_0_PIN    PB15
#endif

#ifndef HEATER_BED_PIN
    #define HEATER_BED_PIN  PB4
#endif

//
// Temp Probes
//
#define TEMP_0_PIN          PC0
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN      PC3
#endif

//
// Case Light
//
#ifndef CASE_LIGHT_PIN  // use Heater E2 output as caselight pin
    #define CASE_LIGHT_PIN  PB3
#endif

//
// EXP Headers
//
/**
 *         ------                 ------
 *   PC9  |10  9 | PA8      PA6  |10  9 | PA5
 *   PC11 | 8  7 | PD2      PC6  | 8  7 | PA4
 *   PC10   6  5 | PC12     PC7    6  5 | PA7
 *   PD0  | 4  3 | PD1      PB10 | 4  3 | RESET
 *   GND  | 2  1 | 5V       GND  | 2  1 | 5V
 *         ------                 ------
 *          EXP1                   EXP2
 */
#define EXP1_03_PIN     PD1
#define EXP1_04_PIN     PD0
#define EXP1_05_PIN     PC12
#define EXP1_06_PIN     PC10
#define EXP1_07_PIN     PD2
#define EXP1_08_PIN     PC11
#define EXP1_09_PIN     PA8
#define EXP1_10_PIN     PC9

#define EXP2_03_PIN     -1      // RESET
#define EXP2_04_PIN     PB10
#define EXP2_05_PIN     PA7
#define EXP2_06_PIN     PC7
#define EXP2_07_PIN     PA4
#define EXP2_08_PIN     PC6
#define EXP2_09_PIN     PA5
#define EXP2_10_PIN     PA6

//
// SPI / SD Card
//
#define SD_SCK_PIN                   EXP2_09_PIN
#define SD_MISO_PIN                  EXP2_10_PIN
#define SD_MOSI_PIN                  EXP2_05_PIN

#define SDSS                         EXP2_07_PIN
#define SD_DETECT_PIN                EXP2_04_PIN

//
// LCD / Controller
//
#if ENABLED(FYSETC_242_OLED_12864)

  #define BTN_EN1                    EXP1_10_PIN
  #define BTN_EN2                    EXP1_03_PIN
  #define BTN_ENC                    EXP1_09_PIN

  #define BEEPER_PIN                 EXP2_08_PIN

  #define LCD_PINS_DC                EXP1_05_PIN
  #define LCD_PINS_RS                EXP2_06_PIN  // LCD_RST
  #define DOGLCD_CS                  EXP1_07_PIN
  #define DOGLCD_MOSI                EXP1_06_PIN
  #define DOGLCD_SCK                 EXP1_08_PIN
  #define DOGLCD_A0                  LCD_PINS_DC
  #define FORCE_SOFT_SPI

  #define KILL_PIN                          -1    // NC
  #define NEOPIXEL_PIN               EXP1_04_PIN

#elif HAS_WIRED_LCD

  #define BEEPER_PIN                 EXP1_10_PIN
  #define BTN_ENC                    EXP1_09_PIN

  #if ENABLED(CR10_STOCKDISPLAY)
    #define LCD_PINS_RS              EXP1_04_PIN

    #define BTN_EN1                  EXP1_08_PIN
    #define BTN_EN2                  EXP1_06_PIN

    #define LCD_PINS_ENABLE          EXP1_03_PIN
    #define LCD_PINS_D4              EXP1_05_PIN

  #else

    #define LCD_PINS_RS              EXP1_07_PIN

    #define BTN_EN1                  EXP2_08_PIN
    #define BTN_EN2                  EXP2_06_PIN

    #define LCD_SDSS                 EXP2_07_PIN

    #define LCD_PINS_ENABLE          EXP1_08_PIN
    #define LCD_PINS_D4              EXP1_06_PIN

    #if ENABLED(FYSETC_MINI_12864)
      // See https://wiki.fysetc.com/Mini12864_Panel
      #define DOGLCD_CS              EXP1_08_PIN
      #define DOGLCD_A0              EXP1_07_PIN
      #if ENABLED(FYSETC_GENERIC_12864_1_1)
        #define LCD_BACKLIGHT_PIN    EXP1_04_PIN
      #endif
      #define LCD_RESET_PIN          EXP1_06_PIN  // Must be high or open for LCD to operate normally.
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN      EXP1_05_PIN
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN      EXP1_04_PIN
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN      EXP1_03_PIN
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN         EXP1_05_PIN
      #endif
    #endif

    #if IS_ULTIPANEL
      #define LCD_PINS_D5            EXP1_05_PIN
      #define LCD_PINS_D6            EXP1_04_PIN
      #define LCD_PINS_D7            EXP1_03_PIN
      #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
        #define BTN_ENC_EN           LCD_PINS_D7  // Detect the presence of the encoder
      #endif
    #endif

  #endif

#endif // HAS_WIRED_LCD

// Alter timing for graphical display
#if IS_U8GLIB_ST7920
  #define BOARD_ST7920_DELAY_1                96
  #define BOARD_ST7920_DELAY_2                48
  #define BOARD_ST7920_DELAY_3               640
#endif

#ifndef RGB_LED_R_PIN
  #define RGB_LED_R_PIN                     PB6
#endif
#ifndef RGB_LED_G_PIN
  #define RGB_LED_G_PIN                     PB5
#endif
#ifndef RGB_LED_B_PIN
  #define RGB_LED_B_PIN                     PB7
#endif
#ifndef RGB_LED_W_PIN
  #define RGB_LED_W_PIN                     -1
#endif
