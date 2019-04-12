#include <SFML/Graphics.hpp>
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

int main() {
    // Create the main window
    sf::RenderWindow win(sf::VideoMode(800, 600), "SFML window");

    IntroView iv;
    IntroController ic(iv);
    // generalnie - do kontrolera przekażemy referencje na widok i model, czyli
    // IntroController ic(iv, im);
    // w tym przypadku model jest tak prosty, że "zintegrowałem" go z widokiem

    // fake - zastąpcie Waszą klasą, dodajcie model planszy
    MinesweeperView mv;
    MinesweeperController mc(mv);

    // uwagi jak do Intro
    ScoreView sv;
    ScoreController sc(sv);

    GameManager gm(ic, mc, sc);

    // Start the game loop
    while (win.isOpen()) {
        // Process events
        sf::Event event;
        while (win.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                win.close();

            gm.handleEvent(event);
        }

        // Clear screen
        win.clear();

        // Draw current state
        gm.draw(win);

        // Update the window
        win.display();
    }

    return EXIT_SUCCESS;
}
