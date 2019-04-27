#include "ScoreView.h"

ScoreView::ScoreView(MSSFMLview &mssfmLview): mssfmLview(mssfmLview) {
    if (!font.loadFromFile("arial.ttf")) {
        abort();
    }
    text.setPosition(0,700);
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setCharacterSize(100);
    text.setOutlineThickness(25);
    text.setFillColor(sf::Color::Yellow);

    revealAmountText.setFont(font);
    revealAmountText.setCharacterSize(30);
    revealAmountText.setFillColor(sf::Color::Yellow);
    revealAmountText.setOutlineThickness(2);
    revealAmountText.setOutlineColor(sf::Color::Blue);
    revealAmountText.setPosition(0,0);

}

void ScoreView::draw(sf::RenderWindow &win) {
    win.draw(revealAmountText);
    win.draw(text);
    mssfmLview.draw();
}