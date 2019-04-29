#include "ScoreView.h"


ScoreView::ScoreView(sf::RenderWindow &renderWindow,MSSFMLview &mssfmLview):
    renderWindow(renderWindow),
    mssfmLview(mssfmLview) {
    if (!font.loadFromFile("arial.ttf")) {
        abort();
    }
    text.setPosition(100,700-150);
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

    play_again.setPosition(430+100, 700-150);
    play_again.setFillColor(sf::Color::Green);
    play_again.setSize(sf::Vector2f(100,100));
    textPlay.setFont(font);
    textPlay.setString("Play Again");
    textPlay.setCharacterSize(20);
    textPlay.setFillColor(sf::Color::Black);
    textPlay.setPosition(450+83,720-130);

    close.setPosition(550+100,700-150);
    close.setFillColor(sf::Color::Red);
    close.setSize(sf::Vector2f(100,100));
    textClose.setFont(font);
    textClose.setString("Close");
    textClose.setCharacterSize(20);
    textClose.setFillColor(sf::Color::Black);
    textClose.setPosition(570+105,720-130);

}

void ScoreView::draw(sf::RenderWindow &win) {
    win.draw(revealAmountText);
    win.draw(text);
    win.draw(play_again);
    win.draw(textPlay);
    win.draw(close);
    win.draw(textClose);
    mssfmLview.draw();

}

const sf::Text &ScoreView::getTextPlay() const {
    return textPlay;
}

const sf::Text &ScoreView::getTextClose() const {
    return textClose;
}

const sf::RectangleShape &ScoreView::getPlay_again() const {
    return play_again;
}

const sf::RectangleShape &ScoreView::getClose() const {
    return close;
}
