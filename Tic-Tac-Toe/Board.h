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
	bool set_O(const int& row, const int& col);
	bool set_X(const int& row, const int& col);

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
	void draw_vertical_win_line(sf::RenderWindow& window, const int& player, const int& col);
	void draw_horizontal_win_line(sf::RenderWindow& window, const int& player, const int& row);
	void draw_diagonal_win_line_1(sf::RenderWindow& window, const int& player);
	void draw_diagonal_win_line_2(sf::RenderWindow& window, const int& player);
};

