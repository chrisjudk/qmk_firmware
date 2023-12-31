/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,          KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, LT(1,KC_LGUI), KC_LALT,                            KC_SPC,                             KC_RALT, TT(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM,  KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, NK_ON,    NK_OFF,            _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           RCTL(RALT(KC_DEL)),
        RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, KC_PAUS,  QK_BOOT,           KC_SCRL,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,           EE_CLR,            _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_MUTE, KC_VOLD, KC_VOLU, _______,           _______, KC_PGUP,  TG(1),
        _______, _______,  _______,                            _______,                            _______, _______, _______,  KC_HOME, KC_PGDN,  KC_END
    ),


};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

// RGB LED layout

// led number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 9
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 10
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 11
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 12
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 13
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 14
//  87, Side led 07                                                                                                                                                                                                        88, Side led 15
//  91, Side led 08                                                                                                                                                                                                        92, Side led 16
enum LEDS{
    LED_ESC,LED_GRAVE,LED_TAB,LED_CAPS,LED_LSFT,LED_LCTL,LED_F_ONE,LED_ONE,LED_Q,LED_A,LED_Z,LED_LGUI,LED_F_TWO,LED_TWO,LED_W,LED_S,LED_X,LED_LALT,LED_F_THREE,
    LED_THREE,LED_E,LED_D,LED_C,LED_F_FOUR,LED_FOUR,LED_R,LED_F,LED_V,LED_F_FIVE,LED_FIVE,LED_T,LED_G,LED_B,LED_SPC,LED_F_SIX,LED_SIX,LED_Y,LED_H,LED_N,LED_F_SEVEN,
    LED_SEVEN,LED_U,LED_J,LED_M,LED_F_EIGHT,LED_EIGHT,LED_I,LED_K,LED_COMM,LED_RALT,LED_F_NINE,LED_NINE,LED_O,LED_L,LED_DOT,LED_TT_ONE,LED_F_TEN,LED_ZERO,LED_P,LED_SCLN,
    LED_SLSH,LED_F_ELEVEN,LED_MINS,LED_LBRC,LED_QUOT,LED_RCTL,LED_F_TWELVE,LED_LS_ONE,LED_RS_ONE,LED_PSCR,LED_LS_TWO,LED_RS_TWO,LED_BUTTON_ZERO,LED_LS_THREE,LED_RS_THREE,LED_BUTTON_ONE,
    LED_LS_FOUR,LED_RS_FOUR,LED_EQL,LED_RIGHT,LED_LS_FIVE,LED_RS_FIVE,LED_BUTTON_THREE,LED_LS_SIX,LED_RS_SIX,LED_BSPC,LED_BUTTON_TWO,LED_LS_SEVEN,LED_RS_SEVEN,LED_RBRC,LED_RSFT,
    LED_LS_EIGHT, LED_RS_EIGHT,LED_BSLS,LED_UP,LED_LEFT,LED_ENT,LED_DOWN
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
	if (host_keyboard_led_state().caps_lock)
	{
        rgb_matrix_set_color_all(RGB_WHITE);
        uint8_t red[] = {LED_TAB,LED_CAPS,LED_LSFT,LED_RSFT};
        uint8_t black[] = {
            LED_ESC,LED_F_ONE,LED_F_TWO,LED_F_THREE,LED_F_FOUR,LED_F_FIVE,LED_F_SIX,LED_F_SEVEN,LED_F_EIGHT,LED_F_NINE,LED_F_TEN,LED_F_ELEVEN,LED_F_TWELVE,LED_PSCR,
			LED_BUTTON_ZERO,
            LED_BUTTON_ONE,
            LED_BUTTON_TWO,
            LED_UP,LED_BUTTON_THREE,
            LED_LCTL,LED_LGUI,LED_LALT,LED_SPC,LED_RALT,LED_TT_ONE,LED_RCTL,LED_LEFT,LED_DOWN,LED_RIGHT};
		//rgb_matrix_set_color(pin, r, g, b);
		rgb_matrix_set_color(3, 255, 255, 255); //capslock key
		rgb_matrix_set_color(67, 255, 255, 255); //Side LED 01
		rgb_matrix_set_color(70, 255, 255, 255); //Side LED 02
		rgb_matrix_set_color(73, 255, 255, 255); //Side LED 03
		rgb_matrix_set_color(76, 255, 255, 255); //Side LED 04
		rgb_matrix_set_color(80, 255, 255, 255); //Side LED 05
		rgb_matrix_set_color(83, 255, 255, 255); //Side LED 06
		rgb_matrix_set_color(87, 255, 255, 255); //Side LED 07
		rgb_matrix_set_color(91, 255, 255, 255); //Side LED 08
	}
    if (get_highest_layer(layer_state) > 0)
	{
		uint8_t layer = get_highest_layer(layer_state);

		if (layer == 1)
		{
            uint8_t black[] = {
                LED_ESC,
                LED_GRAVE,LED_ONE,LED_TWO,LED_THREE,LED_FOUR,LED_FIVE,LED_SIX,LED_SEVEN,LED_EIGHT,LED_NINE,LED_ZERO,LED_MINS,LED_EQL,LED_BSPC,
                LED_Y,LED_U,LED_I,LED_O,LED_P,LED_LBRC,LED_RBRC,
                LED_CAPS,LED_H,LED_J,LED_K,LED_L,LED_SCLN,LED_QUOT,LED_BUTTON_TWO,
                LED_LSFT,LED_Z,LED_X,LED_C,LED_V,LED_B,LED_M,LED_COMM,LED_DOT,LED_SLSH,LED_RSFT,
                LED_LCTL,LED_LALT,LED_SPC,LED_RALT,LED_RCTL
            };

            uint8_t purple[] = {LED_TAB,LED_Q,LED_W,LED_E,LED_R,LED_T,LED_A,LED_S,LED_D,LED_F,LED_G};

            uint8_t yellow[] ={
                LED_BUTTON_ZERO,
                LED_LGUI,LED_TT_ONE,LED_BUTTON_THREE,
                LED_LS_ONE,LED_LS_TWO,LED_LS_THREE,LED_LS_FOUR,LED_LS_FIVE,LED_LS_SIX,LED_LS_SEVEN,LED_LS_EIGHT,
                LED_RS_ONE,LED_RS_TWO,LED_RS_THREE,LED_RS_FOUR,LED_RS_FIVE,LED_RS_SIX,LED_RS_SEVEN,LED_RS_EIGHT
            };

            uint8_t red[] = {
                LED_BSLS,LED_ENT
            };

            uint8_t springgreen[] ={LED_BUTTON_ONE,LED_RBRC,LED_M,LED_COMM,LED_DOT};

            for (i = 0; i < 46; i++)
                rgb_matrix_set_color(black[i],RGB_BLACK);

            for (i = 0; i < 11; i++)
                rgb_matrix_set_color(purple[i],RGB_PURPLE);

            for (i = 0; i <  20; i++)
                rgb_matrix_set_color(yellow[i],RGB_YELLOW);

            for (i = 0; i < 2; i++)
                rgb_matrix_set_color(red[i],RGB_RED);

            for (i=0; i<1; i++)
                rgb_matrix_set_color(springgreen[i],RGB_SPRINGGREEN);
        }
    }
	return false;
}
