#include QMK_KEYBOARD_H
#include "mousekey.h"

// ─────────────────────────────────────────────────────────────────────────────
// LAYERS
enum layer_names {
    // Game mode layers (unchanged)
    _BASE = 0, //
    _HOTBAR1,  //
    _LAYER2,   //
    _LAYER3,   //
    _HOTBAR2,  //
    // One-handed keyboard mode layers:
    _OH_BASE, // Primary one-hand letters & modifiers
    _OH_SYM,  // Symbols & Numbers (accessed via LT on Alt key)
    _OH_NAV,  // Navigation (toggled by left encoder)
    _OH_MIR,  // Mirror letters (accessed via LT on Space key)
    _OH_EX,   // Extra letters/punctuation (missing letters: R, Z, X, V, plus punctuation)
    _OH_FN,   // Function & Media keys
    // RPGMaker
    _OH_RPG,    // Main
    _OH_RPG_NUM // RPG Numbers
};

// ─────────────────────────────────────────────────────────────────────────────
// CUSTOM KEYCODES
enum custom_keycodes { ALT_TAB = SAFE_RANGE, CAM_L, CAM_R, TOG_ONEHAND };

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
     * LAYER 0: BASE (Game mode – unchanged)
     */
    [_BASE] = LAYOUT(TO(_OH_RPG), TO(_OH_BASE),                           // Encoder presses (unused)
                     KC_Q, KC_W, KC_E, CAM_L,                             // Row0
                     KC_A, KC_S, KC_D, CAM_R,                             // Row1
                     KC_LCTL, KC_M, MT(MOD_LSFT, KC_ESC), KC_SPC,         // Row2
                     MO(_HOTBAR1), MO(_LAYER2), MO(_LAYER3), MO(_HOTBAR2) // Row3
                     ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 1: HOTBAR1 (unchanged)
     */
    [_HOTBAR1] = LAYOUT(KC_NO, KC_NO,                      //
                        KC_1, KC_2, KC_3, KC_4,            //
                        KC_5, KC_6, KC_7, KC_8,            //
                        KC_9, KC_0, KC_MINS, KC_EQL,       //
                        _______, _______, _______, _______ //
                        ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 2: Placeholder (unchanged)
     */
    [_LAYER2] = LAYOUT(QK_BOOTLOADER, KC_NO,                                //
                       LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4),      //
                       LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8),      //
                       LALT(KC_9), LALT(KC_0), LALT(KC_MINS), LALT(KC_EQL), //
                       _______, _______, _______, _______                   //
                       ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 3: Placeholder (unchanged)
     */
    [_LAYER3] = LAYOUT(KC_NO, KC_NO,                                    //
                       LCA(KC_1), LCA(KC_2), LCA(KC_3), LCA(KC_4),      //
                       LCA(KC_5), LCA(KC_6), LCA(KC_7), LCA(KC_8),      //
                       LCA(KC_9), LCA(KC_0), LCA(KC_MINS), LCA(KC_EQL), //
                       _______, _______, _______, _______               //
                       ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 4: HOTBAR2 (unchanged)
     */
    [_HOTBAR2] = LAYOUT(KC_NO, KC_NO,                                        //
                        LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4),      //
                        LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8),      //
                        LCTL(KC_9), LCTL(KC_0), LCTL(KC_MINS), LCTL(KC_EQL), //
                        _______, _______, _______, _______                   //
                        ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 10: One-Handed Base Layer
     * This layer provides the leftmost group of letters (group1) for rows 0–2,
     * and reserves row 3 for modifiers.
     * - Encoder left: TG(_OH_NAV) toggles Navigation.
     * - Encoder right: TO(_BASE) returns to game mode.
     */
    [_OH_BASE] = LAYOUT(TO(_OH_RPG), TO(_BASE), // Encoder buttons
                        /* Row0 (Top row, group1): */ KC_Q, KC_W, KC_E, KC_R,
                        /* Row1 (Home row, group1): */ KC_A, KC_S, KC_D, KC_F,
                        /* Row2 (Bottom row, group1): */ KC_Z, KC_X, KC_C, KC_V,
                        /* Row3 (Modifiers): */ LT(_OH_MIR, KC_BSPC), LT(_OH_NAV, KC_LSFT), LT(_OH_SYM, KC_RSFT), LT(_OH_EX, KC_SPC)),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 11: One-Handed Mirror Layer
     * This layer provides the middle group of letters (group2).
     */
    [_OH_MIR] = LAYOUT(_______, _______, // Encoder buttons (unused here)
                       /* Row0 (Top row, group2): */ KC_T, KC_Y, KC_U, KC_I,
                       /* Row1 (Home row, group2): */ KC_G, KC_H, KC_J, KC_K,
                       /* Row2 (Bottom row, group2): */ KC_B, KC_N, KC_M, KC_COMM,
                       /* Row3: */ _______, _______, _______, _______),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 12: One-Handed Extra Layer
     * This layer fills in the remaining keys to complete each QWERTY row.
     */
    [_OH_EX] = LAYOUT(_______, _______, // Encoder buttons (unused)
                      /* Row0 (Top row, group3): */ KC_O, KC_P, KC_TRNS, KC_TRNS,
                      /* Row1 (Home row, group3): */ KC_L, KC_SCLN, KC_QUOT, KC_TRNS,
                      /* Row2 (Bottom row, group3): */ KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS,
                      /* Row3: */ _______, _______, _______, _______),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 13: Symbols/Numbers Layer
     * Accessed by holding LT(_OH_SYM) on _OH_BASE (if you wish to use it).
     */
    [_OH_SYM] = LAYOUT(_______, _______,                 // Encoder buttons (unused)
                       KC_1, KC_2, KC_3, KC_4,           // Row0
                       KC_5, KC_6, KC_7, KC_8,           // Row1
                       KC_9, KC_0, KC_MINS, KC_EQL,      // Row2
                       KC_LSFT, KC_SCLN, KC_BSLS, KC_SPC // Row3
                       ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 14: Navigation Layer
     * Toggled by the left encoder (TG(_OH_NAV) in _OH_BASE).
     */
    [_OH_NAV] = LAYOUT(_______, _______,                   // Encoder buttons (unused)
                       KC_ESC, KC_HOME, KC_UP, KC_END,     // Row0
                       KC_LBRC, KC_LEFT, KC_DOWN, KC_RGHT, // Row1
                       KC_RBRC, KC_PGUP, KC_PGDN, KC_DEL,  // Row2
                       _______, _______, _______, _______  // Row3 (transparent)
                       ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 15: Function & Media Layer
     * Accessed by holding LT(_OH_FN) on _OH_BASE.
     */
    [_OH_FN] = LAYOUT(_______, _______,                  // Encoder buttons (unused)
                      KC_F1, KC_F2, KC_F3, KC_F4,        // Row0
                      KC_F5, KC_F6, KC_F7, KC_F8,        // Row1
                      KC_F9, KC_F10, KC_F11, KC_F12,     // Row2
                      KC_MPLY, KC_MNXT, KC_MPRV, KC_MUTE // Row3
                      ),                                 //

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 16: RPGMaker.

     */

    [_OH_RPG] = LAYOUT(TO(_BASE), TO(_OH_BASE),                   // Encoder presses (unused)
                       KC_ESC, KC_UP, KC_F4, KC_LSFT,             // Row0
                       KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENTER,      // Row1
                       KC_Z, KC_X, KC_C, KC_V,                    // Row2
                       _______, _______, _______, MO(_OH_RPG_NUM) // Row3
                       ),

    /* ─────────────────────────────────────────────────────────────────────────
     * LAYER 17: RPGMaker numbers.
     */
    [_OH_RPG_NUM] = LAYOUT(KC_NO, KC_NO,                      //
                           KC_1, KC_2, KC_3, KC_4,            //
                           KC_5, KC_6, KC_7, KC_8,            //
                           KC_9, KC_0, KC_MINS, KC_EQL,       //
                           _______, _______, _______, _______ //
                           )

}; //

// ─────────────────────────────────────────────────────────────────────────────
// process_record_user: handle macros & camera turns
// ─────────────────────────────────────────────────────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // 1) Convert "if (keycode == KC_SPC)" to case statements
        // case KC_SPC:
        //    if (record->event.pressed) {
        //        if (get_mods() & MOD_MASK_CTRL) {
        //            tap_code(KC_ENT);
        //            return false; // skip normal Space output
        //        }
        //    }
        //    break; // break out of case

        // 2) Convert "if (keycode == TOG_ONEHAND)" to case statements
        case TOG_ONEHAND:
            if (record->event.pressed) {
                if (!(layer_state & (1UL << 10))) {
                    layer_on(10);
                } else {
                    layer_off(10);
                    layer_off(11);
                    layer_off(12);
                    layer_off(13);
                }
                return false;
            }
            break;
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
            // case _BASE:
            //     rgblight_sethsv_noeeprom(85, 255, 128); // Green
            //     break;
        case _HOTBAR1:
            rgblight_sethsv_noeeprom(85, 255, 128); // Green
            break;
        case _HOTBAR2:
            rgblight_sethsv_noeeprom(0, 255, 128); // Red
            break;
        case _LAYER2:
            rgblight_sethsv_noeeprom(200, 255, 128); // Purple
            break;
        case _LAYER3:
            rgblight_sethsv_noeeprom(32, 255, 128); // Orange
            break;

        // One-Hand Layers (more distinct hues):
        case 10:
            rgblight_sethsv_noeeprom(85, 255, 128); // Green (base)
            break;
        case 11:
            rgblight_sethsv_noeeprom(43, 255, 128); // Yellow (symbols)
            break;
        case 12:
            rgblight_sethsv_noeeprom(128, 255, 128); // Cyan (nav)
            break;
        case 13:
            rgblight_sethsv_noeeprom(234, 255, 128); // Pink (mirror)
            break;

        default:
            rgblight_sethsv_noeeprom(0, 0, 128); // White
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
