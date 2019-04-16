#include "IntroController.h"
#include "GameManager.h"

IntroController::IntroController(IntroView &v,Minesweeperboard &msb) : view(v),
msb(msb)
{}

void IntroController::handleEvent(sf::Event &event) {
    auto mouse_position = sf::Mouse::getPosition(view.getWindow());
    auto translated_pos = view.getWindow().mapPixelToCoords(mouse_position);

    //std::cout<<game_mode<<std::endl;

    if(view.getRect_easy_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            msb.setGameMOde(EASY);
            view.text_mode.setString("EASY");
        }
    }
     if(view.getRect_normal_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            msb.setGameMOde(NORMAL);
            view.text_mode.setString("NORMAL");

        }
    }
     if(view.getRect_hard_mode().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            msb.setGameMOde(HARD);
            view.text_mode.setString("HARD");

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


IntroSize IntroController::getIntroSize() const {
    return introSize;
}

IntroGameMode IntroController::getIntroGameMode()  {
    return introGameMode;
}

bool IntroController::isIntromode() const {
    return intromode;
}

