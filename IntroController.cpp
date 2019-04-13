#include "IntroController.h"
#include "GameManager.h"

IntroController::IntroController(IntroView &v) : view(v)
{}

void IntroController::handleEvent(sf::Event &event) {
    auto mouse_position = sf::Mouse::getPosition(view.getWindow());
    auto translated_pos = view.getWindow().mapPixelToCoords(mouse_position);
    if(view.getRect_easy_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            gameMode = INTRO_EASY;
        }
    }
    else if(view.getRect_normal_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            gameMode = INTRO_NORMAL;
        }
    }
    else if(view.getRect_hard_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            gameMode = INTRO_HARD;
        }
    }

    if(view.getRect_small_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            introSize = intro_small;
        }
    }
    else if(view.getRect_normal_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            introSize = intro_normal;
        }
    }
    else if(view.getRect_big_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            introSize = intro_big;
        }
    }
    if(view.getRect().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            finished = true;
        }
    }
}

IntroGameMode IntroController::getGameMode() const {
    return gameMode;
}

IntroSize IntroController::getIntroSize() const {
    return introSize;
}
