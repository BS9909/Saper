#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>

class ScoreView {
    sf::RectangleShape rect;
public:
    ScoreView();

    void draw(sf::RenderWindow &win);
};


#endif //UNTITLED2_SCOREVIEW_H
