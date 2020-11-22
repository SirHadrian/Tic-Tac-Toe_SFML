#include "Board.h"

Board::Board()
{
	board = new int* [ROWS];
	for (unsigned int i = 0; i < ROWS; ++i)
		board[i] = new int[COLS];

	init_board(board);
	init_lines();
	init_x_o();
	board[2][2] = 1;
	board[0][0] = 1;
	board[1][2] = 2;
}

Board::~Board()
{
	for (unsigned int i = 0; i < ROWS; ++i)
		delete board[i];
	delete[] board;
}

void Board::draw_lines(sf::RenderWindow& window)
{
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

void Board::draw_shapes(sf::RenderWindow& window)
{
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		for (unsigned col = 0; col < COLS; ++col)
		{
			if (board[row][col] == 2)
			{
				draw_x(window, row, col);
			}
			else if (board[row][col] == 1)
			{
				draw_o(window, row, col);
			}
		}
	}
}

void Board::init_board(int** board)
{
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		for (unsigned int col = 0; col < COLS; ++col)
		{
			board[row][col] = 0;
		}
	}
}

void Board::draw_x(sf::RenderWindow& window, const int& row, const int& col)
{
	//set position
	line_1_x.setPosition(sf::Vector2f((float)(SQUARE_SIZE * col + SQUARE_SIZE / 2), (float)(SQUARE_SIZE * row + SQUARE_SIZE / 2)));
	line_2_x.setPosition(sf::Vector2f((float)(SQUARE_SIZE * col + SQUARE_SIZE / 2), (float)(SQUARE_SIZE * row + SQUARE_SIZE / 2)));


	//draw X
	window.draw(line_1_x);
	window.draw(line_2_x);
}

void Board::draw_o(sf::RenderWindow& window, const int& row, const int& col)
{
	//set position
	circle.setPosition(sf::Vector2f((float)(SQUARE_SIZE * col + SQUARE_SIZE / 2), (float)(SQUARE_SIZE * row + SQUARE_SIZE / 2)));

	//draw O
	window.draw(circle);
}

void Board::init_x_o()
{
	//INIT X

	// X Lines size
	line_1_x.setSize(sf::Vector2f(X_LINE_LENGHT, X_LINE_THICKNESS));
	line_2_x.setSize(sf::Vector2f(X_LINE_LENGHT, X_LINE_THICKNESS));

	//Lines position
	//line_1_x.setPosition(sf::Vector2f(450.f, 300.f));
	//line_2_x.setPosition(sf::Vector2f(450.f, 300.f));

	//Lines origin point
	line_1_x.setOrigin(line_1_x.getSize().x / 2, line_1_x.getSize().y / 2);
	line_2_x.setOrigin(line_2_x.getSize().x / 2, line_2_x.getSize().y / 2);

	//Lines rotation
	line_1_x.rotate(45.f);
	line_2_x.rotate(135.f);

	//Lines color
	line_1_x.setFillColor(sf::Color::Red);
	line_2_x.setFillColor(sf::Color::Red);


	//INIT O

	//Circle radius
	circle.setRadius(CIRCLE_RADIUS);

	//Circle outline color/thickness
	circle.setOutlineThickness(OUTLINE_THICKNESS);
	circle.setOutlineColor(CIRCLE_COLOR);

	//Circle fill color
	circle.setFillColor(BG_COLOR);

	//Circle origin point
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
}

void Board::init_lines()
{
	//Lines
	line_1.setSize(sf::Vector2f(HEIGHT, BOARD_LINE_WIDTH));
	line_1.setFillColor(LINE_COLOR);
	line_1.setPosition(sf::Vector2f(SQUARE_SIZE, 0));
	line_1.rotate(90);

	line_2.setSize(sf::Vector2f(HEIGHT, BOARD_LINE_WIDTH));
	line_2.setFillColor(LINE_COLOR);
	line_2.setPosition(sf::Vector2f(SQUARE_SIZE * 2, 0));
	line_2.rotate(90);

	line_3.setSize(sf::Vector2f(WIDTH, BOARD_LINE_WIDTH));
	line_3.setFillColor(LINE_COLOR);
	line_3.setPosition(sf::Vector2f(0, SQUARE_SIZE));

	line_4.setSize(sf::Vector2f(WIDTH, BOARD_LINE_WIDTH));
	line_4.setFillColor(LINE_COLOR);
	line_4.setPosition(sf::Vector2f(0, SQUARE_SIZE * 2));
}
