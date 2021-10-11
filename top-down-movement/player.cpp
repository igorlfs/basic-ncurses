#include "player.hpp"
Player::Player(WINDOW *win, int yc, int xc, char c)
    : currentWin(win), yLoc(yc), xLoc(xc), character(c) {
  getmaxyx(this->currentWin, this->yMax, this->xMax);
  keypad(this->currentWin, true);
}
int Player::getMv() {
  int choice = wgetch(this->currentWin);
  // Replaces current char with space
  // No worries, if it doesn't change, it will be overwritten
  mvwaddch(this->currentWin, this->yLoc, this->xLoc, ' ');
  switch (choice) {
  case KEY_UP:
    if (this->yLoc != 1)
      this->yLoc--;
    break;
  case KEY_DOWN:
    if (this->yLoc != this->yMax - 2)
      this->yLoc++;
    break;
  case KEY_LEFT:
    if (this->xLoc != 1)
      this->xLoc--;
    break;
  case KEY_RIGHT:
    if (this->xLoc != this->xMax - 2)
      this->xLoc++;
    break;
  }
  return choice;
}
void Player::display() {
  mvwaddch(this->currentWin, this->yLoc, this->xLoc, this->character);
}
