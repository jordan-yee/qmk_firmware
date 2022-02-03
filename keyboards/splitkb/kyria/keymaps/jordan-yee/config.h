/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

// Lets you roll mod-tap keys
// NOTE: This is probably what you want if you use Mod/Tap for home row keys,
// but not if you want instantaneous respose from Mod/Tap mod combos.
// #define IGNORE_MOD_TAP_INTERRUPT

// Make Mod/Tap keys use the hold key press if another key is pressed
#define PERMISSIVE_HOLD

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

// Fix clockwise direction of rotary encoder
#define ENCODER_DIRECTION_FLIP

// Limit to 8 layers to save space (could bump to 16 if needed)
#define LAYER_STATE_8BIT

// 16 matches a refresh rate of 60hz and significantly speeds up the cursor
#define MOUSEKEY_INTERVAL 16

#define MOUSEKEY_DELAY 100
