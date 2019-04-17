#include <SFML/Graphics.hpp>
#include "MSSFMLview.h"
#include "Minesweeperboard.h"
#include "MSSFMLview.h"
#include "ScoreController.h"
#include "ScoreView.h"
#include "IntroController.h"
#include "IntroView.h"
#include "iostream"
#include "MinesweeperController.h"
#include "MinesweeperView.h"
#include "Minesweeperboard.h"
#include "MSSFMLview.h"
#include <cmath>
#include "GameManager.h"
#include <conio.h>
#include <ctime>

int main() {
    srand(time(NULL));
    // Create the main window
    sf::Event event;

    sf::RenderWindow win(sf::VideoMode(1000, 800), "Saper");

    // generalnie - do kontrolera przekażemy referencje na widok i model, czyli
    // IntroController ic(iv, im);
    // w tym przypadku model jest tak prosty, że "zintegrowałem" go z widokiem

    // fake - zastąpcie Waszą klasą, dodajcie model planszy
    IntroView iv(win);

    Minesweeperboard board(9,7,DEBUG);

    MSSFMLview sfml_view(30.f, board, 0,50,win);

    IntroController ic(iv, board, sfml_view);



    MinesweeperView mv(sfml_view);

    // uwagi jak do Intro
    ScoreView sv;
    MinesweeperController mc(mv, win,board,sv);

    ScoreController sc(sv);

    GameManager gm(ic, mc, sc);

    // Start the game loop
    while (win.isOpen()) {
        // Process events
        while (win.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                win.close();

            gm.handleEvent(event);
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
        }
        // Clear screen
        win.clear();

        // Draw current state
        gm.draw(win);

        // Update the window
        win.display();
    }
   // board.debug_display();

    return EXIT_SUCCESS;
}
