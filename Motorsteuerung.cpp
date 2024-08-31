#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

const uint LED_PIN = 15;  // Pin für die PWM-Steuerung der LED
const uint wrap_val = 1023; // PWM-Auflösung (10-Bit)

void setup_pwm(uint gpio, uint wrap) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Pin für PWM konfigurieren
    pwm_set_wrap(slice_num, wrap);          // PWM-Periode (Wrap-Wert) setzen
    pwm_set_enabled(slice_num, true);       // PWM-Slice aktivieren
}

void set_pwm_level(uint level) {
    pwm_set_gpio_level(LED_PIN, level);  // PWM-Wert setzen
    printf("PWM-Level: %d%%\n", (level * 100) / wrap_val);
}

int main() {
    stdio_init_all(); // Initialisiere Standard-I/O
    setup_pwm(LED_PIN, wrap_val);  // PWM auf 8-Bit Auflösung konfigurieren (0-255)

    while (true) {
        // Motor auf 100 % PWM
        set_pwm_level(wrap_val); // 100 % PWM
        sleep_ms(3000); // 3 Sekunden warten

        // Motor auf 50 % PWM
        set_pwm_level(wrap_val *0.8); // 80 % PWM
        sleep_ms(3000); // 3 Sekunden warten

        // Motor auf 10 % PWM
        set_pwm_level(wrap_val *0.6); // 69 % PWM
        sleep_ms(3000); // 3 Sekunden warten
    }

    return 0;
}
