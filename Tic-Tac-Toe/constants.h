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
const float BOARD_LINE_WIDTH = 16.f;
const float X_LINE_LENGHT = 150.f;
const float X_LINE_THICKNESS = 10.f;

//Colors
const sf::Color BG_COLOR(42, 37, 44, 255);
const sf::Color LINE_COLOR(55, 51, 58, 255);
const sf::Color CIRCLE_COLOR(239, 231, 200, 255);
