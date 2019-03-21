#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"

int main() {
    int row_x=2, column_y=1;
    Minesweeperboard board(9,7,DEBUG);
    board.toggleFlag(1,2);
    board.revealField(row_x,column_y);
    //board.debug_display();
    MSBoardTextView view(board);
    view.display();


    return 0;
}