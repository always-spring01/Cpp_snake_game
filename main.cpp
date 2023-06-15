#include <ncurses.h>
#include "view/Board.hpp"
#include "controller/GameManager.hpp"
#include "view/Drawable.hpp"

#define BOARD_DIM 25
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLUMNS BOARD_DIM * 2.5

int main(int argc, char **argv) {
    initscr();
    refresh();

    noecho();

    GameManager game(BOARD_ROWS, BOARD_COLUMNS);

    while(!game.isOver()) {
        // 1 : User input
        game.processInput();

        // 2 : update game state
        game.updateState();

        // 3 : redraw display
        game.redraw();

        // 4 : go to 1, unless game over
    }

    getch();
    endwin();

    return 0;
}