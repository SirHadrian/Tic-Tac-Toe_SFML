#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>

class Board
{
public:
	Board();
	~Board();
	void draw_lines(sf::RenderWindow& window);
	void print_board(int** board)const;
	int** get_board()const;
	void draw_shapes(sf::RenderWindow& window);

private:
	int** board;
	sf::RectangleShape line_1;
	sf::RectangleShape line_2;
	sf::RectangleShape line_3;
	sf::RectangleShape line_4;
	sf::RectangleShape line_1_x;
	sf::RectangleShape line_2_x;
	sf::CircleShape circle;

private:
	void init_board(int** board);
	void draw_x(sf::RenderWindow& window, const int& row, const int& col);
	void draw_o(sf::RenderWindow& window, const int& row, const int& col);
	void init_x_o();
	void init_lines();
};

