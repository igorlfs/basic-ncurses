#include "menubar.hpp"

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor

    if (!has_colors()) return -1;
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
    box(win, 0, 0);

    std::string menu1[] = {"New", "Open", "Save", "Exit"};
    std::string menu2[] = {"Copy", "Cut", "Paste"};
    std::string menu3[] = {"Sidebar", "Terminal"};
    Menu menus[3] = {
        Menu("File", 'f', menu1, 4),
        Menu("Edit", 'e', menu2, 3),
        Menu("Options", 'o', menu3, 2),
    };

    Menubar menubar = Menubar(win, menus, 3);
    menubar.draw();

    char ch;
    while ((ch = wgetch(win))) {
        menubar.handleTrigger(ch);
        menubar.draw();
    }

    wgetch(win);

    endwin();
}
