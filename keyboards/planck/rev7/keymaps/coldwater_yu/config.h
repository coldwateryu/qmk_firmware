/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4




// my additional settings
#define FLOW_TAP_TERM 100
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD




// #undef MOUSEKEY_DELAY
// #undef MOUSEKEY_INTERVAL
// #undef MOUSEKEY_WHEEL_DELAY
// #undef MOUSEKEY_MAX_SPEED
// #undef MOUSEKEY_TIME_TO_MAX
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #undef MOUSEKEY_WHEEL_TIME_TO_MAX
// #define MOUSEKEY_DELAY          3
// #define MOUSEKEY_INTERVAL       16
// #define MOUSEKEY_WHEEL_DELAY    30
// #define MOUSEKEY_MAX_SPEED      6
// #define MOUSEKEY_TIME_TO_MAX    64
// #define MOUSEKEY_WHEEL_MAX_SPEED   8
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 64


#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY	5
#define MOUSEKEY_INTERVAL	10
#define MOUSEKEY_MOVE_DELTA	16
#define MOUSEKEY_INITIAL_SPEED	100
#define MOUSEKEY_BASE_SPEED	5000
#define MOUSEKEY_DECELERATED_SPEED	400
#define MOUSEKEY_ACCELERATED_SPEED	3000
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS	16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS	32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS	48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS	8