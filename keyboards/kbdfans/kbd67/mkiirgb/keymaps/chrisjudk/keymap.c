#include QMK_KEYBOARD_H

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( // Base
			QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
			CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL,       KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi_blocker( // FN
			QK_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
		    _______,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL,  KC_PAUS, QK_BOOT,  KC_PGUP,
			CTL_T(KC_CAPS),RGB_SPI,  RGB_SPD, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          EE_CLR,   KC_PGDN,
		    KC_LSFT,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          KC_VOLU,  KC_MUTE,
		    _______,       _______,  _______,                  _______,                   _______,          _______,  KC_MPRV,          KC_VOLD,  KC_MNXT),
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[0] = LAYOUT_65_ansi_blocker( // Base
			KC_ESCAPE,      KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_DEL,
		    KC_TAB,         KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
			KC_CAPS,        KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,        KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL, LT(1,KC_LGUI),  KC_LALT,                KC_SPC,                          KC_RALT,   KC_RCTL,         KC_LEFT,    KC_DOWN,   KC_RIGHT),
		[1] = LAYOUT_65_ansi_blocker( // FN
			KC_GRAVE,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______,   RCTL(RALT(KC_DEL)),
		    RGB_TOG,        RGB_MOD,  RGB_HUI, RGB_SAI,RGB_VAI, RGB_SPI, _______, _______, _______, _______, KC_PSCR,  KC_SCRL, KC_PAUS, QK_BOOT,  _______,
			_______,       RGB_RMOD,  RGB_HUD, RGB_SAD,RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,          EE_CLR,   _______,
		    _______,       _______,  _______, _______,_______, _______, _______, _______, KC_VOLD, KC_VOLU, _______,  _______,          KC_PGUP,  KC_MUTE,
		    _______,       _______,  OSM(MOD_LALT),                  _______,                   _______,          _______,  KC_HOME,          KC_PGDN,  KC_END),
};

enum LEDS{
	LED_ESCAPE,LED_ONE,LED_TWO,LED_THREE,LED_FOUR,LED_FIVE,LED_SIX,LED_SEVEN,LED_EIGHT,LED_NINE,LED_ZERO,LED_MINUS,LED_PLUS,LED_BSPC,LED_DEL,
    LED_TAB,LED_Q,LED_W,LED_E,LED_R,LED_T,LED_Y,LED_U,LED_I,LED_O,LED_P,LED_LBRC,LED_RBRC,LED_BSLS,LED_PGUP,
    LED_CAPS,LED_A,LED_S,LED_D,LED_F,LED_G,LED_H,LED_J,LED_K,LED_L,LED_SCLN,LED_QUOT,LED_ENT,LED_PGDN,
    LED_LSFT,LED_Z,LED_X,LED_C,LED_V,LED_B,LED_N,LED_M,LED_COMM,LED_DOT,LED_SLSH,LED_RSFT,LED_UP,LED_END,
    LED_LCTL,LED_LGUI,LED_LALT,LED_SPC,LED_RALT,LED_RCTL,LED_LEFT,LED_DOWN,LED_RIGHT
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
	uint8_t i = 0;
    if (host_keyboard_led_state().caps_lock)
	{
        rgb_matrix_set_color_all(RGB_WHITE);
        uint8_t red[] = {LED_CAPS,LED_LSFT,LED_RSFT};
		uint8_t black[] = {
            LED_ESCAPE,LED_DEL,
			LED_TAB, LED_PGUP,
            LED_PGDN,
            LED_UP,LED_END,
            LED_LCTL,LED_LGUI,LED_LALT,LED_SPC,LED_RALT,LED_RCTL,LED_LEFT,LED_DOWN,LED_RIGHT};

        for (i = 0; i < 3; i++)
            rgb_matrix_set_color(red[i], RGB_RED);
		for ( i = 0; i < 16; i++)
            rgb_matrix_set_color(black[i], RGB_OFF);
    }
	if (get_highest_layer(layer_state) > 0)
	{
		uint8_t layer = get_highest_layer(layer_state);

		if (layer == 1)
		{
			uint8_t black[] ={
				LED_BSPC,
				LED_Y,LED_U,LED_I,LED_O,LED_PGUP,
				LED_CAPS,LED_H,LED_J,LED_K,LED_L,LED_SCLN,LED_QUOT,LED_PGDN,
				LED_LSFT,LED_Z,LED_X,LED_C,LED_V,LED_B,LED_N,LED_M,LED_SLSH,LED_RSFT,
				LED_LCTL,LED_SPC,LED_RALT,LED_RCTL
            };
            uint8_t purple[] = {LED_TAB,LED_Q,LED_W,LED_E,LED_R,LED_T,LED_A,LED_S,LED_D,LED_F,LED_G};
            uint8_t springgreen[] = {LED_P,LED_LBRC,LED_RBRC,LED_COMM,LED_DOT,LED_END};
            uint8_t yellow[] = {LED_DEL,LED_LGUI,LED_LALT};
            uint8_t red[] = {LED_BSLS,LED_ENT};

            for (i = 0; i < 28; i++)
                rgb_matrix_set_color(black[i],RGB_BLACK);
            for (i = 0; i < 11; i++)
                rgb_matrix_set_color(purple[i],RGB_PURPLE);
            for (i = 0; i < 6; i++)
                rgb_matrix_set_color(springgreen[i],RGB_SPRINGGREEN);
            for (i = 0; i <  3; i++)
                rgb_matrix_set_color(yellow[i],RGB_YELLOW);
            for (i = 0; i < 2; i++)
                rgb_matrix_set_color(red[i],RGB_RED);
		}
	}
	return false;
}
