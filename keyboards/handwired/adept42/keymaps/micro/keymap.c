#include "adept42.h"
#include "raw_hid.h"
#include "split_util.h"
#include "version.h"

#define _QWERTY 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _L4 4

enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  LT_LEAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Qwerty
   * Enter = Enter when tapped and Alt + Ctrl when held
   * Space = Space when tapped and Super when held
   * Layer2 = Leader key when tapped and layer 2 when held
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
     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                       KC_LCTL, LCA_T(KC_ENT), MO(_L1),      TD(LT_LEAD), LGUI_T(KC_SPC), KC_RALT \
  ),

  /*
   * Layer1
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |  `   |  !   |  @   |  #   |  {   |  }   |                    |  =   |  7   |  8   |  9   |  /   |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  ~   |  ^   |  &   |  $   |  [   |  ]   |                    |  %   |  4   |  5   |  6   |  *   |  +   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  (   |  \   |  |   |  _   |  <   |  >   |                    |  ,   |  1   |  2   |  3   |  .   |  )   |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter |L1Held|      | RCtl |  0   | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L1] = LAYOUT( \
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_LCBR, KC_RCBR,             KC_EQL, KC_7, KC_8, KC_9, KC_SLSH, KC_PMNS, \
     KC_TILD, KC_CIRC, KC_AMPR, KC_DLR, KC_LBRC, KC_RBRC,           KC_PERC, KC_4, KC_5, KC_6, KC_PAST, KC_PPLS, \
     KC_LPRN, KC_BSLS, KC_PIPE, KC_UNDS, KC_LT, KC_GT,              KC_COMM, KC_1, KC_2, KC_3, KC_PDOT, KC_RPRN, \
                             KC_TRNS, KC_TRNS, KC_TRNS,      KC_RCTL, KC_0, KC_TRNS \
  ),

  /*
   * Layer2
   * AS = Alt + Space
   * CE = Ctrl + Enter
   * SS = Super + Space
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  SS  |                    |PrtScn| PgUp |Insert| Home |VolUp | Del  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  AS  |  F5  |  F6  |  F7  |  F8  |  CE  |                    | Left | Down |  Up  |Right |VolDn |Pause |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |  F9  | F10  | F11  | F12  |      |                    |ScrLck| PgD  | Caps | End  |VolMte|Shift |
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             | LCtl |Enter | LAlt |      |L2Held|Space | RAlt |
   *                             `--------------------'      `--------------------'
   */
  [_L2] = LAYOUT( \
     KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, LGUI(KC_SPC),               KC_PSCR, KC_PGUP, KC_INS, KC_HOME, KC_VOLU, KC_DEL, \
     LALT(KC_SPC), KC_F5, KC_F6, KC_F7, KC_F8, LCTL(KC_ENT),        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_PAUS, \
     KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,                 KC_SLCK, KC_PGDN, KC_CAPS, KC_END, KC_MUTE, KC_RSFT, \
                             KC_TRNS, KC_TRNS, KC_LALT,      KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  /*
   * Layer3
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | Esc  |  V   |  Q   |  W   |  E   |  R   |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |Shift |  A   |  S   |  D   |  F   |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  B   | LCtl |  Z   |  X   |  T   | LAlt |                    |      |      |      |      |      |TGLYR3|
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             |  C   |Space |  G   |      |      |      |      |
   *                             `--------------------'      `--------------------'
   */
  [_L3] = LAYOUT( \
     KC_ESC, KC_V, KC_Q, KC_W, KC_E, KC_R,                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
     KC_TAB, KC_LSFT, KC_A, KC_S, KC_D, KC_F,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
     KC_B, KC_LCTL, KC_Z, KC_X, KC_T, KC_LALT,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_L3), \
                                 KC_C, KC_SPC, KC_G,         KC_NO, KC_NO, KC_NO \
  ),

  /*
   * Layer4
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |  F1  |      |      |  Up  |      |      |                    |      |  A   |  S   |  Q   |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Enter |      | Left | Down |Right |      |                    |      |  Z   |  X   |  W   |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |                    |      |      |      |      |      |TGLYR4|
   * `-----------------------------------------|------.      ,------|-----------------------------------------'
   *                             |      |      |      |      |      |      |      |
   *                             `--------------------'      `--------------------'
   */
  [_L4] = LAYOUT( \
     KC_F1, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO,                      KC_NO, KC_A, KC_S, KC_Q, KC_NO, KC_NO, \
     KC_ENT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,               KC_NO, KC_Z, KC_X, KC_W, KC_NO, KC_NO, \
     KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_L4), \
                                   KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO \
  )
};

// advanced tap dance to enable the leader key
typedef struct {
  bool is_press_action;
  uint8_t state;
} tap;

static tap ltld = {
  .is_press_action = true,
  .state = 0
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
      // Key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  } else return 8; // Magic number. At some point this method will expand to work for more presses
}

void layerlead_finished(qk_tap_dance_state_t *state, void *user_data) {
  ltld.state = cur_dance(state);
  switch (ltld.state) {
    case SINGLE_TAP:
      qk_leader_start(); break;
    case SINGLE_HOLD:
      layer_on(2); break;
  }
}

void layerlead_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (ltld.state) {
    case SINGLE_HOLD:
      layer_off(2); break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [LT_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layerlead_finished, layerlead_reset)
};

// leader macro's
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // swith to gaming layer
    SEQ_ONE_KEY(KC_G) {
      layer_on(3);
    }

    // swith to retro arch layer
    SEQ_ONE_KEY(KC_R) {
      layer_on(4);
    }

    // paste text from primary buffer
    SEQ_ONE_KEY(KC_I) {
      register_code(KC_LSFT);
      register_code(KC_INS);
      unregister_code(KC_INS);
      unregister_code(KC_LSFT);
    }

    SEQ_TWO_KEYS(KC_P, KC_W) {
      SEND_STRING("https://www.deonsworld.co.za\n");
    }

    // reset microcontroller
    SEQ_THREE_KEYS(KC_K, KC_B, KC_R) {
      reset_keyboard();
    }

    // display firmware version
    SEQ_THREE_KEYS(KC_K, KC_B, KC_V) {
      SEND_STRING("QMK firmware: v" QMK_VERSION "\nBuilt on: " QMK_BUILDDATE "\nKeyboard: " QMK_KEYBOARD);
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  uint8_t msg[RAW_EPSIZE] = {0};

  sprintf((char *)msg, "LAYER:%u", layer);
  raw_hid_send(msg, RAW_EPSIZE);

  return state;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  //raw_hid_send(data, length);
}
