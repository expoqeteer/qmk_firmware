RGB_MATRIX_EFFECT(christmas_lights)

// Define effects inside the RGB_MATRIX_CUSTOM_EFFECT_IMPLS ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
bool christmas_lights(effect_params_t* params) {

	static uint8_t led_group[RGB_MATRIX_LED_COUNT];
	static uint8_t scale = 0;
	static uint16_t base_timer = 0;
	static uint8_t slowdown = 1;
	static uint8_t cycle_count = 0;

	uint8_t count;
	uint8_t i;
	HSV hsv;
	RGB rgb[4];

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

	if ( params->init ) {
		for ( i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
			// Assign each LED randomly to a group
			led_group[i] = random8() % 4;
		}
		// Save the current timer so that the count will
		// always restart start at zero
    	base_timer = g_rgb_timer;
    	cycle_count = 0;
    	slowdown = 1;
    	scale = rgb_matrix_config.speed / 8;
	}

	// Count always starts at zero and wraps at 255
    count = scale16by8(g_rgb_timer - base_timer, scale) % 256;

    // Calculate the brightness of each led group
    // Each led group's brigtness is a sine function
    // Each groups sine functions are 90 degrees out of phase
    for ( i = 0; i < 4; i++ ) {
    	hsv = rgb_matrix_config.hsv;
    	hsv.v = scale8(hsv.v, qsub8(sin8(count+(64*i)), 128) * 2);
    	rgb[i] = hsv_to_rgb(hsv);
	}

    // Set the brightness of the LED based on it's group number
    for ( uint8_t i = led_min; i < led_max; i++ ) {
        RGB_MATRIX_TEST_LED_FLAGS();
    	rgb_matrix_set_color(i, rgb[led_group[i]].r, rgb[led_group[i]].g, rgb[led_group[i]].b);
    }

    if ( rgb_matrix_check_finished_leds(led_max) ) {
    	return true;
    } else {
    	// If we're finished with the LEDs and the count is max,
    	// then recalculate the base timer and the scale.
    	// This ensures that transitions are smooth
    	if ( count == 255 ) {
    		base_timer = g_rgb_timer;
    		cycle_count = (cycle_count + 1) % 3;
    		if ( cycle_count <= 1 ) {
    			// No slowdown for two cycles
    			slowdown = 1;
    		} else {
    			// Slow down the third cycle
    			slowdown = 2;
    		}
    		scale = rgb_matrix_config.speed / (8 * slowdown);
        }
    	return false;
    }
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
