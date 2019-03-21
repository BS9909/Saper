//
// Created by Bartek on 21.03.2019.
//
#include <iostream>
#include "MSTextController.h"
#include <conio.h>
#include <string>

MSTextController::MSTextController(MSBoardTextView v, Minesweeperboard &b): view(v),board(b) {
}

void MSTextController::play() {
    int row_position=0, column_position=0;
    bool choice;
    GameState status_of_game = RUNNING;
    while(status_of_game==RUNNING){
        std::cout<<"Flag=1-Reveal=0: ";
        std::cin>>choice;
        std::cout<<"Set row postion: ";
        std::cin>>row_position;
        std::cout<<"Set column position: ";
        std::cin>>column_position;
        if(choice==1) board.toggleFlag(row_position-1,column_position-1);
        else if(choice==0) board.revealField(row_position-1, column_position-1);
        std::cout<<std::endl;
        view.display();
        status_of_game = board.getGameState();
    }
    if (status_of_game==FINISHED_LOSS) std::cout<<"Ups, you lose";
    else if (status_of_game==FINISHED_WIN) std::cout<<"Congratulations! You win";

}