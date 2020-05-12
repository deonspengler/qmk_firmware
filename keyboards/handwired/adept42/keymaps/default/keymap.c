#include "adept42.h"

#define _QWERTY 0
#define _L1 1
#define _L2 2

enum {
    TD_SHIFT_CAPS = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Shift, twice for Caps Lock
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
   * |Shift |  \   |  _   |  |   |  [   |  ]   |                    |  0   |  1   |  2   |  3   |  .   |Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter |L1Held|      | RCtl |Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L1] = LAYOUT( \
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_LPRN, KC_RPRN,             KC_PERC, KC_7, KC_8, KC_9, KC_PPLS, KC_PMNS, \
     KC_TILD, KC_CIRC, KC_AMPR, KC_DLR, KC_LCBR, KC_RCBR,           KC_EQL, KC_4, KC_5, KC_6, KC_PAST, KC_SLSH, \
     KC_TRNS, KC_BSLS, KC_UNDS, KC_PIPE, KC_LBRC, KC_RBRC,          KC_0, KC_1, KC_2, KC_3, KC_PDOT, KC_TRNS, \
                             KC_TRNS, KC_TRNS, KC_TRNS,      KC_RCTL, KC_TRNS, KC_TRNS \
  ),

  /*
   * Layer2
   * AS = Alt + Space
   * CE = Ctrl + Enter
   * SS = Super + Space
   * ACE = Alt + Ctrl + Enter
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |Layer3|  F1  |  F2  |  F3  |  F4  |  CE  |                    |PrtScn| Home |  Up  | PgUp |VolUp | Del  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | ACE  |  F5  |  F6  |  F7  |  F8  |  SS  |                    |Insert| Left | Down |Right |VolDn |Pause |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |  F9  | F10  | F11  | F12  |  AS  |                    |ScrLck| End  |Leader| PgDn |VolMte|Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter | LAlt |      |L2Held|Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L2] = LAYOUT( \
     KC_SPC, KC_F1, KC_F2, KC_F3, KC_F4, LCTL(KC_ENT),              KC_PSCR, KC_HOME, KC_UP, KC_PGUP, KC_VOLU, KC_DEL, \
     LCA(KC_ENT), KC_F5, KC_F6, KC_F7, KC_F8, LGUI(KC_SPC),         KC_INS, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_PAUS, \
     KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, LALT(KC_SPC),          KC_SLCK, KC_END, KC_LEAD, KC_PGDN, KC_MUTE, KC_TRNS, \
                             KC_TRNS, KC_TRNS, KC_LALT,      KC_TRNS, KC_TRNS, KC_TRNS \
  )
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    // led status, (Caps Lock)
    uint8_t led_state = host_keyboard_leds();

    if (led_state & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_ln_P(PSTR("\nCPSLK"), true);
    } else {
        oled_write_ln_P(PSTR("\nCPSLK"), false);
    }

    // show layer information
    oled_write_P(PSTR("\nLYR: "), false);

    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(PSTR("ALPHA"), false);
                break;
            case _L1:
                oled_write_ln_P(PSTR("SYM"), false);
                break;
            case _L2:
                oled_write_ln_P(PSTR("FKEYS"), false);
                break;
            default:
                oled_write_ln_P(PSTR("UNDEF"), false);
        }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
