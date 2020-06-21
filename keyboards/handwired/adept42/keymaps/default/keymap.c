#include "adept42.h"
#include "split_util.h"

#define _QWERTY 0
#define _L1 1
#define _L2 2
#define _L3 3

enum {
    TD_SHIFT_CAPS = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
    /*
     * Tap once for Shift, twice for Caps Lock
     */
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Qwerty
   * Enter = Activates Enter when tapped and Alt + Ctrl when held
   * Space = Activates Space when tapped and Super when held
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | Esc  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   | Bspc |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |  A   |  S   |  D   |  F   |  G   |                    |  H   |  J   |  K   |  L   |  ;   |  '   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |  Z   |  X   |  C   |  V   |  B   |                    |  N   |  M   |  ,   |  .   |  /   |Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter |Layer1|      |Layer2|Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_QWERTY] = LAYOUT( \
     KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
     KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
     TD(TD_SHIFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_SHIFT_CAPS), \
                        KC_LCTL, LCA_T(KC_ENT), MO(_L1),     MO(_L2), LGUI_T(KC_SPC), KC_RALT \
  ),

  /*
   * Layer1
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |  `   |  !   |  @   |  #   |  (   |  )   |                    |  %   |  7   |  8   |  9   |  +   |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  ~   |  ^   |  &   |  $   |  {   |  }   |                    |  =   |  4   |  5   |  6   |  *   |  /   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |  \   |  |   |  _   |  [   |  ]   |                    |  0   |  1   |  2   |  3   |  .   |Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter |L1Held|      | RCtl |Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L1] = LAYOUT( \
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_LPRN, KC_RPRN,             KC_PERC, KC_7, KC_8, KC_9, KC_PPLS, KC_PMNS, \
     KC_TILD, KC_CIRC, KC_AMPR, KC_DLR, KC_LCBR, KC_RCBR,           KC_EQL, KC_4, KC_5, KC_6, KC_PAST, KC_SLSH, \
     KC_TRNS, KC_BSLS, KC_PIPE, KC_UNDS, KC_LBRC, KC_RBRC,          KC_0, KC_1, KC_2, KC_3, KC_PDOT, KC_TRNS, \
                             KC_TRNS, KC_TRNS, KC_TRNS,      KC_RCTL, KC_TRNS, KC_TRNS \
  ),

  /*
   * Layer2
   * AS = Alt + Space
   * CE = Ctrl + Enter
   * SS = Super + Space
   * ACE = Alt + Ctrl + Enter
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |Layer3|  F1  |  F2  |  F3  |  F4  |  CE  |                    |PrtScn| Home |Insert| PgUp |VolUp | Del  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | ACE  |  F5  |  F6  |  F7  |  F8  |  SS  |                    | Left | Down |  Up  |Right |VolDn |Pause |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |  F9  | F10  | F11  | F12  |  AS  |                    |ScrLck| End  |Leader| PgDn |VolMte|Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter | LAlt |      |L2Held|Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L2] = LAYOUT( \
     TG(_L3), KC_F1, KC_F2, KC_F3, KC_F4, LCTL(KC_ENT),             KC_PSCR, KC_HOME, KC_INS, KC_PGUP, KC_VOLU, KC_DEL, \
     LCA(KC_ENT), KC_F5, KC_F6, KC_F7, KC_F8, LGUI(KC_SPC),         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_PAUS, \
     KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, LALT(KC_SPC),          KC_SLCK, KC_END, KC_LEAD, KC_PGDN, KC_MUTE, KC_TRNS, \
                             KC_TRNS, KC_TRNS, KC_LALT,      KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  /*
   * Layer3
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | Esc  |      |  Q   |  W   |  E   |  R   |                    |LedPLN|LedHUI|      |      |      |MCURST|
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |      |  A   |  S   |  D   |  G   |                    |LedBTH|LedSAT|      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                    |LedOFF|LedVAL|      |      |      |TGLYR3|
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             |Shift |Space |      |      |      |      |      |
   *                             `--------------------'      `--------------------'
   */
  [_L3] = LAYOUT( \
     KC_ESC, KC_NO, KC_Q, KC_W, KC_E, KC_R,                         RGB_M_P, RGB_HUI, KC_NO, KC_NO, KC_NO, RESET, \
     KC_TAB, KC_NO, KC_A, KC_S, KC_D, KC_G,                         RGB_M_B, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, \
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      RGB_TOG, RGB_VAI, KC_NO, KC_NO, KC_NO, TG(_L3), \
                             KC_LSFT, KC_SPC, KC_NO,         KC_NO, KC_NO, KC_NO \
  )
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        if (isLeftHand) {
            return OLED_ROTATION_270;
        } else {
            return OLED_ROTATION_90;
        }
    } else {
        if (isLeftHand) {
            return OLED_ROTATION_180;
        }
    }
    return rotation;
}


static void render_logo(void) {
    static const char PROGMEM adept_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f,
        0x0f, 0x0f, 0x00, 0x00, 0xf8, 0xfc, 0xfe, 0xff, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff,
        0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
        0xff, 0xff, 0x00, 0x00, 0xf8, 0xfc, 0xfe, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
        0xef, 0xef, 0xef, 0xef, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x0f,
        0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3f, 0x3c, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x3c,
        0x3c, 0x3c, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3d, 0x3d,
        0x3d, 0x3d, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3c, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3f, 0x3f,
        0x3f, 0x3f, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3c, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x3c,
        0x3c, 0x3c, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
        0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x00,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3c, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(adept_logo, sizeof(adept_logo));
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // led status, (Caps Lock)
        oled_write("\nCAPS:", false);
        uint8_t led_state = host_keyboard_leds();

        if (led_state & (1<<USB_LED_CAPS_LOCK)) {
            oled_write("On\n", false);
        } else {
            oled_write("Off\n", false);
        }

        // show layer information
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write("\n\nLEFT:Alpha", false);
                oled_write("\n\nRGHT:Alpha", false);
                break;
            case _L1:
                oled_write("\n\nLEFT:Symbl", false);
                oled_write("\n\nRGHT:Numbr", false);
                break;
            case _L2:
                oled_write("\n\nLEFT:FKeys", false);
                oled_write("\n\nRGHT:Nav\n", false);
                break;
            case _L3:
                oled_write("\n\nLEFT:Game\n", false);
                oled_write("\n\nRGHT:Confg", false);
                break;
            default:
                oled_write("UNDEF", false);
        }

        // show words per minute
        oled_write("\n\nWPM:\n", false);
        char wpm_str[3];
        sprintf(wpm_str, "%03d\n", get_current_wpm());
        oled_write(wpm_str, false);
    } else {
        // render and scroll logo
        render_logo();
        oled_scroll_left();
    }
}
#endif
