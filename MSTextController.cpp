//
// Created by Bartek on 21.03.2019.
//
#include <iostream>
#include "MSTextController.h"
#include <conio.h>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
MSTextController::MSTextController(MSBoardTextView &v, Minesweeperboard &b): view(v),board(b) {
}

void MSTextController::play() const {
    int row_position = 0, column_position = 0;

    bool choice;
    //sf::RenderWindow window(sf::VideoMode(500,500), "SweeperWindow");

    while (board.getGameState() == RUNNING) {
        std::cout << "Flag=1-Reveal=0: ";
        std::cin >> choice;
        std::cout << "Set row postion: ";
        std::cin >> row_position;
        std::cout << "Set column position: ";
        std::cin >> column_position;

        if (choice == 1) board.toggleFlag(row_position - 1, column_position - 1);
        else if (choice == 0) board.revealField(row_position - 1, column_position - 1);
        std::cout << std::endl;
        view.display();
    }
    if (board.getGameState() == FINISHED_LOSS) std::cout << "Ups, you lose";
    else if (board.getGameState() == FINISHED_WIN) std::cout << "Congratulations! You win";
}

