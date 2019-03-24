#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>


int main() {
    //int row_x=2, column_y=1;
    Minesweeperboard board(9,7,DEBUG);
    MSBoardTextView view(board);
    MSTextController control(view, board);
    control.play();
    std::cout<<std::endl;
    board.debug_display();
    return 0;
}