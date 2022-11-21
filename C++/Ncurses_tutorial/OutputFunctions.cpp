#include <ncurses.h>
#include <cstring>

int main()
{
    char mesg[] = "Just a string.";
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col); // Give number of row and columns in a given window.
    mvprintw(row / 3, (col - strlen(mesg)) / 2, "%s", mesg);
    mvprintw(row - 3, 0, "This screen has %d rows and %d columns.\n", row, col);
    printw("Try resizing your window and then run this program again.");
    
    refresh();
    getch();
    endwin();

    return 0;
}