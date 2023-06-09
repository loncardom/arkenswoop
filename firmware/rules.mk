# Build Options
#   change yes to no to disable

# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Compile for the Liatris
CONVERT_TO = promicro_rp2040
MCU_LIATRIS = yes
ENCODER_ENABLE = yes

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
SPLIT_KEYBOARD = yes
RGBLIGHT_ENABLE = yes       # Enable underlight
WS2812_DRIVER = vendor      # Use the RP2040's PIO interface

