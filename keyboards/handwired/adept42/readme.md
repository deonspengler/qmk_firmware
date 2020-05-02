# Adept42

[Adept42](image url to come here)

A compact 42 key ortholinear, column staggered split keyboard. The keyboard layout has been designed to be ergonomic and efficient.

* Keyboard Maintainer: [Deon Spengler](https://github.com/deonspengler)
* Hardware Supported: Arduino Pro Micro

## Pinout

The following pins are used for the switch matrix:
- Rows 1-4: D7, E6, B4, B5
- Columns 1-6: F6, F7, B1, B3, B2, B6

Pin D2 is used for the serial communication between the two halves

## Building firmware
Make example for this keyboard (after setting up your build environment):

    make handwired/adept42:default

Flash firmware to Pro Micro

    make handwired/adept42:default:avrdude

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
