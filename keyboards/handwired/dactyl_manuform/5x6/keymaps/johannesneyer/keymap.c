#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
};

#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define RAISE_ENT LT(_RAISE, KC_ENT)
#define LOWER_TAB LT(_LOWER, KC_TAB)
#define NUM       MO(_NUM)

#define SFT_BSPC  SFT_T(KC_BSPC)
#define CTL_SPC   CTL_T(KC_SPC)
#define CTRL_ESC  CTL_T(KC_ESC)
#define RALT_LGUI GUI_T(KC_RALT)
#define LALT_ESC  ALT_T(KC_ESC)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_SCLN LGUI_T(KC_SCLN)
#define HOME_L LALT_T(KC_L)
#define HOME_K LSFT_T(KC_K)
#define HOME_J LCTL_T(KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,            KC_H,    HOME_J,  HOME_K,  HOME_L, HOME_SCLN,KC_QUOT,
 /* KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
    SC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RCPC,
                      KC_LEFT, KC_RIGHT,                                            KC_DOWN, KC_UP,
                                      LOWER_TAB, CTL_SPC,         SFT_BSPC,RAISE_ENT,
                                        XXXXXXX, RALT_LGUI,       LALT_ESC,XXXXXXX,
                                        XXXXXXX, NUM,             KC_LCTL, XXXXXXX
  ),
  [_LOWER] = LAYOUT_5x6(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_LBRC, KC_RBRC, KC_EQL,  KC_UNDS, KC_QUOT,         KC_DQUO, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_LCBR, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, XXXXXXX,         XXXXXXX, KC_TILD, KC_GRV,  XXXXXXX, XXXXXXX, KC_RCBR,
                      _______, _______,                                             KC_END,  KC_HOME,
                                        _______, _______,         KC_DEL,  _______,
                                        _______, _______,         _______, _______,
                                        _______, QK_BOOT,         _______, _______
  ),
  [_RAISE] = LAYOUT_5x6(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, KC_BSLS,
    KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC,
                      _______, _______,                                             KC_PGDN, KC_PGUP,
                                        _______, KC_INS,          _______, _______,
                                        _______, _______,         _______, _______,
                                        _______, _______,         QK_BOOT, _______
  ),
  [_ADJUST] = LAYOUT_5x6(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          _______, _______, KC_MPLY, KC_MNXT, _______, _______,
                      KC_BTN1, KC_BTN2,                                             KC_VOLD, KC_VOLU,
                                        _______, _______,         _______, _______,
                                        _______, _______,         NK_TOGG, _______,
                                        _______, QK_BOOT,         QK_BOOT, _______
  ),
  [_NUM] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,         _______, KC_7,    KC_8,    KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, KC_4,    KC_5,    KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, KC_0,    _______, _______, _______, _______,
                      _______, _______,                                             _______, _______,
                                        _______, _______,         _______, _______,
                                        _______, _______,         _______, _______,
                                        _______, _______,         _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
