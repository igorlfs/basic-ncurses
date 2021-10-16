#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
class Player {
  public:
    Player(WINDOW *winc, int yc, int xc, char c);

    int getMv();

    void display();

  private:
    WINDOW *currentWin;
    int yLoc, xLoc, yMax, xMax;
    char character;
};
#endif
