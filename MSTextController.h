//
// Created by Bartek on 21.03.2019.
//
#include "MSBoardTextView.h"
#include "Minesweeperboard.h"
#ifndef SAPER0_2_MSTEXTCONTROLLER_H
#define SAPER0_2_MSTEXTCONTROLLER_H


class MSTextController {
    MSBoardTextView &view;
    Minesweeperboard &board;
    static GameState game_status;
public:
    MSTextController(MSBoardTextView &v, Minesweeperboard &b);
    void play() const;
};

#endif //SAPER0_2_MSTEXTCONTROLLER_H
