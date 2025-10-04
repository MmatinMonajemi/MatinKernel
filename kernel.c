#include <stdint.h>

void kernel_main() {
    // آدرس حافظه ویدیویی در حالت متنی
    volatile char* video = (char*)0xB8000;

    const char* message = "Welcome to Matin Kernel!";
    uint8_t color = 0x0F; // سفید روی زمینه مشکی

    for (int i = 0; message[i] != '\0'; i++) {
        video[i * 2] = message[i];     // کاراکتر
        video[i * 2 + 1] = color;      // رنگ
    }

    while (1); // توقف کرنل
}
#include "screen.h"
#include "keyboard.h"

void kernel_main() {
    clear_screen();
    print("Welcome to Matin Kernel!\n");
    init_keyboard();

    while (1) {
        char c = get_char();
        if (c) {
            print_char(c, 1, 0, 0x0F); // نمایش کاراکتر در خط دوم
        }
    }
}
