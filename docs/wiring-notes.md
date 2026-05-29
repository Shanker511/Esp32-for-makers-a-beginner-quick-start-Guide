# Wiring Notes

## Common pins used in the book

| Function | GPIO |
|---|---:|
| LED | GPIO 2 |
| Button | GPIO 4 |
| DHT11 Data | GPIO 18 |
| I2C SDA | GPIO 21 |
| I2C SCL | GPIO 22 |

## Button wiring

Use `INPUT_PULLUP`.

The button should connect the GPIO pin to ground when pressed.

- Not pressed = HIGH
- Pressed = LOW

## LED wiring

Use a resistor.

Typical resistor value:

- 220 ohm
- 330 ohm

Do not connect an LED directly to a GPIO pin without a resistor.

## DHT11 wiring

Typical pins:

- VCC to 3.3V
- GND to GND
- DATA to GPIO 18

Check your specific DHT11 module.
