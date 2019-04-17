#include "ScoreView.h"

ScoreView::ScoreView() {
    if (!font.loadFromFile("arial.ttf")) {
        abort();
    }
    rect.setSize(sf::Vector2f(550, 100));
    rect.setPosition(100, 200);
    rect.setFillColor(sf::Color::Blue);
    text.setPosition(100,200);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(50);

    revealAmountText.setFont(font);
    revealAmountText.setCharacterSize(20);
    revealAmountText.setFillColor(sf::Color::Blue);
    revealAmountText.setPosition(0,0);

}

void ScoreView::draw(sf::RenderWindow &win) {
    win.draw(rect);
    win.draw(revealAmountText);
    win.draw(text);
}