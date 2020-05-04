# MCU name
MCU = atmega32u4

# LUFA target architecture
ARCH = AVR8

# Processor frequency
F_CPU = 16000000

# Input clock frequency
F_USB = $(F_CPU)

# Interrupt driven control endpoint task
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Bootloader for Pro Micro
BOOTLOADER = caterina

# Build options
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no
MIDI_ENABLE = no
AUDIO_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
RGBLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no
SPLIT_KEYBOARD = yes
