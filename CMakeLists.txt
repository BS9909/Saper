cmake_minimum_required(VERSION 3.13)
project(Saper0_2)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "C:/Users/Bartek/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window system)

add_executable(Saper0_2 main.cpp Minesweeperboard.h Minesweeperboard.cpp MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h MSGui.cpp MSGui.h MSSFMLview.cpp MSSFMLview.h)
target_link_libraries(Saper0_2 sfml-graphics sfml-window sfml-system)