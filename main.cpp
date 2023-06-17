#include <ncurses.h>
#include "controller/GameManager.hpp"

int main(int argc, char **argv) {
  int i = 0;
  initscr();
  refresh();

  noecho();
  start_color();

  curs_set(0);

  GameManager game(i);
  
  while (!game.isOver()) {
    // 1 : User input
    game.processInput();

    // 2 : update game state
    game.updateState();

    // 3 : redraw display
    game.redraw();

    // 4 : go to 1, unless game over
    if (game.isClear()) game = GameManager(++i);
  }

  getch();
  endwin();

  return 0;
}