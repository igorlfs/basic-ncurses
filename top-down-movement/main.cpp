#include "player.hpp"
#include <memory>

int main() {
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *playWin = newwin(20, 50, (yMax / 2) - 10, 10);
    box(playWin, 0, 0);
    refresh();
    wrefresh(playWin);

    std::unique_ptr<Player> p = std::make_unique<Player>(playWin, 1, 1, '@');
    do {
        p->display();
        wrefresh(playWin);
    } while (p->getMv() != 'x');

    delwin(playWin);
    endwin();
}
