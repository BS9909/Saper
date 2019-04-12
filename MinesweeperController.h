#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"

class MinesweeperController {
    bool finished = false;

    MinesweeperView & view;
    // ... & model;
public:
    explicit MinesweeperController(MinesweeperView & v);
public:
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
