#include "MinesweeperView.h"
#include "MSSFMLview.h"

MinesweeperView::MinesweeperView(MSSFMLview &mssfmLview):mssfmLview(mssfmLview) {}

void MinesweeperView::draw(sf::RenderWindow &win) {
    mssfmLview.draw();
}


