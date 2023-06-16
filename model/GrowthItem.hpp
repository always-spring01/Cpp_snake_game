#pragma once
#include <ncurses.h>
#include "../view/Drawable.hpp"

class GrowthItem : public Drawable {
public:
    GrowthItem(int row, int col) {
        this->row = row;
        this->col = col;
        this->icon = 'A';
    }
};