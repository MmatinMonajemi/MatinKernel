#ifndef MATIN_SCREEN_H
#define MATIN_SCREEN_H

#include <stdint.h>

#define VIDEO_ADDRESS 0xB8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0F

// توابع اصلی
void clear_screen();
void print_char(char c, int row, int col, uint8_t attr);
void print(const char* message);
void print_at(const char* message, int row, int col);
int get_cursor_offset();
void set_cursor_offset(int offset);

#endif
