#include <ncurses.h>

int main()
{
    initscr(); // nurses 모드 시작, 가장 먼저 호출돼야 함, 기본 크기의 윈도우 생성
    start_color(); // Color 사용 선언, 성공하면 0 아니면 -1 반환
    init_pair(1, COLOR_RED, COLOR_WHITE); // Color Attribute 선언, 인자 : (팔레트 번호, 폰트 색, 폰트 배경 색), 성공하면 0 아니면 -1 반환

    attron(COLOR_PAIR(1)); // Attribute 적용, 성공하면 0 아니면 -1 반환
    printw("Hello World"); // 지정한 문자열 출력, 하지만 실제 출력을 담당하는 곳은 아님, 성공하면 문자열 길이 아니면 -1 반환
    attroff(COLOR_PAIR(1)); // Attribute 적용 해제, 성공하면 0 아니면 -1 반환

    refresh(); // 이 함수 호출 전까지의 작업들을 스크린에 업데이트, 성공하면 0 아니면 -1 반환
    getch(); // 하나의 문자를 입력 받음, 바로 종료되는 것을 막기 위해 사용, 성공하면 문자 값 아니면 -1 반환
    endwin(); // ncurses 모드 종료, 성공하면 0 아니면 -1 반환

    return 0;
}