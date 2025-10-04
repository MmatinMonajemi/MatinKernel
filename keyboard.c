#include "keyboard.h"
#include "screen.h"

#define KEYBOARD_PORT 0x60

// جدول ساده تبدیل کد اسکن به کاراکتر
char scancode_to_char[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,
    '\\','z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ',
    // ادامه جدول...
};

static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile ("inb %1, %0" : "=a"(result) : "d"(port));
    return result;
}

char get_char() {
    uint8_t scancode = inb(KEYBOARD_PORT);
    if (scancode < 128) {
        return scancode_to_char[scancode];
    }
    return 0;
}

void init_keyboard() {
    print("Keyboard initialized.\n");
}
