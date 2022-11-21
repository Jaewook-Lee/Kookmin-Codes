#include <ncurses.h>
#include <iostream>

int main()
{
    initscr();
    printw("Hello World!\n");
    refresh();
    def_prog_mode(); // Save the tty mode.
    getch();
    endwin();

    char i;
    std::cout << "Let's go to tty mode again!" << std::endl;
    std::cin >> i;

    reset_prog_mode(); // Return previous tty mode.
    refresh(); // restore screen contents

    printw("Another string!\n");
    refresh();
    getch();
    endwin();
    return 0;
}