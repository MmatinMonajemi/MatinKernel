#include "shell.h"
#include "screen.h"
#include "keyboard.h"
#include "string.h"

#define MAX_INPUT 128

void shell_start() {
    clear_screen();
    print("Matin Kernel Shell v0.1\n");
    print("Type 'help' for commands.\n\n");

    char input[MAX_INPUT];
    int index = 0;

    while (1) {
        print("> ");
        index = 0;

        while (1) {
            char c = get_char();
            if (c == '\n') break;
            if (c) {
                input[index++] = c;
                print_char(c, 3, index + 2, 0x0F); // نمایش کاراکتر
            }
        }

        input[index] = '\0';

        if (matin_strcmp(input, "help") == 0) {
            print("\nCommands: help, clear, echo\n");
        } else if (matin_strncmp(input, "echo ", 5) == 0) {
            print("\n");
            print(input + 5);
            print("\n");
        } else if (matin_strcmp(input, "clear") == 0) {
            clear_screen();
        } else {
            print("\nUnknown command.\n");
        }
    }
}
