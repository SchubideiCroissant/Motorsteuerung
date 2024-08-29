#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_PWM_PIN 15  // Der GPIO-Pin, der für die Motorsteuerung verwendet wird

void setup_pwm(uint gpio , uint wrap) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    gpio_set_function(gpio, GPIO_FUNC_PWM);  // Konfiguriere den Pin für PWM
    pwm_set_wrap(slice_num, wrap);            // Setze den maximalen Zählerwert (PWM Periode)
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);  // Setze den Duty Cycle auf 0%
    pwm_set_enabled(slice_num, true);         // Aktiviere den PWM-Slice
}

int main() {
    uint slice_num = pwm_gpio_to_slice_num(15);
    printf("slice_num");
    setup_pwm(LED_PWM_PIN, 255);
    while(true){
        pwm_set_chan_level(slice_num, PWM_CHAN_B ,255);
        sleep_ms(2000);
        pwm_set_chan_level(slice_num, PWM_CHAN_B ,255/2);
        sleep_ms(2000);
        pwm_set_chan_level(slice_num, PWM_CHAN_B ,255/4);
        sleep_ms(2000);
        
    }
    
  
   

    // Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
    // correct slice and channel for a given GPIO.
}

