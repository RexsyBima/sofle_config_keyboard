// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


#define ESC_SFT  MT(MOD_LSFT, KC_ESC)    // Hold for Left Shift, tap for Escape

#define A_LGUI MT(MOD_LGUI,KC_A)
#define R_LALT MT(MOD_LALT,KC_R)
#define S_LSFT MT(MOD_LSFT,KC_S)
#define T_LCTL MT(MOD_LCTL,KC_T)

#define O_LGUI MT(MOD_LGUI,KC_O)
#define I_LALT MT(MOD_LALT,KC_I)
#define E_LSFT MT(MOD_LSFT,KC_E)
#define N_LCTL MT(MOD_LCTL,KC_N)



#define MO_LOWR MO(_LOWER)    // Momentary switch to LOWER layer
#define MO_RAIS MO(_RAISE)    // Momentary switch to RAISE layer
#define MO_AJST MO(_ADJUST)   // Momentary switch to ADJUST layer
#define TG_AJST TG(_ADJUST)   // Switch to ADJUST layer when pressed, deactivate it when repressed
#define SPC_AST LT(_ADJUST, KC_SPC)   // Tap = space, hold = ADJUST layer
#include "oled.c"

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
};
#endif



enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    // _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |`esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | "'   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESCSFT| ALGUI| RLALT| SLSFT|TLCTL |   G  |-------.    ,-------|   M  | NLGUI| ELALT| ILSFT|OLCTL |  =+  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |CW_TOG|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,< | .>   | \|   |  /?  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |TG_AJST|XXXXXXX| KC_LALT |LOWER |/Spcjst/\Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_QUOT,
  ESC_SFT,   A_LGUI,   R_LALT,    S_LSFT,    T_LCTL,    KC_G,       KC_M,    N_LCTL,    E_LSFT,    I_LALT,    O_LGUI,  KC_EQL,
  CW_TOGG,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      KC_CAPS,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_BSLS,  KC_SLSH,
                 TG_AJST,XXXXXXX,KC_LALT,MO_LOWR, SPC_AST,        SC_SENT,  MO_RAIS, KC_BSPC, KC_LBRC, KC_RBRC),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   | F1   | F2   | F3   | F4   | F5   |                    | F6   | F7   | F8   | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |PSCR | WHR  |  [   |  ]   | WHD  |                     |PgDn  |  →   |  @   |  *   |Home  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |XXXXX | INS | WHL  |  (   |  )   | WHU  |-------.    ,-------|WBAK |  ←   |  ↓   |  ↑   |  →   |WFWD  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |XXXXX | DEL |XXXXX |  {   |  }   |XXXXX |-------|    |-------|PgUp |  ←   |XXXXX |XXXXX | End  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |XXXXX |XXXXX |XXXXX |XXXXX | /       /       \      \ |XXXXX |XXXXX | DEL  |XXXXX |
 *            |      |      |      |      |/ Enter /         \Space \|      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_TAB,    KC_PSCR,    MS_WHLR,   KC_LBRC,KC_RBRC,MS_WHLD,                KC_PGDN,KC_RIGHT,S(KC_7),S(KC_8), KC_HOME,  KC_F12,
  XXXXXXX, KC_INS,   MS_WHLL, S(KC_9), S(KC_0), MS_WHLU,                    KC_WBAK, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_WFWD,
  XXXXXXX,  KC_DEL, XXXXXXX,S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX,XXXXXXX, KC_PGUP, KC_LEFT, XXXXXXX, KC_END, KC_BSLS, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_NUM,  KC_P7, KC_P8, KC_P9, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_P4,  KC_P5,  KC_P6, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_Z), KC_P1,   KC_P2,  KC_P3, KC_P0,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |`esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | "'   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESCSFT| ALGUI| RLALT| SLSFT|TLCTL |   G  |-------.    ,-------|   M  | NLGUI| ELALT| ILSFT|OLCTL |  =+  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |CW_TOG|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,< | .>   | \|   |  /?  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |TG_AJST|XXXXXXX| KC_LALT |LOWER |/Spcjst/\Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_QUOT,
  ESC_SFT,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                   KC_M,    N_LCTL,    E_LSFT,    I_LALT,    O_LGUI,  KC_EQL,
  CW_TOGG,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      KC_CAPS,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_BSLS,  KC_SLSH,
                 TG_AJST,XXXXXXX,KC_LALT,MO_LOWR, SPC_AST,        SC_SENT,  MO_RAIS, KC_BSPC, KC_LBRC, KC_RBRC),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

// extern rgblight_config_t rgblight_config;
// void keyboard_post_init_user(void){
//     rgblight_config.hue = 120;
//     rgblight_config.sat = 120;
//     rgblight_config.val = 120;
// }


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_LGUI: // GUI + A
            return TAPPING_TERM + 100;  // Slightly longer for pinky
        case R_LALT: // ALT + R
            return TAPPING_TERM + 100;   // Ring finger
        case O_LGUI: // ALT + R
            return TAPPING_TERM + 100;   // Ring finger
        case I_LALT: // ALT + R
            return TAPPING_TERM + 100;   // Ring finger
        default:
            return TAPPING_TERM;
    }
}
