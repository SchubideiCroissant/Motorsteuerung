#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdio.h>

const uint LED_PIN = 15; // Pin für die PWM-Steuerung der LED

void setup_pwm(uint gpio, uint wrap) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Pin für PWM konfigurieren
    pwm_set_wrap(slice_num, wrap);          // PWM-Periode (Wrap-Wert) setzen
    pwm_set_enabled(slice_num, true);       // PWM-Slice aktivieren
}

int main() {
    stdio_init_all(); // Initialisiere Standard-I/O

    setup_pwm(LED_PIN, 255);  // PWM auf 8-Bit Auflösung konfigurieren (0-255)

    while (true) {
        // Dimme die LED stufenweise hoch und runter
        for (int level = 0; level <= 255; level++) {
            pwm_set_gpio_level(LED_PIN, level);  // PWM-Wert setzen
            sleep_ms(10);  // Kurze Verzögerung für sanftes Dimmen
        }
        for (int level = 255; level >= 0; level--) {
            pwm_set_gpio_level(LED_PIN, level);  // PWM-Wert setzen
            sleep_ms(10);  // Kurze Verzögerung für sanftes Dimmen
        }
    }

    return 0;
}
