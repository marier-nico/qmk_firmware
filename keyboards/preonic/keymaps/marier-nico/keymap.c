/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum preonic_layers {
  _QWERTY,
  _QWERTY_LOWER,
  _QWERTY_RAISE,
  _CMKDH,
  _CMKDH_LOWER,
  _CMKDH_RAISE,
  _ADJUST,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_LOWER,
  QWERTY_RAISE,
  CMKDH,
  CMKDH_LOWER,
  CMKDH_RAISE,
};

enum custom_keycodes {
  A_GRAVE = CMKDH_RAISE + 1,  // Cannot be SAFE_RANGE
  E_GRAVE,
  U_GRAVE,

  A_CRCFLX,
  E_CRCFLX,
  I_CRCFLX,
  O_CRCFLX,
  U_CRCFLX,

  C_CEDILLE,

  TERMINAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,           KC_5,    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,           KC_T,    KC_Y,    KC_U,           KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,   KC_A,     KC_S,    KC_D,    KC_F,           KC_G,    KC_H,    KC_J,           KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,           KC_B,    KC_N,    KC_M,           KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTRL, TERMINAL, KC_LALT, KC_LGUI, QWERTY_LOWER,   KC_SPC,  KC_SPC,  QWERTY_RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   ê  |      |      |      |   û  |   î  |   ô  |   ^  |   ¨  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   â  |      |      | Home |  End |   _  |   +  |      |      |   `  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_LOWER] = LAYOUT_preonic_grid(
  _______, _______,  _______, _______,  _______, _______, _______, _______,  _______,  ALGR(KC_LBRACKET), ALGR(KC_RBRACKET), _______,
  _______, _______,  _______, E_CRCFLX, _______, KC_PGUP, KC_PGUP, U_CRCFLX, I_CRCFLX, O_CRCFLX,          KC_LBRACKET,       LSFT(KC_RBRACKET),
  _______, A_CRCFLX, _______, _______,  KC_HOME, KC_END,  KC_UNDS, KC_PLUS,  _______,  _______,           KC_QUOTE,          _______,
  _______, _______,  _______, _______,  _______, KC_PGDN, KC_PGDN, _______,  _______,  _______,           _______,           _______,
  _______, _______,  _______, _______,  _______, _______, _______, _______,  KC_MPRV,  KC_MSTP,           KC_MPLY,           KC_MNXT
),

/* Qwerty Raise
 * ,-----------------------------------------------------------------------------------.
 * |   \  |      |   @  |   £  |   ¢  |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   è  |      |      |      |   ù  |      |   <  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   à  |      |      | Home |  End |   -  |   =  |      |      |   ~  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_RAISE] = LAYOUT_preonic_grid(
  ALGR(KC_GRAVE), _______, ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), _______, _______, _______, _______, ALGR(KC_QUOTE), ALGR(KC_BSLASH), _______,
  _______,        _______, _______,    E_GRAVE,    _______,    KC_PGUP, KC_PGUP, U_GRAVE, _______, KC_BSLASH,      LSFT(KC_BSLASH), _______,
  _______,        A_GRAVE, _______,    _______,    KC_HOME,    KC_END,  KC_MINS, KC_EQL,  _______, _______,        ALGR(KC_SCLN),   _______,
  _______,        _______, _______,    C_CEDILLE,  _______,    KC_PGDN, KC_PGDN, _______, _______, _______,        _______,         _______,
  _______,        _______, _______,    _______,    _______,    _______, _______, _______, KC_MPRV, KC_MSTP,        KC_MPLY,         KC_MNXT
),

/* Colemak Mod-DH
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TERM | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CMKDH] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,          KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,          KC_B,    KC_J,    KC_L,          KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_ESC,  KC_A,     KC_R,    KC_S,    KC_T,          KC_G,    KC_M,    KC_N,          KC_E,    KC_I,    KC_O,    KC_ENT,
  KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_D,          KC_V,    KC_K,    KC_H,          KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, TERMINAL, KC_LALT, KC_LGUI, CMKDH_LOWER,   KC_SPC,  KC_SPC,  CMKDH_RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

 /* Colemak mod-dh Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   û  |      |   ^  |   ¨  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   â  |      |      | Home |  End |   _  |   +  |   ê  |   î  |   ô  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_CMKDH_LOWER] = LAYOUT_preonic_grid(
  _______, _______,  _______, _______, _______, _______, _______, _______, _______,  ALGR(KC_LBRACKET), ALGR(KC_RBRACKET), _______,
  _______, _______,  _______, _______, _______, _______, _______, _______, U_CRCFLX, _______,           KC_LBRACKET,       LSFT(KC_RBRACKET),
  _______, A_CRCFLX, _______, _______, KC_HOME,  KC_END, KC_UNDS, KC_PLUS, E_CRCFLX, I_CRCFLX,          O_CRCFLX,          KC_QUOTE,
  _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,           _______,           _______,
  _______, _______,  _______, _______, _______, _______, _______, _______, KC_MPRV,  KC_MSTP,           KC_MPLY,           KC_MNXT
),

/* Colemak mod-dh Raise
 * ,-----------------------------------------------------------------------------------.
 * |   \  |      |   @  |   £  |   ¢  |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ù  |   <  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   à  |      |      | Home |  End |   -  |   =  |   è  |      |   ~  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_CMKDH_RAISE] = LAYOUT_preonic_grid(
  ALGR(KC_GRAVE), _______, ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), _______, _______, _______, _______, ALGR(KC_QUOTE), ALGR(KC_BSLASH), _______,
  _______,        _______, _______,    _______,    _______,    _______, _______, _______, U_GRAVE, KC_BSLASH,      LSFT(KC_BSLASH), _______,
  _______,        A_GRAVE, _______,    _______,    KC_HOME,    KC_END,  KC_MINS, KC_EQL,  E_GRAVE, _______,        ALGR(KC_SCLN),   _______,
  _______,        _______, _______,    C_CEDILLE,  _______,    _______, _______, _______, _______, _______,        _______,         _______,
  _______,        _______, _______,    _______,    _______,    _______, _______, _______, KC_MPRV, KC_MSTP,        KC_MPLY,         KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |QWERTY| CMKDH|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, QWERTY,  CMKDH,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

// These macros allow the use of accents directly on a layer to avoid
// making triple key combinations.
bool french_accent_macros(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case A_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_QUOTE)"a");
        return false;
      }
    case E_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_QUOTE)"e");
        return false;
      }
    case U_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_QUOTE)"u");
        return false;
      }
    case A_CRCFLX:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET)"a");
        return false;
      }
    case E_CRCFLX:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET)"e");
        return false;
      }
    case I_CRCFLX:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET)"i");
        return false;
      }
    case O_CRCFLX:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET)"o");
        return false;
      }
    case U_CRCFLX:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LBRACKET)"u");
        return false;
      }
    case C_CEDILLE:
      if (record->event.pressed) {
        if (get_mods() & MODS_SHIFT_MASK) {
          del_mods(MODS_SHIFT_MASK);
          SEND_STRING(SS_TAP(X_RBRACKET)SS_LSFT("c"));
        } else {
          SEND_STRING(SS_TAP(X_RBRACKET)"c");
        }
        return false;
      }
  }
  return true;
};

bool misc_macros (uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TERMINAL:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_ENT)));
        return false;
      }
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case QWERTY_LOWER:
          if (record->event.pressed) {
            layer_on(_QWERTY_LOWER);
            update_tri_layer(_QWERTY_LOWER, _QWERTY_RAISE, _ADJUST);
          } else {
            layer_off(_QWERTY_LOWER);
            update_tri_layer(_QWERTY_LOWER, _QWERTY_RAISE, _ADJUST);
          }
          return false;
          break;
        case QWERTY_RAISE:
          if (record->event.pressed) {
            layer_on(_QWERTY_RAISE);
            update_tri_layer(_QWERTY_LOWER, _QWERTY_RAISE, _ADJUST);
          } else {
            layer_off(_QWERTY_RAISE);
            update_tri_layer(_QWERTY_LOWER, _QWERTY_RAISE, _ADJUST);
          }
          return false;
          break;
        case CMKDH:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_CMKDH);
          }
          return false;
          break;
        case CMKDH_LOWER:
          if (record->event.pressed) {
            layer_on(_CMKDH_LOWER);
            update_tri_layer(_CMKDH_LOWER, _CMKDH_RAISE, _ADJUST);
          } else {
            layer_off(_CMKDH_LOWER);
            update_tri_layer(_CMKDH_LOWER, _CMKDH_RAISE, _ADJUST);
          }
          return false;
          break;
        case CMKDH_RAISE:
          if (record->event.pressed) {
            layer_on(_CMKDH_RAISE);
            update_tri_layer(_CMKDH_LOWER, _CMKDH_RAISE, _ADJUST);
          } else {
            layer_off(_CMKDH_RAISE);
            update_tri_layer(_CMKDH_LOWER, _CMKDH_RAISE, _ADJUST);
          }
          return false;
          break;
      }

    // Handle macros for French accents.
    bool accent_result = french_accent_macros(keycode, record);
    // Handle other misc macros.
    bool misc_result = misc_macros(keycode, record);

    if (!accent_result || !misc_result) {
      return false;
    }

    return true;
};

void keyboard_post_init_user(void) {
  rgblight_disable_noeeprom();
}
