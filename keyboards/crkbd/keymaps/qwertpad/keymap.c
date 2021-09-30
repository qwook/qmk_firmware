/* Copyright 2021 konomu 
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
#include "print.h"

/**
 * Get ready for spaghetti!
 * 
 * Yeah yeah yeah, this could have been done using combos and layers and all that stuff.
 * I just didn't like how too high level everything is, and there are some strange edge
 * cases that I wanted to iron out... Also....
 * I was too stubborn to learn how to code properly in QMK... But it works!
 * Sorry :(
 * 
 * TODO List:
 * Modifier keys
 * Symbol layer
 * Number Layer
 */

enum custom_layers {
    _DEFAULT,
    _RIGHT_HAND,
    _BACKSPACE,
    _SYMBOL,
    _NUMBER,
};

#define COMBO_TIME 60

#define BSP_EXT KC_BSPC
#define OSYM KC_BSPC
#define ONUM KC_BSPC
#define OSFT KC_BSPC
#define OGUI KC_BSPC
// #define ATAB KC_BSPC
#define OALT KC_BSPC
#define OCTL KC_BSPC
#define CBSP KC_BSPC

enum keycodes {
    CMB_SPC = SAFE_RANGE,
    LYR_BSP,
    CMB_NUM,
    CMB_SYM,
    ATAB,
    SATAB,
    CTRL_Z,
    CTRL_X,
    CTRL_C,
    CTRL_V,
    CTRL_Y,
    OSM_CTRL,
    OSM_ALT,
    OSM_SHFT,
    OSM_CMD,
    OSM_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ENTER,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LYR_BSP,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CMB_NUM, CMB_SYM, CMB_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
};

