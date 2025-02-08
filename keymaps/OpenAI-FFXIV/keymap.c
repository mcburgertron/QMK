#include QMK_KEYBOARD_H
#include "mousekey.h"

// ─────────────────────────────────────────────────────────────────────────────
// LAYERS
enum layer_names { _BASE = 0, _HOTBAR1, _HOTBAR2, _LAYER3, _LAYER4 };

// ─────────────────────────────────────────────────────────────────────────────
// CUSTOM KEYCODES
enum custom_keycodes { ALT_TAB = SAFE_RANGE, CAM_L, CAM_R };

// ─────────────────────────────────────────────────────────────────────────────
// KEYMAPS
// The Hub16's LAYOUT requires 18 arguments:
//   LAYOUT(k4A, k4B,
//          k0A, k0B, k0C, k0D,
//          k1A, k1B, k1C, k1D,
//          k2A, k2B, k2C, k2D,
//          k3A, k3B, k3C, k3D)
// Here:
//   k4A, k4B   -> encoder button positions (unused = KC_NO)
//   16 more    -> the 4x4 grid
// ─────────────────────────────────────────────────────────────────────────────

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 0: BASE
     *
     * Encoder presses: KC_NO, KC_NO
     *
     * Row 0: [ Q      ,   W    ,   E    ,  CAM_L  ]
     * Row 1: [ A      ,   S    ,   D    ,  CAM_R  ]
     * Row 2: [ MMB    , ALT_TAB,  LCTRL ,  SPACE  ]
     * Row 3: [ MO(1)  , MO(2)  , MO(3)  , MO(4)   ]
     */
    [_BASE] = LAYOUT(KC_NO, KC_NO, // encoder presses

                     KC_Q, KC_W, KC_E, CAM_L, KC_A, KC_S, KC_D, CAM_R, KC_MS_BTN3, ALT_TAB, KC_LCTL, KC_SPC, MO(_HOTBAR1), MO(_HOTBAR2), MO(_LAYER3), MO(_LAYER4)),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 1: HOTBAR1 (1..=)
     */
    [_HOTBAR1] = LAYOUT(KC_NO, KC_NO,

                        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, _______, _______, _______, _______),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 2: HOTBAR2 (Ctrl+1..=)
     */
    [_HOTBAR2] = LAYOUT(KC_NO, KC_NO,

                        LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0), LCTL(KC_MINS), LCTL(KC_EQL), _______, _______, _______, _______),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 3: placeholder
     */
    [_LAYER3] = LAYOUT(KC_NO, KC_NO,

                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 4: placeholder
     */
    [_LAYER4] = LAYOUT(
        // Encoder press positions (unused => KC_NO)
        KC_NO, KC_NO,

        // Row 0
        _______, _______, _______, _______,

        // Row 1
        _______, _______, _______, _______,

        // Row 2
        KC_M, KC_LALT, KC_TAB, LCTL(KC_SPC),

        // Row 3
        _______, _______, _______, _______)};

// ─────────────────────────────────────────────────────────────────────────────
// process_record_user: handle macros & camera turns
// ─────────────────────────────────────────────────────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_TAB);
                unregister_code(KC_LALT);
            }
            return false;

        case CAM_L:
            if (record->event.pressed) {
                // Hold RMB + move mouse left
                mousekey_on(KC_BTN2);
                mousekey_on(KC_MS_LEFT);
                mousekey_send();
            } else {
                mousekey_off(KC_MS_LEFT);
                mousekey_off(KC_BTN2);
                mousekey_send();
            }
            return false;

        case CAM_R:
            if (record->event.pressed) {
                // Hold RMB + move mouse right
                mousekey_on(KC_BTN2);
                mousekey_on(KC_MS_RIGHT);
                mousekey_send();
            } else {
                mousekey_off(KC_MS_RIGHT);
                mousekey_off(KC_BTN2);
                mousekey_send();
            }
            return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────────────────────
// ENCODER UPDATE
// Left encoder => volume, Right encoder => mouse speed
// ─────────────────────────────────────────────────────────────────────────────
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // For example: Left encoder => volume
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Right encoder => emulate scroll wheel
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN); // Scroll down
        } else {
            tap_code(KC_MS_WH_UP); // Scroll up
        }

        // Optional: Provide user feedback (e.g., debug print)
        // uprintf("Mouse max_speed: %u\n", mousekey_config.max_speed);
    }
    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// LAYER-BASED COLOR SWITCHING
// Use rgblight_sethsv_noeeprom() to update LEDs upon layer change.
// ─────────────────────────────────────────────────────────────────────────────
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _BASE:
            rgblight_sethsv_noeeprom(170, 255, 128); // Blue
            break;
        case _HOTBAR1:
            rgblight_sethsv_noeeprom(85, 255, 128); // Green
            break;
        case _HOTBAR2:
            rgblight_sethsv_noeeprom(0, 255, 128); // Red
            break;
        case _LAYER3:
            rgblight_sethsv_noeeprom(200, 255, 128); // Purple
            break;
        case _LAYER4:
            rgblight_sethsv_noeeprom(32, 255, 128); // Orange
            break;
        default:
            rgblight_sethsv_noeeprom(0, 0, 128); // White (fallback)
            break;
    }
    return state;
}

// ─────────────────────────────────────────────────────────────────────────────
// keyboard_post_init_user: set a default color/mode
// ─────────────────────────────────────────────────────────────────────────────
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    // Start in _BASE color:
    rgblight_sethsv_noeeprom(170, 255, 128); // Blue
}
