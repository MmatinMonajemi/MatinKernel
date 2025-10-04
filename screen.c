#include "screen.h"
#include <stddef.h>

// نوشتن کاراکتر در موقعیت خاص
void print_char(char c, int row, int col, uint8_t attr) {
    volatile char* video = (char*) VIDEO_ADDRESS;
    int offset = (row * MAX_COLS + col) * 2;
    video[offset] = c;
    video[offset + 1] = attr;
}

// نوشتن رشته در موقعیت فعلی
void print(const char* message) {
    int row = 0, col = 0;
    for (size_t i = 0; message[i] != '\0'; i++) {
        print_char(message[i], row, col++, WHITE_ON_BLACK);
        if (col >= MAX_COLS) {
            col = 0;
            row++;
        }
    }
}

// نوشتن رشته در موقعیت خاص
void print_at(const char* message, int row, int col) {
    for (size_t i = 0; message[i] != '\0'; i++) {
        print_char(message[i], row, col++, WHITE_ON_BLACK);
        if (col >= MAX_COLS) {
            col = 0;
            row++;
        }
    }
}

// پاک کردن صفحه
void clear_screen() {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            print_char(' ', row, col, WHITE_ON_BLACK);
        }
    }
}