const uint16_t layers[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ENTER,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LYR_BSP,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CMB_NUM, CMB_SYM, CMB_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
    [_RIGHT_HAND] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_SLASH,    KC_O,    KC_I,    KC_U,    KC_Y,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_L,    KC_K,    KC_J,    KC_H,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_COMM,    KC_DOT,    KC_P,    KC_M,    KC_N,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
    [_BACKSPACE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX,    SATAB,    KC_UP,    ATAB,    XXXXXXX,    CTRL_Y,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    XXXXXXX,    OSM_FN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    CTRL_Z,    CTRL_X,    CTRL_C,    CTRL_V,    OSM_SHFT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM_CTRL, OSM_ALT, OSM_CMD,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
    [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_PSCR,    KC_AUDIO_VOL_UP,    KC_MEDIA_PLAY_PAUSE,    KC_LBRACKET,    KC_RBRACKET,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_MEDIA_PREV_TRACK,    KC_AUDIO_VOL_DOWN,    KC_MEDIA_NEXT_TRACK,    KC_SCOLON,    KC_QUOTE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_BSLASH,    KC_AUDIO_MUTE,    KC_COMM,    KC_DOT,    KC_SLASH,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
    [_NUMBER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TILDE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_BRMD,    KC_BRMU,    KC_ASTR,    KC_MINUS,    KC_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),
};


uint16_t spacebar_timer;
bool pressed_spacebar;
bool fake_pressed_spacebar;
bool in_spacebar_combo_keymap[MATRIX_ROWS][MATRIX_COLS];
bool was_in_combo_spacebar;

uint16_t symbol_timer;
bool pressed_symbol;
bool fake_pressed_symbol;
bool in_symbol_combo_keymap[MATRIX_ROWS][MATRIX_COLS];
bool was_in_combo_symbol;

uint16_t number_timer;
bool pressed_number;
bool fake_pressed_number;
bool in_number_combo_keymap[MATRIX_ROWS][MATRIX_COLS];
bool was_in_combo_number;

uint16_t combo_timers[MATRIX_ROWS][MATRIX_COLS];
bool pressed_keymap[MATRIX_ROWS][MATRIX_COLS];
bool fake_pressed_keymap[MATRIX_ROWS][MATRIX_COLS];

uint16_t backspace_timer;
bool pressed_backspace;
bool fake_pressed_backspace;
bool in_backspace_combo_keymap[MATRIX_ROWS][MATRIX_COLS];
bool was_in_combo_backspace;
bool backspace_layer_enabled = false;

bool osm_ctrl;
bool osm_alt;
bool osm_shift;
bool osm_command;
bool osm_fn;

enum cosmetics {
    COSMETIC_DEFAULT,
    COSMETIC_RIGHT_HAND,
    COSMETIC_SYMBOL,
    COSMETIC_NUMBER,
};

uint8_t current_cosmetic = COSMETIC_DEFAULT;

bool backspace_keymap[MATRIX_ROWS][MATRIX_COLS];

// This is an esoteric conditional.
// If we turn on modifiers but end up using some key in the backspace layer,
// we want to turn off those modifiers when we exit the backspace layer.
bool turn_off_modifiers_after_background_layer_done;
bool are_we_going_to_hold_the_modifier_keys;

// Used so we can maintain the alt tab menu when holding down backspace layer.
bool alt_tab_on = false;

bool is_modifier_on(void) {
    return osm_ctrl || osm_alt || osm_shift || osm_command || osm_fn;
}

bool modifiers_are_disabled = false;

// Should we continue the spacebar combo?
// This is an experimental feature. If we do a combo and hold the spacebar, let's continue on the combo layer.
bool continue_spacebar_combo = false;
bool continue_number_combo = false;

void disable_modifiers(void) {
    if (osm_ctrl) {
        unregister_code(KC_LCTRL);
    }
    if (osm_alt) {
        unregister_code(KC_LALT);
    }
    if (osm_shift) {
        unregister_code(KC_LSHIFT);
    }
    if (osm_command) {
        unregister_code(KC_LGUI);
    }
    modifiers_are_disabled = true;
}

void reregister_modifiers(void) {
    if (osm_ctrl) {
        register_code(KC_LCTRL);
    }
    if (osm_alt) {
        register_code(KC_LALT);
    }
    if (osm_shift) {
        register_code(KC_LSHIFT);
    }
    if (osm_command) {
        register_code(KC_LGUI);
    }
    modifiers_are_disabled = false;
}

void turn_off_modifiers(void) {
    print("Turned off all modifiers.\n");
    disable_modifiers();
    modifiers_are_disabled = false; // topkek
    osm_ctrl = false;
    osm_alt = false;
    osm_shift = false;
    osm_command = false;
    osm_fn = false;
}

void toggle_modifier(bool *osm_key, uint16_t code) {
        *osm_key = !*osm_key;
        if (osm_key != XXXXXXX) {
            if (*osm_key) {
                register_code(code);
                print("Toggle modifier on.\n");
            } else {
                unregister_code(code);
                print("Toggle modifier off.\n");
            }
        }
        if (!is_modifier_on() && backspace_layer_enabled) {
            turn_off_modifiers_after_background_layer_done = false;
        }
}

void press_special_code(uint16_t code) {
    if (code == ATAB) {
        turn_off_modifiers();
        if (!alt_tab_on) {
            alt_tab_on = true;
            register_code(KC_LALT);
        }
        register_code(KC_TAB);
    } else if (code == SATAB) {
        turn_off_modifiers();
        if (!alt_tab_on) {
            alt_tab_on = true;
            register_code(KC_LALT);
        }
        register_code(KC_LSHIFT);
        register_code(KC_TAB);
    } else if (code == CTRL_Z) {
        turn_off_modifiers();
        register_code(KC_LCTRL);
        register_code(KC_Z);
    } else if (code == CTRL_X) {
        turn_off_modifiers();
        register_code(KC_LCTRL);
        register_code(KC_X);
    } else if (code == CTRL_C) {
        turn_off_modifiers();
        register_code(KC_LCTRL);
        register_code(KC_C);
    } else if (code == CTRL_V) {
        turn_off_modifiers();
        register_code(KC_LCTRL);
        register_code(KC_V);
    } else if (code == CTRL_Y) {
        turn_off_modifiers();
        register_code(KC_LCTRL);
        register_code(KC_Y);
    } else if (code == OSM_CTRL) {
        toggle_modifier(&osm_ctrl, KC_LCTRL);
    } else if (code == OSM_ALT) {
        toggle_modifier(&osm_alt, KC_LALT);
    } else if (code == OSM_SHFT) {
        toggle_modifier(&osm_shift, KC_LSHIFT);
    } else if (code == OSM_CMD) {
        toggle_modifier(&osm_command, KC_LGUI);
    } else if (code == OSM_FN) {
        toggle_modifier(&osm_fn, XXXXXXX);
    } else {
        if (alt_tab_on) {
            alt_tab_on = false;
            unregister_code(KC_LALT);
        }
        // Backspace layer enabled.
        if (is_modifier_on() && backspace_layer_enabled) {
            turn_off_modifiers_after_background_layer_done = true;
        }
        if (osm_fn) {
            if (code == KC_Q) {
                register_code(KC_F1);
            } else if (code == KC_W) {
                register_code(KC_F2);
            } else if (code == KC_E) {
                register_code(KC_F3);
            } else if (code == KC_R) {
                register_code(KC_F4);
            } else if (code == KC_T) {
                register_code(KC_F5);
            } else if (code == KC_A) {
                register_code(KC_F6);
            } else if (code == KC_S) {
                register_code(KC_F7);
            } else if (code == KC_D) {
                register_code(KC_F8);
            } else if (code == KC_F) {
                register_code(KC_F9);
            } else if (code == KC_G) {
                register_code(KC_F10);
            } else if (code == KC_Z) {
                register_code(KC_F11);
            } else if (code == KC_X) {
                register_code(KC_F12);
            }
        } else {
            register_code(code);
        }
    }
}

void release_special_code(uint16_t code) {
    if (code == ATAB) {
        unregister_code(KC_TAB);
    } else if (code == SATAB) {
        unregister_code(KC_TAB);
        unregister_code(KC_LSHIFT);
    } else if (code == CTRL_Z) {
        unregister_code(KC_Z);
        unregister_code(KC_LCTRL);
    } else if (code == CTRL_X) {
        unregister_code(KC_X);
        unregister_code(KC_LCTRL);
    } else if (code == CTRL_C) {
        unregister_code(KC_C);
        unregister_code(KC_LCTRL);
    } else if (code == CTRL_V) {
        unregister_code(KC_V);
        unregister_code(KC_LCTRL);
    } else if (code == CTRL_Y) {
        unregister_code(KC_Y);
        unregister_code(KC_LCTRL);
    } else if (code == OSM_CTRL || code == OSM_ALT || code == OSM_SHFT || code == OSM_CMD || code == OSM_FN) {
        // TBD
    } else {
        if (osm_fn) {
            if (code == KC_Q) {
                unregister_code(KC_F1);
            } else if (code == KC_W) {
                unregister_code(KC_F2);
            } else if (code == KC_E) {
                unregister_code(KC_F3);
            } else if (code == KC_R) {
                unregister_code(KC_F4);
            } else if (code == KC_T) {
                unregister_code(KC_F5);
            } else if (code == KC_A) {
                unregister_code(KC_F6);
            } else if (code == KC_S) {
                unregister_code(KC_F7);
            } else if (code == KC_D) {
                unregister_code(KC_F8);
            } else if (code == KC_F) {
                unregister_code(KC_F9);
            } else if (code == KC_G) {
                unregister_code(KC_F10);
            } else if (code == KC_Z) {
                unregister_code(KC_F11);
            } else if (code == KC_X) {
                unregister_code(KC_F12);
            }
        } else {
            unregister_code(code);
        }
        // if (is_modifier_on() && !backspace_layer_enabled) {
        //     turn_off_modifiers();
        // }
        // If this is not a background layer, then all modifiers are one shot and should turn off.
        if (is_modifier_on() && !backspace_layer_enabled && !are_we_going_to_hold_the_modifier_keys && code != KC_LSHIFT) {
            uprintf("Ahh %d %d\n", code, CMB_NUM);
            print("Why is this being turned off?\n");
            turn_off_modifiers();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t real_keycode = layers[_DEFAULT][record->event.key.row][record->event.key.col];
    if (backspace_layer_enabled || (!record->event.pressed && backspace_keymap[record->event.key.row][record->event.key.col])) {
        if (record->event.pressed) {
            backspace_keymap[record->event.key.row][record->event.key.col] = true;
        } else {
            backspace_keymap[record->event.key.row][record->event.key.col] = false;
        }
        real_keycode = layers[_BACKSPACE][record->event.key.row][record->event.key.col];
        if (real_keycode == XXXXXXX) {
            real_keycode = layers[_DEFAULT][record->event.key.row][record->event.key.col];
        }
        if ((continue_spacebar_combo || pressed_spacebar) && keycode == CMB_SPC) {
            real_keycode = CMB_SPC;
            backspace_keymap[record->event.key.row][record->event.key.col] = false;
        }
        if ((continue_number_combo || pressed_number) && keycode == CMB_NUM) {
            real_keycode = CMB_NUM;
            backspace_keymap[record->event.key.row][record->event.key.col] = false;
        }
    }
    switch (real_keycode) {
        case CMB_SPC:
        {
            pressed_spacebar = record->event.pressed;
            // Disable spacebar combo continuation regardless.
            if (!record->event.pressed) {
                continue_spacebar_combo = false;
            }
            if (record->event.pressed) {
                spacebar_timer = timer_read();
                was_in_combo_spacebar = false;
                fake_pressed_backspace = false;
            }
            // Stop pressing fake spacebar.
            if (!record->event.pressed && fake_pressed_spacebar) {
                fake_pressed_spacebar = false;
                release_special_code(KC_SPACE);
                return false;
            }
            // Unpressed the spacebar within combo time, let's fake a quick spacebar tap.
            if (!record->event.pressed && !was_in_combo_spacebar && !fake_pressed_spacebar) {
                press_special_code(KC_SPACE);
                release_special_code(KC_SPACE);
                spacebar_timer = 0;
                return false;
            }
            return false;
        }
        case CMB_SYM:
        {
            pressed_symbol = record->event.pressed;
            if (record->event.pressed) {
                symbol_timer = timer_read();
                was_in_combo_symbol = false;
                fake_pressed_backspace = false;
            }
            // Stop pressing fake symbol.
            if (!record->event.pressed && fake_pressed_symbol) {
                fake_pressed_symbol = false;
                release_special_code(KC_BSPACE);
                return false;
            }
            // Unpressed the symbol within combo time, let's fake a quick symbol tap.
            if (!record->event.pressed && !was_in_combo_symbol && !fake_pressed_symbol) {
                press_special_code(KC_BSPACE);
                release_special_code(KC_BSPACE);
                symbol_timer = 0;
                return false;
            }
            return false;
        }
        case CMB_NUM:
        {
            if (!record->event.pressed) {
                continue_number_combo = false;
            }
            pressed_number = record->event.pressed;
            if (record->event.pressed) {
                number_timer = timer_read();
                was_in_combo_number = false;
                fake_pressed_backspace = false;
            }
            // Stop pressing fake number.
            if (!record->event.pressed && fake_pressed_number) {
                fake_pressed_number = false;
                // release_special_code(KC_LGUI);
                return false;
            }
            // Unpressed the number within combo time, let's fake a quick number tap.
            if (!record->event.pressed && !was_in_combo_number && !fake_pressed_number) {
                // press_special_code(KC_LGUI);
                // release_special_code(KC_LGUI);
                return false;
            }
            return false;
        }
        case LYR_BSP:
        {
            pressed_backspace = record->event.pressed;
            if (record->event.pressed) {
                if (is_modifier_on()) {
                    are_we_going_to_hold_the_modifier_keys = true;
                    return false;
                }
                backspace_timer = timer_read();
                was_in_combo_backspace = false;
                fake_pressed_backspace = false;
                // Remove the next line if you want to make this a combo. Otherwise this is a normal layer.
                backspace_layer_enabled = true;
                print("Backspace Layer ENABLED\n");
                turn_off_modifiers_after_background_layer_done = false;
            } else {
                backspace_layer_enabled = false;
                print("Backspace Layer DISABLED\n");
                if (is_modifier_on() && are_we_going_to_hold_the_modifier_keys) {
                    are_we_going_to_hold_the_modifier_keys = false;
                    turn_off_modifiers();
                    print("Backspace raised. Turning off the modifiers..\n");
                    return false;
                }
                if (alt_tab_on) {
                    alt_tab_on = false;
                    release_special_code(KC_LALT);
                }
                if (turn_off_modifiers_after_background_layer_done) {
                    print("Why is this being turned off 2?\n");
                    turn_off_modifiers();
                }
            }
            return false;
        }
        // Don't mind this spaghetti...
        // This fixes dangling alt's.
        case ATAB: {
            if (record->event.pressed) {
                press_special_code(ATAB);
            } else {
                release_special_code(ATAB);
            }
            return false;
        }
        case SATAB: {
            if (record->event.pressed) {
                press_special_code(SATAB);
            } else {
                release_special_code(SATAB);
            }
            return false;
        }
        default:
            if (record->event.pressed) {
                // Allows you to hold the backspace as if it were a layer.
                if (backspace_layer_enabled) {
                    in_backspace_combo_keymap[record->event.key.row][record->event.key.col] = true;
                    press_special_code(layers[_BACKSPACE][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Allows you to hold the spacebar as if it were a layer. Allows for continuation of combos if we hold down space.
                // This is added to save your thumb.
                if (continue_spacebar_combo) {
                    in_spacebar_combo_keymap[record->event.key.row][record->event.key.col] = true;
                    press_special_code(layers[_RIGHT_HAND][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Allows you to hold the number as if it were a layer. Allows for continuation of combos if we hold down space.
                // This is added to save your thumb.
                if (continue_number_combo) {
                    in_number_combo_keymap[record->event.key.row][record->event.key.col] = true;
                    press_special_code(layers[_NUMBER][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Store how long it's been since we pressed this button.
                // If this button isn't used in any combo, just press it.
                if (layers[_RIGHT_HAND][record->event.key.row][record->event.key.col] != XXXXXXX ||
                    layers[_SYMBOL][record->event.key.row][record->event.key.col] != XXXXXXX ||
                    layers[_NUMBER][record->event.key.row][record->event.key.col] != XXXXXXX) {
                    combo_timers[record->event.key.row][record->event.key.col] = timer_read();
                } else {
                    press_special_code(layers[_DEFAULT][record->event.key.row][record->event.key.col]);
                    fake_pressed_keymap[record->event.key.row][record->event.key.col] = true;
                    return false;
                }
            } else {
                // Reset button timer.
                combo_timers[record->event.key.row][record->event.key.col] = 0;
                // Unpress any button in spacebar combo
                if (in_spacebar_combo_keymap[record->event.key.row][record->event.key.col]) {
                    in_spacebar_combo_keymap[record->event.key.row][record->event.key.col] = false;
                    release_special_code(layers[_RIGHT_HAND][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Unpress any button in symbol combo.
                if (in_symbol_combo_keymap[record->event.key.row][record->event.key.col]) {
                    in_symbol_combo_keymap[record->event.key.row][record->event.key.col] = false;
                    release_special_code(layers[_SYMBOL][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Unpress any button in number combo.
                if (in_number_combo_keymap[record->event.key.row][record->event.key.col]) {
                    in_number_combo_keymap[record->event.key.row][record->event.key.col] = false;
                    release_special_code(layers[_NUMBER][record->event.key.row][record->event.key.col]);
                    return false;
                }
                // Unpress any button in backspace combo.
                if (in_backspace_combo_keymap[record->event.key.row][record->event.key.col]) {
                    in_backspace_combo_keymap[record->event.key.row][record->event.key.col] = false;
                    release_special_code(layers[_BACKSPACE][record->event.key.row][record->event.key.col]);
                    return false;
                }
            }
            pressed_keymap[record->event.key.row][record->event.key.col] = record->event.pressed;
            // Unpress any regular button.
            if (!record->event.pressed && fake_pressed_keymap[record->event.key.row][record->event.key.col]) {
                fake_pressed_keymap[record->event.key.row][record->event.key.col] = false;
                release_special_code(layers[_DEFAULT][record->event.key.row][record->event.key.col]);
                return false;
            }
            // Unpressed a button within combo time, let's fake a quick button tap.
            if (!record->event.pressed && !fake_pressed_keymap[record->event.key.row][record->event.key.col] && timer_elapsed(spacebar_timer) >= COMBO_TIME) {
                press_special_code(layers[_DEFAULT][record->event.key.row][record->event.key.col]);
                release_special_code(layers[_DEFAULT][record->event.key.row][record->event.key.col]);
                return false;
            }
    }
    return false;  // Process all other keycodes normally
}

void matrix_scan_user(void){
    uint16_t max_combo_timers = 10000;
    bool in_combo_state = false;
    for (uint8_t y = 0; y < MATRIX_ROWS; y++) {
        for (uint8_t x = 0; x < MATRIX_COLS; x++) {
            if (combo_timers[y][x] == 0) {
                continue;
            }
            // Used to see if we should be pressing the spacebar now.
            if (timer_elapsed(combo_timers[y][x]) < max_combo_timers) {
                max_combo_timers = timer_elapsed(combo_timers[y][x]);
            }
            if (in_spacebar_combo_keymap[y][x] || in_symbol_combo_keymap[y][x] || in_backspace_combo_keymap[y][x]) {
                in_combo_state = true;
            }
            // If we've pressed this button for less than 40 units, and the space bar for less than 40 units..
            if (timer_elapsed(combo_timers[y][x]) < COMBO_TIME) {
                bool in_combo = in_spacebar_combo_keymap[y][x] || in_symbol_combo_keymap[y][x] || in_number_combo_keymap[y][x];
                if (timer_elapsed(spacebar_timer) < COMBO_TIME && !in_combo && layers[_RIGHT_HAND] != XXXXXXX) {
                    in_spacebar_combo_keymap[y][x] = true;
                    was_in_combo_spacebar = true;
                    pressed_spacebar = false; // Disable spacebar.
                    press_special_code(layers[_RIGHT_HAND][y][x]);
                    current_cosmetic = COSMETIC_RIGHT_HAND;
                    // combo_timers[y][x] = 0;
                    spacebar_timer = 0;
                    continue_spacebar_combo = true;
                } else if (timer_elapsed(symbol_timer) < COMBO_TIME && !in_combo && layers[_RIGHT_HAND] != XXXXXXX) {
                    in_symbol_combo_keymap[y][x] = true;
                    was_in_combo_symbol = true;
                    pressed_symbol = false; // Disable symbol.
                    press_special_code(layers[_SYMBOL][y][x]);
                    current_cosmetic = COSMETIC_SYMBOL;
                    // combo_timers[y][x] = 0;
                    symbol_timer = 0;
                } else if (timer_elapsed(number_timer) < COMBO_TIME && !in_combo && layers[_NUMBER] != XXXXXXX) {
                    in_number_combo_keymap[y][x] = true;
                    was_in_combo_number = true;
                    pressed_number = false; // Disable number.
                    press_special_code(layers[_NUMBER][y][x]);
                    current_cosmetic = COSMETIC_NUMBER;
                    // combo_timers[y][x] = 0;
                    number_timer = 0;
                    continue_number_combo = true;
                }/* else if (timer_elapsed(backspace_timer) < COMBO_TIME && !in_backspace_combo_keymap[y][x] && layers[_BACKSPACE] != XXXXXXX) {
                    backspace_layer_enabled = true;
                    in_backspace_combo_keymap[y][x] = true;
                    was_in_combo_backspace = true;
                    pressed_backspace = false; // Disable backspace.
                    press_special_code(layers[_BACKSPACE][y][x]);
                }*/
            // If we are not in a combo button state, and we're still pressing this button, and we are pass the point in time where this would be registered as a combo, and we are not already passing a fake button press.
            } else if (!in_spacebar_combo_keymap[y][x] && !in_symbol_combo_keymap[y][x] && !in_number_combo_keymap[y][x] && !in_backspace_combo_keymap[y][x] && pressed_keymap[y][x] && timer_elapsed(combo_timers[y][x]) >= COMBO_TIME && fake_pressed_keymap[y][x] == false) {
                fake_pressed_keymap[y][x] = true;
                press_special_code(layers[_DEFAULT][y][x]);
                current_cosmetic = COSMETIC_DEFAULT;
            }
        }
    }
    // We are still pressing the spacebar, it's been a while since we've pressed a combo button, we're not passing a fake space bar button, and we are currently not in a global combo state.
    if (pressed_spacebar && max_combo_timers >= COMBO_TIME && timer_elapsed(spacebar_timer) >= COMBO_TIME && !fake_pressed_spacebar && !in_combo_state) {
        fake_pressed_spacebar = true;
        press_special_code(KC_SPACE);
    }
    // // We are still pressing the backspace, it's been a while since we've pressed a combo button, we're not passing a fake space bar button, and we are currently not in a global combo state.
    // if (pressed_backspace && max_combo_timers >= COMBO_TIME && timer_elapsed(backspace_timer) >= COMBO_TIME && !fake_pressed_backspace && !in_combo_state) {
    //     fake_pressed_backspace = true;
    //     press_special_code(KC_BSPACE);
    // }
    // We are still pressing the symbol, it's been a while since we've pressed a combo button, we're not passing a fake space bar button, and we are currently not in a global combo state.
    if (pressed_symbol && max_combo_timers > 40 && timer_elapsed(symbol_timer) > 40 && !fake_pressed_symbol && !in_combo_state) {
        fake_pressed_symbol = true;
        press_special_code(KC_BSPACE);
    }
    if (pressed_number && max_combo_timers > 40 && timer_elapsed(number_timer) > 40 && !fake_pressed_number && !in_combo_state) {
        fake_pressed_number = true;
        // press_special_code(KC_LGUI);
    }
    // // Press the backspace if layer hasn't been activated yet.
    // if (!fake_pressed_backspace && backspace_layer_timer != 0 && timer_elapsed(backspace_layer_timer) >= COMBO_TIME && !backspace_layer_enabled && backspace_down) {
    //     fake_pressed_backspace = true;
    //     register_code(KC_BSPACE);
    // }
}

void keyboard_post_init_user(void) {
    debug_enable=true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

int i = 0;
void oled_render_logo(void) {
    // static const char PROGMEM crkbd_logo[] = {
    //     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    //     0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    //     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    //     0};
    // oled_write_P(crkbd_logo, false);
    switch (current_cosmetic) {
        case COSMETIC_DEFAULT:
            oled_write_ln_P(PSTR("(^.^)  "), false);
            break;
        case COSMETIC_RIGHT_HAND:
            oled_write_ln_P(PSTR("(o.o)  "), false);
            break;
        case COSMETIC_SYMBOL:
            i = (i+1) % 500;
            int j = i / 100;
            if (j == 0) {
                oled_write_ln_P(PSTR("($.$)  "), false);
            } else if (j == 1) {
                oled_write_ln_P(PSTR("(*.*)  "), false);
            } else if (j == 2) {
                oled_write_ln_P(PSTR("(&.&)  "), false);
            } else if (j == 3) {
                oled_write_ln_P(PSTR("(!.!)  "), false);
            } else if (j == 4) {
                oled_write_ln_P(PSTR("(?.?)  "), false);
            }
            break;
        case COSMETIC_NUMBER:
            oled_write_ln_P(PSTR("(#.#)  "), false);
            break;
    }
    oled_write_ln_P(PSTR("CTRL"), osm_ctrl);
    oled_write_ln_P(PSTR("ALT"), osm_alt);
    oled_write_ln_P(PSTR("SHFT"), osm_shift);
    oled_write_ln_P(PSTR("CMD"), osm_command);
    oled_write_ln_P(PSTR("    "), true);
    oled_write_ln_P(PSTR("F#"), osm_fn);
    oled_write_ln_P(PSTR("    "), true);
    oled_write_ln_P(PSTR("LYR"), backspace_layer_enabled);
}

void oled_task_user(void) {
    oled_render_logo();
}
