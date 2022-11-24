MOUSEKEY_ENABLE = yes    # Mouse keys
# RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

MCU = RP2040
BOOTLOADER = rp2040
WS2812_DRIVER = vendor
SERIAL_DRIVER  = vendor
EXTRAKEY_ENABLE = yes
WPM_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

CONSOLE_ENABLE = yes
DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

SRC += \
    process_record.c \
	oled/oled_handler.c \
	oled/master/oled_master_handler.c \
	oled/master/indicators_up.c \
	oled/master/indicators_down.c \
	oled/slave/oled_slave_handler.c \
	oled/slave/ocean_dream.c


