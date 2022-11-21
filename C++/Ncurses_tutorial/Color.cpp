#include <ncurses.h>
#include <cstring>
#include <iostream>
using namespace std;

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
int main()
{
    initscr();
    char mseg[80] = "Viola !!! In color ...";
    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal doesn't support color\n");
        exit(1);
    }
    
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    print_in_middle(stdscr, LINES / 2, 0, 0, mseg);
    attroff(COLOR_PAIR(1));
    getch();
    endwin();

    return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
    int length, x, y;
    float temp;

    if (win == NULL) win = stdscr;

    getyx(win, y, x);
    if (startx != 0) x = startx;
    if (starty != 0) y = starty;
    if (width == 0) width = 80;

    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int)temp;
    mvwprintw(win, y, x, "%s", string);
    refresh();
}