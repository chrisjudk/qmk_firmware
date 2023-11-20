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
			KC_GRAVE,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   RCTL(RALT(KC_DEL)),
		    RGB_TOG,        RGB_MOD,  RGB_HUI, RGB_SAI,RGB_VAI, RGB_SPI, _______, _______, _______, _______, KC_PSCR,  KC_SCRL, KC_PAUS, QK_BOOT,  KC_PGUP,
			_______,       RGB_RMOD,  RGB_HUD, RGB_SAD,RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,          EE_CLR,   KC_PGDN,
		    _______,       _______,  _______, _______,_______, _______, _______, _______, KC_VOLD, KC_VOLU, _______,  _______,          KC_PGUP,  KC_MUTE,
		    _______,       _______,  OSM(MOD_LALT),                  _______,                   _______,          _______,  KC_HOME,          KC_PGDN,  KC_END),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
	if (host_keyboard_led_state().caps_lock)
	{
		rgb_matrix_set_color_all(RGB_WHITE);
		//left side
		rgb_matrix_set_color(0, 0, 0, 0); //esc
		rgb_matrix_set_color(15, RGB_RED); //tab
		rgb_matrix_set_color(30, RGB_RED); //capslock key
		rgb_matrix_set_color(44, RGB_RED); //left shift
		//bottom
		rgb_matrix_set_color(58, 0, 0, 0); //left control
		rgb_matrix_set_color(59, 0, 0, 0); //GUI
		rgb_matrix_set_color(60, 0, 0, 0); //left alt
		rgb_matrix_set_color(61, 0, 0, 0); //space
		rgb_matrix_set_color(62, 0, 0, 0); //right alt
		rgb_matrix_set_color(63, 0, 0, 0); //right control
		rgb_matrix_set_color(64, 0, 0, 0); //left arrow
		rgb_matrix_set_color(65, 0, 0, 0); //down arrow
		//right side
		rgb_matrix_set_color(66, 0, 0, 0); //right arrow
		rgb_matrix_set_color(57, 0, 0, 0); //end
		rgb_matrix_set_color(43, 0, 0, 0); //page down
		rgb_matrix_set_color(29, 0, 0, 0); //page up
		rgb_matrix_set_color(14, 0, 0, 0); //delete
	}
	if (get_highest_layer(layer_state) > 0)
	{
		uint8_t layer = get_highest_layer(layer_state);

		if (layer == 1)
		{
			rgb_matrix_set_color(58, RGB_YELLOW); //left control
			rgb_matrix_set_color(59, RGB_YELLOW); //GUI
			rgb_matrix_set_color(60,RGB_YELLOW); //left alt
			rgb_matrix_set_color(61, RGB_YELLOW); //space
			rgb_matrix_set_color(62, RGB_YELLOW); //right alt
			rgb_matrix_set_color(63, RGB_YELLOW); //right control
		}
	}
	return false;
}