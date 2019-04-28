#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>
#include "MSSFMLview.h"

class ScoreView {
    sf::Text text;
    sf::Text revealAmountText;
    sf::Font font;
    MSSFMLview &mssfmLview;
public:
    const sf::RectangleShape &getPlay_again() const;

    const sf::RectangleShape &getClose() const;

private:
    sf::RectangleShape play_again;
    sf::RectangleShape close;
    sf::Text textPlay;
public:
    const sf::Text &getTextPlay() const;

    const sf::Text &getTextClose() const;

private:
    sf::Text textClose;
    sf::RenderWindow &renderWindow;

public:
    ScoreView(sf::RenderWindow &renderWindow,MSSFMLview &mssfmLview);
    void draw(sf::RenderWindow &win);
    void setText(std::string resultString){text.setString(resultString);}
    void setRevealAmountText(std::string revealTExt){revealAmountText.setString("Reveal fieled: " + revealTExt);}
    void setGameStateText(int position_x, int position_y);
    sf::RenderWindow &getWindow() { return renderWindow; };
};


#endif //UNTITLED2_SCOREVIEW_H
