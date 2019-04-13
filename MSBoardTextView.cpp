//
// Created by Bartek on 20.03.2019.
//
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "MSBoardTextView.h"
#include "MSTextController.h"

void MSBoardTextView::display() const {
    for (int i = 0; i < board.getBoardHeight(); ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            std::cout<<"["<<board.getFieldInfo(i,j)<<"]";

        }std::cout<<std::endl;
    }
}
//MSBoardTextView::MSBoardTextView(Minesweeperboard &b): board(b){
//    board = b;
//}