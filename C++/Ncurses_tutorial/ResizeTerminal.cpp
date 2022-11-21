#include <ncurses.h>
#include <iostream>

int main()
{
    int row, col;
    std::cin >> row >> col;

    initscr();
    resize_term(row, col); // Terminal 크기, Windows 크기 조정, 인자 : (줄, 칸), 성공하면 0 아니면 -1 반환
    mvprintw(3, 4, "C++ programming with ncurses");
    // 윈도우의 (y, x) 위치부터 지정된 문자열 출력, 인자 : (y값, x값, 문자열), 성공하면 문자열 길이 아니면 -1 반환

    refresh();
    getch();
    endwin();

    return 0;
}
