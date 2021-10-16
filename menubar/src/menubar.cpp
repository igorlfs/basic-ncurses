#include "menubar.hpp"
Menubar::Menubar(WINDOW *win, Menu *menus, const int &numberMenus)
    : win(win), menus(menus), numberMenus(numberMenus) {
    int yMax, xMax, yBeg, xBeg;

    getmaxyx(win, yMax, xMax);
    getbegyx(win, yBeg, xBeg);
    this->menuWin = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1);

    keypad(this->menuWin, true); // BUG: Not working for some reason
    wrefresh(this->menuWin);

    uint currentPosition = START_POSITION;
    for (int i = 0; i < this->numberMenus; ++i) {
        this->menus[i].setStart(currentPosition);
        currentPosition += this->menus[i].getText().length() + 1;
    }
}
void Menubar::draw() {
    for (int i = 0; i < this->numberMenus; ++i) {
        bool isSelected = (this->selectedMenu == i);
        drawMenu(this->menus[i], isSelected);
    }
    this->selectedMenu = -1;
}
void Menubar::drawMenu(Menu &menu, bool &isSelected) {
    int startX = menu.getStart();
    std::string text = menu.getText();
    if (isSelected) wattron(this->win, A_STANDOUT);
    mvwprintw(this->win, 0, startX, text.c_str());
    wattroff(this->win, A_STANDOUT);
    wrefresh(this->win);

    drawMenuItens(menu);
    wrefresh(this->menuWin);
    while (isSelected) {
        char ch = wgetch(this->menuWin);
        switch (ch) {
            case KEY_DOWN: menu.selectNextItem(); break;  // BUG
            case KEY_UP: menu.selectPreviosItem(); break; // BUG
            case 'j': menu.selectNextItem(); break;
            case 'k': menu.selectPreviosItem(); break;
            default: isSelected = false;
        }
        drawMenuItens(menu);
    }
    werase(this->menuWin);
    wrefresh(this->menuWin);
    reset();
}
void Menubar::drawMenuItens(const Menu &menu) {
    int xMax = getmaxx(this->menuWin);

    for (int i = 0; i < menu.getNumberItens(); ++i) {
        mvwprintw(this->menuWin, i, 0, menu.getItem(i).c_str());
        if (menu.getSelectedItem() == i)
            mvwchgat(this->menuWin, i, 0, xMax, A_NORMAL, 1, NULL);
        else
            mvwchgat(this->menuWin, i, 0, xMax, A_STANDOUT, 0, NULL);
    }
}
void Menubar::reset() {
    for (int i = 0; i < this->numberMenus; ++i) {
        int startX = this->menus[i].getStart();
        std::string text = this->menus[i].getText();
        mvwprintw(this->win, 0, startX, text.c_str());
    }
    wrefresh(this->menuWin);
}
void Menubar::handleTrigger(const char &trigger) {
    for (int i = 0; i < this->numberMenus; ++i) {
        if (trigger == this->menus[i].getTrigger()) this->selectedMenu = i;
    }
}
