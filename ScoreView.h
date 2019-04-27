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
    ScoreView(MSSFMLview &mssfmLview);
    void draw(sf::RenderWindow &win);
    void setText(std::string resultString){text.setString(resultString);}
    void setRevealAmountText(std::string revealTExt){revealAmountText.setString("Reveal fieled: " + revealTExt);}
    void setGameStateText(int position_x, int position_y);
};


#endif //UNTITLED2_SCOREVIEW_H
