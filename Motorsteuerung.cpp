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
    uint wrap_val = 4095;
    setup_pwm(LED_PIN, wrap_val);  // PWM auf 8-Bit Auflösung konfigurieren (0-255)

    while (true) {
        // Dimme die LED stufenweise hoch und runter
        for (int level = 0; level <= wrap_val; level++) {
            pwm_set_gpio_level(LED_PIN, level);  // PWM-Wert setzen
            sleep_ms(2);  // Kurze Verzögerung für sanftes Dimmen
            if (level % (wrap_val / 5) == 0) { // wrap_val / 5 entspricht 20% des maximalen Wertes
                printf("PWM-Level: %d%%\n", (level * 100) / wrap_val);
            }
        
        }
        for (int level = wrap_val; level >= 0; level--) {
            pwm_set_gpio_level(LED_PIN, level);  // PWM-Wert setzen
            sleep_ms(2);  // Kurze Verzögerung für sanftes Dimmen
            if (level % (wrap_val / 5) == 0) {
                printf("PWM-Level: %d%%\n", (level * 100) / wrap_val);
            }
        }
    }

    return 0;
}
