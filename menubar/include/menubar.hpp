#ifndef MENU_BAR_H
#define MENU_BAR_H
#include "menu.hpp"
class Menubar {
  private:
    WINDOW *win;
    Menu *menus;
    int numberMenus;
    int selectedMenu{-1};
    WINDOW *menuWin;

    static constexpr uint START_POSITION = 2;

  public:
    Menubar(WINDOW *win, Menu *menus, const int &numberMenus);
    void draw();
    void drawMenu(Menu &menu, bool &isSelected);
    void drawMenuItens(const Menu &menu);
    void reset();
    void handleTrigger(const char &trigger);
};
#endif
