#include <ncurses.h>

int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_YELLOW);
    init_pair(2, COLOR_RED, COLOR_GREEN);

    bkgd('*'); // 하나의 Attribute로 전체 윈도우에 적용.
    attron(COLOR_PAIR(1));
    mvprintw(1, 1, "C++ Programming");
    mvprintw(2, 1, "Computer Science @ Kookmin Univ.");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    border(COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_YELLOW, COLOR_BLACK, COLOR_WHITE);
     // 윈도우 경계선 설정, 인자 : (왼쪽, 오른쪽, 위쪽, 아래쪽, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래)
    attroff(COLOR_PAIR(2));

    refresh();
    getch();
    endwin();

    return 0;
}