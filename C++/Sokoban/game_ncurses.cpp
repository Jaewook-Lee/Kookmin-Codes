#include <ncurses.h>
#include "MainDriver.h"
const int WIDTH_SIZE = 60;
const int HEIGHT_SIZE = 40;

void drawMap(WINDOW*, int**, int);
void drawInfo(WINDOW*);
int main()
{
    MainLogic game;

    initscr();

    keypad(stdscr, TRUE); // 키보드 특수 키 입력을 가능하게 한다.

    start_color(); // 색깔 지정할 수 있도록 설정

    resize_term(HEIGHT_SIZE, WIDTH_SIZE); // 전체 창 크기 조정
    border('+', '+', '+', '+', '+', '+', '+', '+');
    mvprintw(2, 26, "Sokoban");

    WINDOW *game_frame, *game_info, *msg_frame;

    game_frame = newwin(20, 20, 6, 6); // 게임 창 생성

    game_info = newwin(12, 20, 6, 34); // 게임 정보 창 생성
    wborder(game_info, '-', '-', '-', '-', '-', '-', '-', '-');

    msg_frame = newwin(10 ,48, 28, 6); // 메세지 창 생성
    wborder(msg_frame, '=', '=', '=', '=', '=', '=', '=', '=');

    while (game.level < 5)
    {   
        drawMap(game_frame, game.current_map, 20); // game_frame에 맵을 그린다.
	    drawInfo(msg_frame);

        wclear(game_info); // game_info창의 내용을 지운다.
        mvwprintw(game_info, 0, 0, "Level: %d", game.level);
        mvwprintw(game_info, 2, 0, "Move: %d", game.step);
        mvwprintw(game_info, 4, 0, "Push: %d", game.Count);

        /* game_frame, game_info, msg_frame 출력 */
        wrefresh(game_frame);
        wrefresh(game_info);
        wrefresh(msg_frame);

        int ch = getch(); // 키 입력을 받는다.
        switch (ch)
        {
        case KEY_UP:
            game.push(KEY_UP, game.current_map);
            break;
        case KEY_DOWN:
            game.push(KEY_DOWN, game.current_map);
            break;
        case KEY_LEFT:
            game.push(KEY_LEFT, game.current_map);
            break;
        case KEY_RIGHT:
            game.push(KEY_RIGHT, game.current_map);
            break;
        }

        /* 매 움직임마다 체크, 클리어 조건을 만족했으면 다음 맵을 보여준다. */
        if (game.clear(game.level, game.current_map))
        {
            game.Count = 0;
            game.step = 0;
            game.current_map = ReturnLevel(++game.level);
        }
    }

    /* ncurses를 종료한다. */
    delwin(game_frame);
    delwin(game_info);
    delwin(msg_frame);
    endwin();
}
void drawMap(WINDOW* area, int** map, int size)
{
    init_pair(1, COLOR_RED, COLOR_RED); // 벽 색깔 지정
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW); // 상자 색깔 지정
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA); // 목적지 색깔 지정
    init_pair(4, COLOR_WHITE, COLOR_WHITE); // 바깥 맵 색깔 지정
    init_pair(5, COLOR_CYAN, COLOR_CYAN); // 캐릭터가 갈 수 있는 길 색깔 지정
    init_pair(6, COLOR_GREEN, COLOR_GREEN); // 캐릭터 색깔 지정

    wbkgd(area, COLOR_PAIR(4)); // game_frame의 배경색 지정
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
		    if (map[j/2][i/2] == 1) 
            {   
                wattron(area, COLOR_PAIR(1));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(1));
            }
		    else if (map[j/2][i/2] == 2)
            {
                wattron(area, COLOR_PAIR(2));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(2));
            }
	        else if (map[j/2][i/2] == 3)
            {
                wattron(area, COLOR_PAIR(3));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(3));
            }
		    else if (map[j/2][i/2] == 4)
            {
                wattron(area, COLOR_PAIR(4));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(4));
            }
		    else if (map[j/2][i/2] == 0)
            {
                wattron(area, COLOR_PAIR(5));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(5));
            }
            else
            {
                wattron(area, COLOR_PAIR(6));
                mvwprintw(area, j, i, "%d", map[j/2][i/2]);
                wattroff(area, COLOR_PAIR(6));
            }
        }
    }
}
void drawInfo(WINDOW* area)
{
    init_pair(11, COLOR_RED, COLOR_BLACK); // 벽 설명 색깔지정
    init_pair(12, COLOR_YELLOW, COLOR_BLACK); // 상자 설명 색깔지정
    init_pair(13, COLOR_MAGENTA, COLOR_BLACK); // 목적지 설명 색깔지정
    init_pair(14, COLOR_WHITE, COLOR_BLACK); // 바깥 맵 설명 색깔지정
    init_pair(15, COLOR_CYAN, COLOR_BLACK); // 캐릭터가 갈 수 있는 길 설명 색깔지정
    init_pair(16, COLOR_GREEN, COLOR_BLACK); // 캐릭터 설명 색깔지정
    
    wattron(area, COLOR_PAIR(11));
    mvwprintw(area, 1, 1, "Red: Wall");
    wattroff(area, COLOR_PAIR(11));

    wattron(area, COLOR_PAIR(12));
    mvwprintw(area, 2, 1, "Yellow: Box");
    wattroff(area, COLOR_PAIR(12));

    wattron(area, COLOR_PAIR(16));
    mvwprintw(area, 3, 1, "Green: Character");
    wattroff(area, COLOR_PAIR(16));

    wattron(area, COLOR_PAIR(14));
    mvwprintw(area, 4, 1, "White: Map");
    wattroff(area, COLOR_PAIR(14));

    wattron(area, COLOR_PAIR(15));
    mvwprintw(area, 4, 1, "Blue: Blank");
    wattroff(area, COLOR_PAIR(13));

    wattron(area, COLOR_PAIR(13));
    mvwprintw(area, 5, 1, "Purple: Destination");
    wattroff(area, COLOR_PAIR(15));
}
