/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _COLEMAK, _DVORAK, _LOWER, _RAISE, _PLOVER, _ADJUST, _FUNCTION, _MOUSE };
// enum planck_layers { _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _PLOVER, _ADJUST, _FUNCTION, _MOUSE };

enum planck_keycodes { PLOVER = SAFE_RANGE, BACKLIT, EXT_PLV };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCTION)
#define MOUSE MO(_MOUSE)

// #define QWERTY PDF(_QWERTY)
#define COLEMAK PDF(_COLEMAK)
#define DVORAK PDF(_DVORAK)


// Tap Dance declarations
enum {
    TD_XX_PRV, // nothing / previous track
    TD_PP_NXT, // play / next track
    TD_SL_BSL, // slash / backslash
    TD_C_SCL, // comma/semicolon
    TD_D_CL, // dot/colon
};


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_XX_PRV] = ACTION_TAP_DANCE_DOUBLE(_______, KC_MPRV),
    [TD_PP_NXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
    [TD_SL_BSL] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BACKSLASH),
    [TD_C_SCL]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [TD_D_CL]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_SCLN)),
};


// Layer switching
#define LOWBSP LT(_LOWER, KC_BSPC)
#define RAISENT LT(_RAISE, KC_ENT)
#define MS_ESC LT(_MOUSE, KC_ESC)
#define FN_TAB LT(_FUNCTION, KC_TAB)


// Tap Dance abbreviations
#define TDXXPR TD(TD_XX_PRV)
#define TDPLNX TD(TD_PP_NXT)
#define TDSBSL TD(TD_SL_BSL)
#define TDCOM TD(TD_C_SCL)
#define TDDCL TD(TD_D_CL)


// Modified Alphas
#define CTLA CTL_T(KC_A)
#define CTLO CTL_T(KC_O)
#define GUIR GUI_T(KC_R)
#define GUII GUI_T(KC_I)
#define ALTS ALT_T(KC_S)
#define ALTE ALT_T(KC_E)
#define SFTT SFT_T(KC_T)
#define SFTN SFT_T(KC_N)


// Modifiers on lower layer
#define SFTKC_4 SFT_T(KC_4)
#define ALTKC_5 ALT_T(KC_5)
#define SUPKC_6 GUI_T(KC_6)
#define CTLMIN CTL_T(KC_MINUS)
#define ALTLBRC ALT_T(KC_LBRC)
#define SFTRBRC SFT_T(KC_RBRC)

// shortcuts
#define MEH1 MEH(KC_1)
#define MEH2 MEH(KC_2)
#define MEHD MEH(KC_DOT)
#define PRINT CTL_T(KC_F16)
#define MEHE MEH(KC_E)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
// [_QWERTY] = LAYOUT_planck_grid(
//     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,    KC_W,     KC_F,    KC_P,   KC_B,    TDXXPR,  TDPLNX,  KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT,
    CTLA,    GUIR,     ALTS,    SFTT,   KC_G,    MEH1,    MEH2,    KC_M,   SFTN,    ALTE,    GUII,    CTLO,
    KC_Z,    KC_X,     KC_C,    KC_D,   KC_V,    KC_VOLD, KC_VOLU, KC_K,   KC_H,    TDCOM,   TDDCL,   TDSBSL,
    KC_BRID, MEHD,     MS_ESC,  LOWBSP, KC_LSFT, KC_DEL,  KC_TAB,  KC_SPC, RAISENT, FN_TAB,  MEHE,    KC_BRIU
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_EQL,
    KC_LCTL, KC_LWIN, ALTLBRC, SFTRBRC, _______, _______, _______, _______, SFTKC_4, ALTKC_5, SUPKC_6, CTLMIN,
    _______, _______, _______, PRINT,   _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_SLSH,
    _______, _______, _______, _______, _______, _______, _______,  KC_SPC, KC_0,    _______, KC_DOT,  _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, _______, _______, KC_C,    KC_V,    _______, _______, KC_N,    KC_M,    _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  COLEMAK, DVORAK,  PLOVER,  _______,
    // _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  F7  |  F8  |  F8  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | LWIN | LALT | LSFT |      |      |      |      |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______,   KC_F7,   KC_F8,   KC_F8,  KC_F10,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, _______, _______, _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Mouse layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | WH_U | WH_L | MS_U | WH_R |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | LWIN | LALT | LSFT |      |      |      | WH_D | MS_L | MS_D | MS_R |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | BTN1 | BTN2 |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______
)

};

#ifdef ENCODER_MAP_ENABLE
/* Rotary Encoders
 */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    /* Qwerty
     *    v- (index) Clockwise / Counter Clockwise                        v- (index) Clockwise / Counter Clockwise
     * ,---------------------------------------------------------------------------------------.
     * | (0) Vol-    / Vol+    |   |   |   |   |   |   |   |   |   |   | (4) Vol-    / Vol+    |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (1) KC_MNXT / KC_MPRV |   |   |   |   |   |   |   |   |   |   | (5) KC_MNXT / KC_MPRV |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (2) KC_WBAK / KC_WFWD |   |   |   |   |   |   |   |   |   |   | (6) KC_SPC  / KC_ENT  |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (3) KC_LEFT / KC_RGHT |   |   |   |   |       |   |   |   |   | (7) KC_DOWN / KC_UP   |
     * `---------------------------------------------------------------------------------------'
     */
    // [_QWERTY] = {
    //     // LEFT SIDE (index 0 to 3)
    //     ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
    //     ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
    //     ENCODER_CCW_CW(KC_WBAK, KC_WFWD),
    //     ENCODER_CCW_CW(KC_LEFT, KC_RGHT),
    //     // RIGHT SIDE (index 4 to 7)
    //     ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
    //     ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
    //     ENCODER_CCW_CW(KC_SPC,  KC_ENT),
    //     ENCODER_CCW_CW(KC_DOWN, KC_UP)
    // },

    /* Adjust (Lower + Raise)
     *    v- (index) Clockwise / Counter Clockwise                        v- (index) Clockwise / Counter Clockwise
     * ,---------------------------------------------------------------------------------------.
     * | (0) _______ / _______ |   |   |   |   |   |   |   |   |   |   | (4) _______ / _______ |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (1) _______ / _______ |   |   |   |   |   |   |   |   |   |   | (5) _______ / _______ |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (2) UG_NEXT / UG_PREV |   |   |   |   |   |   |   |   |   |   | (6) SAT- / SAT+       |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (3) UG_VALD / UG_VALU |   |   |   |   |       |   |   |   |   | (7) HUE- / HUE+       |
     * `---------------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        // LEFT SIDE (index 0 to 3)
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(UG_NEXT, UG_PREV),
        ENCODER_CCW_CW(UG_VALD, UG_VALU),
        // RIGHT SIDE (index 4 to 7)
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(UG_SATD,  UG_SATU),
        ENCODER_CCW_CW(UG_HUEU,  UG_HUED)
    }
};
#endif
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool play_encoder_melody(uint8_t index, bool clockwise);

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ENCODER_MAP_ENABLE
    if (IS_ENCODEREVENT(record->event) && record->event.pressed) {
        play_encoder_melody(record->event.key.col, record->event.type == ENCODER_CCW_EVENT);
    }
#endif
    switch (keycode) {
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                eeconfig_read_keymap(&keymap_config);
                keymap_config.nkro = 1;
                eeconfig_update_keymap(&keymap_config);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool play_encoder_melody(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return play_encoder_melody(index, clockwise);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
