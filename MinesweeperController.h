#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "ScoreView.h"
#include "Minesweeperboard.h"
#include "IntroController.h"

class MinesweeperController {
    bool finished = false;

    MinesweeperView & view;
    sf::RenderWindow &win;
    MSSFMLview &mssfmLview;
    Minesweeperboard &msb;
    ScoreView &scoreView;
    sf::Event event;
    int moveCounter;
    // ... & model;
public:
    MinesweeperController(MinesweeperView & v, sf::RenderWindow &win,Minesweeperboard &msb, ScoreView &scoreView,MSSFMLview &mssfmLview);
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
    void setFinished(bool checkFinished){finished = checkFinished;}
    int getMoveCounter() { return moveCounter;}
    void resetMoveCounter(){moveCounter = 0;}
};



#endif // MINESWEEPERCONTROLLER_H
