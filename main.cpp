#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"

int main() {
    int row_x=6, column_y=7;
    Minesweeperboard board(9,7,DEBUG);
    board.toggleFlag(1,2);
    board.revealField(row_x,column_y);
    MSBoardTextView view(board);
    view.display();


    return 0;
}