#include "config_common.h"

/* USB Device descriptor */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x4201
#define DEVICE_VER      0x0001
#define MANUFACTURER    Deon Spengler
#define PRODUCT         Adept42
#define DESCRIPTION     A 42 key ortholinear, column staggered split keyboard

/* Set polling rate */
#define USB_POLLING_INTERVAL_MS 1

/* Force N-Key RollOver */
#define FORCE_NKRO

/* Key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Key matrix pins */
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

/* Diode direction (COL2ROW or ROW2COL) */
#define DIODE_DIRECTION COL2ROW

/* Configure serial communication for the split keyboard */
#define SOFT_SERIAL_PIN D2

/* Configure pin used for selecting handness */
#define SPLIT_HAND_PIN F5

/* Enable split usb detect for Pro Micro */
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1500
#define NO_USB_STARTUP_CHECK

/* Reduces unintended double presses. Set 0 if debouncing is not needed */
#define DEBOUNCE 2

/* Set the maximum time allowed between taps */
#define TAPPING_TERM 250

/* Configure leader key */
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

/* Allow quick tapping not to trigger modifier hold */
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

/* Releasing key without pressing another will send the original key */
#define RETRO_TAPPING
