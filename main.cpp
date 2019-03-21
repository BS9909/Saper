#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() {
    //int row_x=2, column_y=1;
    Minesweeperboard board(9,7,DEBUG);
    MSBoardTextView view(board);
    MSTextController control(view, board);
    control.play();
    std::cout<<std::endl;
    board.debug_display();
    /*board.toggleFlag(1,2);
    board.revealField(row_x,column_y);
    board.debug_display();*/

    return 0;
}