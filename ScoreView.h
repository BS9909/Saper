#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>

class ScoreView {
    sf::RectangleShape rect;
    sf::Text text;
    sf::Text revealAmountText;
    sf::Font font;
public:
    ScoreView();

    void draw(sf::RenderWindow &win);
    void setText(std::string resultString){text.setString(resultString);}
};


#endif //UNTITLED2_SCOREVIEW_H
