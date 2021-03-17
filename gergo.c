#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define NAV 1 // nav keys, arrows
#define NUMP 2 // numpad
#define NROW 3 // symbols, nums, and f
#define GAME 4 // less layers, for gaming
 
// ,-------------------------------------------.                         ,-------------------------------------------.
// |  TAB   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
// |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
// |Ctrl/ESC| os(A)|alt(S)|ctl(D)|sh(F) |   G  |  -_  |           |  +=  |   H  | sh(J)|ctl(K)|alt(L)|os(;:)|  ' "   |
// |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
// | LShift(|   Z  |   X  |   C  |   V  |   B  |  [{  |           |  ]}  |   N  |   M  | ,  < | . >  | /  ? | RShift)|
// `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
//                    .----------.   .-------.                                 .------.   .-----.
//                    |    APP   |   |  TT2  |                                 | BKSP |   | DEL |
//                    '----------'   '-------'                                 `------.   '-----'
//                                        ,-------.                      ,-------.
//                                        |  TT2  |                      |  F5   |
//                                 ,------|-------|                      |-------|------.
//                                 | LEFT |  LEFT |                      | LT3(  | LT1( |
//                                 | ALT  | Shift |                      | Enter)|Space)|
//                                 |      |       |                      |       |      |
//                                 `--------------'                      `--------------'

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_gergo(
    KC_TAB,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                      KC_Y, KC_U,        KC_I,        KC_O,        KC_P,           KC_BSLS, 
    CTL_T(KC_ESC),GUI_T(KC_A),ALT_T(KC_S),CTL_T(KC_D),SFT_T(KC_F),KC_G, KC_MINS,                    KC_EQL,  KC_H, RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),KC_QUOT, 
    KC_LSPO,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B, KC_LBRC,TT(NUMP),    KC_F5, KC_RBRC, KC_N, KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSPC, 
                                        KC_APP, TT(NUMP), KC_LALT, KC_LSFT,                                    LT(NROW,KC_ENT), LT(NAV,KC_SPC), KC_BSPC, KC_DEL
    ),
	[NAV] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_HOME,   KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(GAME), KC_TRNS,   KC_TRNS, KC_TRNS, LCTL(KC_S),KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_TRNS, 
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[NUMP] = LAYOUT_gergo(
    KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_TRNS,                                      KC_PEQL, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PPLS, 
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_BSPC, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_PAST, 
    KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS, RESET, KC_TRNS,    KC_TRNS, KC_NLCK, KC_DEL,  KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PENT, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_P0, KC_P0
    ),
	[NROW] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,                                     KC_CIRC,KC_AMPR,     KC_ASTR,     KC_LPRN,     KC_RPRN,     KC_TRNS, 
    KC_TRNS, LGUI_T(KC_1),LALT_T(KC_2),LCTL_T(KC_3),LSFT_T(KC_4),KC_5,  KC_F11,                       KC_VOLU, KC_6,   RSFT_T(KC_7),RCTL_T(KC_8),RALT_T(KC_9),RGUI_T(KC_0),KC_TRNS,
    KC_TRNS, KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5, KC_F12, KC_TRNS,    KC_MPLY, KC_VOLD,KC_F6,  KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT,                                                       KC_TRNS, KC_MUTE, KC_MPRV, KC_MNXT
    ),
	[GAME] = LAYOUT_gergo(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I,    KC_O,  KC_P,    KC_BSLS, 
    KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, TT(NROW),                 KC_EQL, KC_H, KC_J, KC_K,    KC_L,  KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TO(BASE),KC_NO,     KC_NO,KC_RBRC,KC_N, KC_M, KC_COMM, KC_DOT,KC_SLSH, KC_RSFT, 
                KC_LALT, KC_LCTL, KC_SPC, KC_ENT,                       KC_ENT, KC_SPC, KC_BSPC, KC_DEL
    )
};
