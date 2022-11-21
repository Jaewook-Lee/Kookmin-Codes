#include <ncurses.h>

int main()
{
    int ch;

    initscr();
    raw(); // Line buffering disabled.
    keypad(stdscr, TRUE);
    noecho();

    printw("Type any character to see it in bold\n");
    ch = getch();

    if (ch == KEY_F(1)) printw("F1 Key Pressed");
    else
    {
        printw("Pressed key: ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD); // A_BOLD = extra bright or bold
    }

    refresh();
    getch();
    endwin();
    
    return 0;
}