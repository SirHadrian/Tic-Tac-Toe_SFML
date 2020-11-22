#include "Board.h"

Board::Board()
{
	board = new int* [ROWS];
	for (unsigned int i = 0; i < ROWS; ++i)
		board[i] = new int[COLS];

	board_init(board);
}

Board::~Board()
{
	for (unsigned int i = 0; i < ROWS; ++i)
		delete board[i];
	delete[] board;
}

void Board::draw_lines(sf::RenderWindow& window)
{
	//Lines
	sf::RectangleShape line_1(sf::Vector2f(HEIGHT, LINE_WIDTH));
	line_1.setFillColor(LINE_COLOR);
	line_1.setPosition(sf::Vector2f(SQUARE_SIZE, 0));
	line_1.rotate(90);

	sf::RectangleShape line_2(sf::Vector2f(HEIGHT, LINE_WIDTH));
	line_2.setFillColor(LINE_COLOR);
	line_2.setPosition(sf::Vector2f(SQUARE_SIZE * 2, 0));
	line_2.rotate(90);

	sf::RectangleShape line_3(sf::Vector2f(WIDTH, LINE_WIDTH));
	line_3.setFillColor(LINE_COLOR);
	line_3.setPosition(sf::Vector2f(0, SQUARE_SIZE));

	sf::RectangleShape line_4(sf::Vector2f(WIDTH, LINE_WIDTH));
	line_4.setFillColor(LINE_COLOR);
	line_4.setPosition(sf::Vector2f(0, SQUARE_SIZE * 2));
	

	//Draw
	window.draw(line_1);
	window.draw(line_2);
	window.draw(line_3);
	window.draw(line_4);
}

void Board::print_board(int** board)const
{
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		for (unsigned int col = 0; col < COLS; ++col)
		{
			std::cout << board[row][col] << " ";
		}
		std::cout << "\n";
	}
}

int** Board::get_board()const
{
	return board;
}

void Board::board_init(int** board)
{
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		for (unsigned int col = 0; col < COLS; ++col)
		{
			board[row][col] = 0;
		}
	}
}
