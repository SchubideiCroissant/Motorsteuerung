# Motorsteuerung mit einem MOSFET (IRLZ44N) und einem Raspberry Pi Pico W

## Beschreibung
Dieses Projekt steuert einen einfachen Gleichstrommotor (DC-Motor) mit einer Spannung von 3 bis 6 Volt. Die Steuerung erfolgt mithilfe eines N-Kanal MOSFETs (Typ: IRLZ44N), der durch ein PWM-Signal vom Raspberry Pi Pico W an- und ausgeschaltet wird.

## Komponenten
- **Raspberry Pi Pico W** (Microcontroller)
- **12 V regulierbare externe Spannungsquelle**
- **N-Kanal MOSFET IRLZ44N**
- **3-6V DC-Motor**
- **Pull-Down-Widerstand** (10kΩ) für das Gate des MOSFETs 
- **Vorwiderstand am Gate** (optional, z. B. 100Ω), um die Strombegrenzung zu unterstützen

## Verdrahtungsschema
                +V (3-6V) ----+--------------------+-----------+-----------+-----------+
                               |                    |
                               |                    |
                             [Motor]               ^ Diode
                               |                    |
                               |                    |
                               |                    |
                            ----------------------------
                                            |
                               +----- [Drain] (D)---
                                            |
                                    +-------+-------+
                                    |               |
                                    |               |
                                    |               |
                                    |    [Gate] (G) | -------------------------- GPIO_PIN (z.B. 15)
                                    |               |           |                (Mikrocontroller)
                                    |               |           |                    [µC GND]
                                    |                           |                       |
                                    |                           |                       |
                                    |                           |                       |
                                [Source] (S)             [10k Pulldown]                 |
                                        |                       |                       |
                                        |                       |                       |
               GND (Masse)     ---------------------------------------------------------------               
                                          (gemeinsame Masse)




