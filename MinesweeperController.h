#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "MSSFMLview.h"
#include "Minesweeperboard.h"
#include "IntroController.h"

class MinesweeperController {
    bool finished = false;

    MinesweeperView & view;
    sf::RenderWindow &win;
    MSSFMLview &mssfmLview;
    Minesweeperboard &msb;
    sf::Event event;
    // ... & model;
public:
    MinesweeperController(MinesweeperView & v, sf::RenderWindow &win, MSSFMLview &mssfmLview,Minesweeperboard &msb);
    void setMode();
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
