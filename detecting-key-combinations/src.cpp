#include <iostream>
#include <ncurses.h>

#define ctrl(x) (x & 0x1F)

int main() {
    initscr(); // Initialize ncurses
    cbreak();  // Stop with ^C
    noecho();  // Do not display user input

    char ch;
    while ((ch = getch())) {
        mvprintw(1, 0, "KEY NAME : %s - 0x%02x\n", keyname(ch), ch);
        if (ch == ('b' & 0x1F))
            mvprintw(0, 0, "Detected Ctrl+b");
        else if (ch == ctrl('p'))
            mvprintw(0, 0, "Detected Ctrl+p");
    }

    endwin(); // End ncurses
    return 0;
}
