#ifndef MENU_H
#define MENU_H
#include <ncurses.h>
#include <string>
class Menu {
  private:
    int startX;
    std::string text;
    char trigger;
    std::string *itens;
    int numberItens;
    int selectedItem{0};

  public:
    Menu(const std::string &text, const char &trigger, std::string *itens,
         const int &numberItens)
        : text(text), trigger(trigger), itens(itens), numberItens(numberItens) {
    }
    void setStart(const int &x) { this->startX = x; }

    int getStart() const { return this->startX; }
    char getTrigger() const { return this->trigger; }
    std::string getText() const { return this->text; }
    int getNumberItens() const { return this->numberItens; }
    std::string getItem(const int &i) const { return this->itens[i]; }
    int getSelectedItem() const { return this->selectedItem; }

    void selectNextItem() {
        (this->selectedItem == this->numberItens - 1) ? this->selectedItem = 0
                                                      : this->selectedItem++;
    }
    void selectPreviosItem() {
        (this->selectedItem == 0) ? this->selectedItem = this->numberItens - 1
                                  : this->selectedItem--;
    };
};
#endif
