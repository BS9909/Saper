//
// Created by Bartek on 20.03.2019.
//
#include "Minesweeperboard.h"

#ifndef SAPER0_2_MSBOARDTEXTVIEW_H
#define SAPER0_2_MSBOARDTEXTVIEW_H


class MSBoardTextView {
    Minesweeperboard & board;
public:
    MSBoardTextView(Minesweeperboard & b);
    void display(int row, int column) const;
};


#endif //SAPER0_2_MSBOARDTEXTVIEW_H
