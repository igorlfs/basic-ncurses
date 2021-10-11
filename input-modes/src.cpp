#include <ncurses.h>
int main() {
    initscr();
    cbreak();
    noecho();

    // Wait for user input for x tenths of a second
    halfdelay(5);

    // Do not wait for user input at all
    // nodelay(stdscr,true)

    // If < 0 behave normally, else wait x miliseconds
    /* timeout(500); */

    int c;
    while ((c = getch()) != 'x') printw("%d\n", c);

    endwin();

    return 0;
}
