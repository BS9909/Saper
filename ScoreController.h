#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "ScoreView.h"
#include "IntroController.h"
#include "MinesweeperController.h"
#include "Minesweeperboard.h"

class ScoreController {
    bool finished = false;
    ScoreView & view;
    IntroController &introController;
    MinesweeperController &minesweeperController;
    Minesweeperboard &minesweeperboard;
public:
    explicit ScoreController(ScoreView & v,IntroController &introController,MinesweeperController &minesweeperController,Minesweeperboard &minesweeperboard);
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};


#endif //UNTITLED2_SCORECONTROLLER_H
