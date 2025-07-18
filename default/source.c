#include QMK_KEYBOARD_H

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_Q, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_W,
    CKC_E,
    CKC_R,
    CKC_U,
    CKC_I,
    CKC_O,
    CKC_P,
    CKC_1,
    CKC_2,
    CKC_3,
    CKC_4,
    CKC_7,
    CKC_8,
    CKC_9,
    CKC_0,
    SMTD_KEYCODES_END,
    CAPS_TOGGLE,  // Add this after all SMTD keycodes
};

const uint16_t PROGMEM caps_combo[] = {KC_BSPC, KC_SPC, COMBO_END};  // Both thumb keys

combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_combo, CAPS_TOGGLE)
};

#include "sm_td.h"

// Layer names for clarity
enum layers {
    _BASE = 0,
    _LAYER1 = 1,
    _LAYER2 = 2,
    _LAYER3 = 3
};

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB,     CKC_Q,  CKC_W,  CKC_E,  CKC_R,  KC_T,    LSFT(KC_9),        LSFT(KC_0), KC_Y,   CKC_U,  CKC_I,    CKC_O,  CKC_P,    KC_BSLS,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LCTL(KC_S), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_LBRC,           KC_RBRC,    KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        MO(1),      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            MO(2),  KC_BSPC, ALL_T(KC_ESC),     KC_ENT,     KC_SPC, MO(3)
  ),

  [_LAYER1] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-----------+-----------+---------+---------++--------------+--------------+----------------+---------------+---------------+-------+-------- //
        KC_TRNS,  KC_BRID,  KC_BRIU,KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_NO,   KC_NO,      KC_VOLD,    KC_MUTE,    KC_VOLU,    KC_NO,  KC_NO, KC_NO,
     // -----------+-------+-------+-----------+-----------+---------+---------++--------------+--------------+----------------+---------------+---------------+-------+-------- //
        KC_CAPS,    KC_NO,  KC_NO,  KC_NO,      LCA(KC_F),  KC_NO,    KC_LALT,    KC_RALT,      KC_LEFT,       KC_DOWN,         KC_UP,          KC_RIGHT,       KC_NO,  KC_NO,
     // -----------+-------+-------+-----------+-----------+---------+---------++--------------+--------------+----------------+---------------+---------------+-------+-------- //
        KC_LSFT,    KC_NO,  KC_NO,  LCA(KC_C),  KC_NO,      KC_NO,                              LCA(KC_LEFT),  LCA(KC_DOWN),    LCA(KC_UP),     LCA(KC_RIGHT),  KC_NO,  KC_NO,
     // -----------+-------+-------+-----------+-----------+---------+---------++--------------+--------------+----------------+---------------+---------------+-------+-------- //
                                                KC_LGUI,    KC_TRNS,  KC_SPC,     LCA(KC_ENT),  LCAG(KC_LEFT), LCAG(KC_RIGHT)
  ),

  [_LAYER2] = LAYOUT_split_3x6_3_ex2(
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++-------------+-----------+-----------+-----------+-------+------------- //
      KC_EQL,   CKC_1,       CKC_2,     CKC_3,      CKC_4,      KC_5,       KC_LCTL,    KC_RCTL,    KC_6,       CKC_7,      CKC_8,      CKC_9,  CKC_0, KC_MINS,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++-------------+-----------+-----------+-----------+-------+------------- //
      KC_CAPS,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO, KC_NO,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++-------------+-----------+-----------+-----------+-------+------------- //
      KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO, KC_NO,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++-------------+-----------+-----------+-----------+-------+------------- //
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),

  [_LAYER3] = LAYOUT_split_3x6_3_ex2(
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++---------+-----------+-------+-------+-------+------------- //
      KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++---------+-----------+-------+-------+-------+------------- //
      RGB_TOG,  RGB_HUI,    RGB_SAI,    RGB_VAI,    KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++---------+-----------+-------+-------+-------+------------- //
      RGB_MOD,  RGB_HUD,    RGB_SAD,    RGB_VAD,    KC_NO,      KC_NO,                          KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
   // ---------+-----------+-----------+-----------+-----------+-----------+--------++---------+-----------+-------+-------+-------+------------- //
                                                    QK_BOOT,    QK_MAKE,    KC_SPC,    KC_ENT,  KC_TRNS,    KC_RGUI
  )
};
#else
// Standard layout without extra keys would go here
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Add standard 3x6_3 layout here if needed
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case CAPS_TOGGLE:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
            }
            return false;
    }
    return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_Q, KC_Q, KC_LEFT_ALT)
        SMTD_MT(CKC_1, KC_1, KC_LEFT_ALT)
        SMTD_MT(CKC_W, KC_W, KC_LEFT_SHIFT)
        SMTD_MT(CKC_2, KC_2, KC_LEFT_SHIFT)
        SMTD_MT(CKC_E, KC_E, KC_LEFT_CTRL)
        SMTD_MT(CKC_3, KC_3, KC_LEFT_CTRL)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_GUI)
        SMTD_MT(CKC_4, KC_4, KC_LEFT_GUI)
        SMTD_MT(CKC_P, KC_P, KC_RIGHT_ALT)
        SMTD_MT(CKC_0, KC_0, KC_RIGHT_ALT)
        SMTD_MT(CKC_O, KC_O, KC_RIGHT_SHIFT)
        SMTD_MT(CKC_9, KC_9, KC_RIGHT_SHIFT)
        SMTD_MT(CKC_I, KC_I, KC_RIGHT_CTRL)
        SMTD_MT(CKC_8, KC_8, KC_RIGHT_CTRL)
        SMTD_MT(CKC_U, KC_U, KC_RIGHT_GUI)
        SMTD_MT(CKC_7, KC_7, KC_RIGHT_GUI)
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE]   = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
};
#endif
