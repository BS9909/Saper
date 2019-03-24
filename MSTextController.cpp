//
// Created by Bartek on 21.03.2019.
//
#include <iostream>
#include "MSTextController.h"
#include <conio.h>
#include <string>

MSTextController::MSTextController(MSBoardTextView &v, Minesweeperboard &b): view(v),board(b) {
}

void MSTextController::play() const {
    int row_position=0, column_position=0;
    view.display(row_position, column_position);
    char k;
    do {
        k = getch();
        if (k == 'f') {
            board.toggleFlag(row_position, column_position);
            system("CLS");
            view.display(row_position,column_position);
        }
        else if (k == 'o') {
            board.revealField(row_position, column_position);
            system("CLS");
            view.display(row_position,column_position);
        }
        else {
            while (kbhit()) {
                switch (k) {
                    case 0:
                        k = getch();
                        switch (k) {
                            case 72:
                                row_position--;
                                if (row_position == 0) row_position = board.getBoardHeight() - 1;
                                system("CLS");
                                view.display(row_position,column_position);
                                break;
                            case 80:
                                row_position++;
                                if (row_position == board.getBoardHeight() - 1) row_position = 0;
                                system("CLS");
                                view.display(row_position,column_position);
                                break;
                            case 75:
                                column_position--;
                                if (column_position == 0) row_position = board.getBoardWidth() - 1;
                                system("CLS");
                                view.display(row_position,column_position);
                                break;
                            case 77:
                                column_position++;
                                if (row_position == board.getBoardWidth() - 1) row_position = 0;
                                system("CLS");
                                view.display(row_position,column_position);
                                break;
                        }
                }
            }
        }
    }while (board.getGameState()==RUNNING);
    if(board.getGameState()==FINISHED_LOSS) std::cout<<"LOSS";
    else if(board.getGameState()==FINISHED_WIN) std::cout<<"Win";
}