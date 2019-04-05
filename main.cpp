#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSGui.h"
#include "MSSFMLview.h"
#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    srand(time(NULL));
    sf::RenderWindow win(sf::VideoMode(1000,1000), "Sweeper_Window", sf::Style::Default);
    Minesweeperboard board(9,7,DEBUG);
    board.revealField(1,3);
    board.revealField(2,7);
    board.revealField(3,1);
    board.revealField(4,4);
    board.revealField(5,3);
    board.revealField(6,8);
    board.revealField(0,1);
    board.toggleFlag(5,5);
    board.toggleFlag(2,6);
    board.debug_display();
    //board.toggleFlag(0,0);
    MSSFMLview sfml_view(50.f, board, 200,200);
    while (win.isOpen()){
        sf::Event event;
        while (win.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color::Black);

        sfml_view.draw(win);

        win.display();
    }


    return 0;
}