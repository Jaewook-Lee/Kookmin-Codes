#include <ncursesw/curses.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "ko_KR.utf-8");
    char key, userName[8];

    initscr();

    /*입력 할 때 키보드의 특수 키 입력도 가능하게 설정(Esc, F1, ...),
      인자 : (Default Window Pointer, 사용 가능 여부), 성공하면 0 아니면 -1 반환*/
    keypad(stdscr, true);
    curs_set(0); // 화면에 보이는 커서 설정, 인자(설정 값(0:사라짐, 1:일반, 2:큰)), 성공하면 인자 아니면 -1 반환
    noecho(); // 문자 입력시 화면에 보이지 않게 설정, 성공하면 0 아니면 -1 반환

    printw("User name: ");
    scanw("%s", userName); // scanf()와 유사, 성공하면 입력된 데이터 수 아니면 -1 반환

    printw("%s\n", userName);
    printw("Enter a key, then window will be cleared");
    refresh();

    getch();
    clear(); // 윈도우의 모든 곳을 빈 칸으로 처리, 성공하면 문자 값 아니면 -1 반환
    printw("Window Cleared");
    refresh();

    getch();
    endwin();

    return 0;
}