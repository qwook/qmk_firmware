
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        # ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c
FORCE_NKRO = yes
# VPATH  +=  keyboards/gboards/
COMBO_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
SPLIT_KEYBOARD = no
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
