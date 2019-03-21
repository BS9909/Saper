#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "My window");

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Red);




        window.display();
    }
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