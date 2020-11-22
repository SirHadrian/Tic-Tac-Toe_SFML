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


public:
	

private:
	int** board;
	void board_init(int** board);
};

