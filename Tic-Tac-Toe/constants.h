#pragma once
#include <SFML/Graphics/Color.hpp>

//Window
const unsigned int WIDTH = 600;
const unsigned int HEIGHT = 600;

//Board
const unsigned int ROWS = 3;
const unsigned int COLS = 3;
const int SQUARE_SIZE = 200;
const float CIRCLE_RADIUS = 54.f;
const float OUTLINE_THICKNESS = 10.f;
const float BOARD_LINE_WIDTH = 12.f;
const float X_LINE_LENGHT = 150.f;
const float X_LINE_THICKNESS = 10.f;
const int Free = 0;
const int O = 2;
const int X = 1;
const float WIN_LINES_EXPAND = 40.f;

//Colors
const sf::Color BG_COLOR(42, 37, 44, 255);
const sf::Color LINE_COLOR(55, 51, 58, 255);
//const sf::Color CIRCLE_COLOR(239, 231, 200, 255);
const sf::Color O_COLOR(137, 133, 165, 255);
const sf::Color X_COLOR(81, 76, 111, 255);