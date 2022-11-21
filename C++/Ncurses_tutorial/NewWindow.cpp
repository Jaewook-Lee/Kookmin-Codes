#include <ncurses.h>

int main()
{
    WINDOW *win1; // 특정 Window 가리키는 pointer

    initscr();
    resize_term(25, 25);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);

    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 1, "Default Window");
    refresh();
    getch();

    /* 새 윈도우 생성, 생성 시 메모리 할당, 인자 : (행 크기, 열 크기, 윈도우 시작 y좌표, 윈도우 시작 x좌표)
       성공하면 새 윈도우 포인터 아니면 NULL 반환 */
    win1 = newwin(20, 20, 3, 3);
    wbkgd(win1, COLOR_PAIR(1)); // 하나의 Attribute로 특정 윈도우 전체에 적용, 성공하면 0 아니면 -1 반환
    wattron(win1, COLOR_PAIR(1)); // 특정 Window에 적용할 Attribute 설정, 성공하면 0 아니면 -1 반환
    mvwprintw(win1, 1, 1, "A new window"); // 특정 윈도우의 특정 위치에서보투 문자열 출력, 성공하면 0 아니면 -1 반환
    wborder(win1, '@', '@', '@', '@', '@', '@', '@', '@'); // 특정 윈도우의 경계선 설정, 성공하면 0 아니면 -1 반환
    wrefresh(win1); // 호출 전까지의 명령들을 특정 윈도우에 업데이트

    getch();
    delwin(win1); // 새 윈도우 생성시 할당된 메모리 해제, 성공하면 0 아니면 -1 반환
    endwin();

    return 0;
}
