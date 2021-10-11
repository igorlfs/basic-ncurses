#include <iostream>
#include <ncurses.h>

// Exits if there's no color support
void checkColorSupport();

int main() {
    initscr(); // Initialize ncurses
    cbreak();  // Stop with ^C
    noecho();  // Do not display user input

    checkColorSupport();

    // newin(height, width, start_y, start_x)
    WINDOW *win = newwin(10, 20, 10, 10);
    refresh(); // Update screen with data in memory
               // When should I refresh? https://youtu.be/U82JXzJoCL4

    /// Movement/Priting
    move(5, 10);                    // Move cursor (y,x)
    printw("Libre ipsum");          // Similar to C's printf
    mvprintw(10, 5, "Sample text"); // Merge above (y,x,...)
    getch();                        // Wait for user input
    clear();                        // Clears the screen

    /// Border
    box(win, 0, 0); // Parameters are ints (ascii)
    refresh();
    mvwprintw(win, 5, 5, "Big Chungus"); // window specific mvprintw
    wrefresh(win);                       // Update window with data in memory
    getch();
    clear();
    refresh();

    /// Funkier border (top/bottom left/right corners)
    // wborder(window, left, right, top, bottom, tlc, trc, blc, brc)
    wborder(win, 0, 0, 0, 0, 0, 0, 0, (int)'+'); // Parameters are ints (ascii)
    refresh();
    mvwprintw(win, 5, 5, "Wild Rift"); // window specific mvwprint
    wrefresh(win);                     // Update window with data in memory
    getch();
    clear();

    /// Attributes
    // Use auto completion to discover all attributes available
    // TODO: test which attributes are supported by kitty
    attron(A_BOLD);
    printw("Hello World!");
    attroff(A_BOLD);
    getch();
    clear();

    /// Basic: color
    start_color();
    // init_pair(name, foreground, background)
    init_pair(1, COLOR_RED, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("Ran out of ideas");
    attroff(COLOR_PAIR(1));
    getch();
    clear();

    /// Change color
    // BUG: does not work with nvim's term
    if (can_change_color()) {
        init_color(COLOR_WHITE, 0, 0, 0);
        attron(COLOR_PAIR(1));
        printw("Something else");
        attroff(COLOR_PAIR(1));
    }
    getch();
    clear();

    /// Store attributes
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    // Combine attributes
    attr_t fancy = A_BOLD | COLOR_PAIR(2);
    attron(fancy);
    mvaddch(5, 5, '@');
    attroff(fancy);
    // store char and attributes
    chtype tag = '#' | A_ITALIC | COLOR_PAIR(1);
    mvaddch(7, 7, tag);
    getch();
    clear();

    /// Get cursor position
    // Works with any "window" (stdscr is the default win)
    int y, x, yBeg, xBeg, yMax, xMax;
    getyx(stdscr, y, x);          // Get current position
    getbegyx(stdscr, yBeg, xBeg); // Get beginning position
    getmaxyx(stdscr, yMax, xMax); // Get max position
    mvprintw(yMax / 2, xMax / 2, "%d %d", yMax, xMax);
    clear();

    // Getting user input
    WINDOW *inputWindow = newwin(3, xMax - 12, yMax - 5, 5);
    box(inputWindow, 0, 0);
    refresh();
    wrefresh(inputWindow);

    keypad(inputWindow, true); // Enable macros (eg, arrow keys)
    if (wgetch(inputWindow) == KEY_UP) {
        mvwprintw(inputWindow, 1, 1, "Up has been pressed");
        wrefresh(inputWindow);
    }

    // Changing attributes
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_RED);
    // int chgat(int n, attr_t attr, short color, const void *opts)
    // chgat, mvchgat, wchgat, mvwchgat
    chgat(5, A_STANDOUT, 3, nullptr);
    chgat(-1, A_STANDOUT, 0, nullptr); // -1 -> until EOL

    // Clear routines
    // All have a window variant
    clrtoeol(); // clear to end of line
    clrtobot(); // clear to bottom
    erase();    // soft clear (same as clear())
    clear();    // hard clear

    getch();

    endwin(); // End ncurses
    return 0;
}
void checkColorSupport() {
    if (!has_colors()) {
        printw("No color support");
        getch();
        exit(1);
    }
}
