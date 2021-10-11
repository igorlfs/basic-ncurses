#include <ncurses.h>
#include <string>
#include <vector>

int main() {

    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuWin = newwin(6, xMax - 12, yMax - 8, 5);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);

    keypad(menuWin, true);
    std::vector<std::string> choices = {"Wal", "Jog", "Run"};
    int choice;
    uint highlight = 0;

    while (1) {
        for (uint i = 0; i < choices.size(); ++i) {
            if (i == highlight) wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, i + 1, 1, choices[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        choice = wgetch(menuWin);
        switch (choice) {
            case KEY_UP: {
                if (highlight != 0) highlight--;
                break;
            }
            case KEY_DOWN: {
                if (highlight != choices.size() - 1) highlight++;
                break;
            }
        }
        if (choice == KEY_LEFT) break;
    }

    printw("Your choice was: %s", choices[highlight].c_str());

    getch();
    endwin();
}
