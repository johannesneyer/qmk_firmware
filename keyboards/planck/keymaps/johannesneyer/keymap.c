#include QMK_KEYBOARD_H

/*
qmk compile -kb planck/ez/glow -km johannesneyer
qmk flash -kb planck/ez/glow -km johannesneyer
 */

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM
};

#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define RAISE_ENT LT(_RAISE, KC_ENT)
#define LOWER_TAB LT(_LOWER, KC_TAB)
#define NUM       MO(_NUM)

#define CTL_SPC   CTL_T(KC_SPC)
#define RALT_LGUI GUI_T(KC_RALT)

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

[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,  KC_Q, KC_W,    KC_E,      KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
/*KC_TAB,  KC_A, KC_S,    KC_D,      KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,*/
  KC_TAB, HOME_A,HOME_S,  HOME_D,    HOME_F,    KC_G,    KC_H,    HOME_J,    HOME_K,  HOME_L,  HOME_SCLN,KC_QUOT,
  KC_LSFT, KC_Z, KC_X,    KC_C,      KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, NUM,  KC_LALT, RALT_LGUI, LOWER_TAB, CTL_SPC, CTL_SPC, RAISE_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_LBRC, KC_RBRC, KC_EQL,  KC_UNDS, KC_QUOT, KC_DQUO, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, KC_TILD, KC_GRV,  XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,  _______
),

[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, KC_BSLS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  NK_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  KC_BTN2, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_MPLY, KC_MNXT, _______, KC_BTN1,
  _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),

[_NUM] = LAYOUT_planck_grid(
  RGB_TOG, RGB_RMOD,RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, _______, KC_P7, KC_P8, KC_P9,   _______,
  _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI, _______, KC_P4, KC_P5, KC_P6,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_P0, KC_PDOT, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
