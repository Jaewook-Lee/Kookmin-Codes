#include <ncurses.h>

int main()
{
    initscr();
    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    printw("A Big string which I dind't care to type fully.");
    /* 인자 : (효과 시작 y좌표, 효과 시작 x좌표, 효과 주고자 하는 문자들의 숫자(-1:문장 전체), 효과, init_pair에서 설정한 color 쌍의 인덱스 번호, NULL) */
    mvchgat(0, 0, -1, A_BLINK, 1, NULL);

    refresh();
    getch();
    endwin();

    return 0;
}