#include "Board.h"

Board::Board()
{
	board = new int* [ROWS];
	for (unsigned int i = 0; i < ROWS; ++i)
		board[i] = new int[COLS];

	init_board(board);
	init_lines();
	init_x_o();
	init_text();
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
			if (board[row][col] == O)
			{
				draw_o(window, row, col);
			}
			else if (board[row][col] == X)
			{
				draw_x(window, row, col);
			}
		}
	}
}

bool Board::set_O(const int& row, const int& col)
{
	if (board[row][col] == Free)
	{
		board[row][col] = O;
		return true;
	}
	return false;
}

bool Board::set_X(const int& row, const int& col)
{
	if (board[row][col] == Free)
	{
		board[row][col] = X;
		return true;
	}
	return false;
}

bool Board::win_check(sf::RenderWindow& window, const int& player) const
{
	//COLS/vertical check
	for (unsigned int col = 0; col < COLS; ++col)
	{
		if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
		{
			draw_vertical_win_line(window, player, col);
			return true;
		}
	}
	//ROWS/horizontal check
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
		{
			draw_horizontal_win_line(window, player, row);
			return true;
		}
	}
	//diagonal_1 check
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		draw_diagonal_win_line_1(window, player);
		return true;
	}
	//diagonal_2 check
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	{
		draw_diagonal_win_line_2(window, player);
		return true;
	}

	return false;
}

void Board::reset_board(int** board)
{
	init_board(board);
}

void Board::draw_vertical_win_line(sf::RenderWindow& window, const int& player, const int& col)const
{
	sf::RectangleShape win_line(sf::Vector2f(HEIGHT - SQUARE_SIZE / 2, BOARD_LINE_WIDTH));
	win_line.rotate(90.f);
	float x = (float)(col * SQUARE_SIZE + SQUARE_SIZE / 2);
	float y = SQUARE_SIZE / 2;
	win_line.setPosition(sf::Vector2f(x, y - WIN_LINES_EXPAND));
	win_line.setOrigin(sf::Vector2f(BOARD_LINE_WIDTH / 2, BOARD_LINE_WIDTH / 2));

	if (player == X)
		win_line.setFillColor(X_COLOR);
	else
		win_line.setFillColor(O_COLOR);

	window.draw(win_line);
}

void Board::draw_horizontal_win_line(sf::RenderWindow& window, const int& player, const int& row)const
{
	sf::RectangleShape win_line(sf::Vector2f(WIDTH - SQUARE_SIZE / 2, BOARD_LINE_WIDTH));

	float y = (float)(row * SQUARE_SIZE + SQUARE_SIZE / 2);
	float x = SQUARE_SIZE / 2;
	win_line.setPosition(sf::Vector2f(x - WIN_LINES_EXPAND, y));
	win_line.setOrigin(sf::Vector2f(BOARD_LINE_WIDTH / 2, BOARD_LINE_WIDTH / 2));

	if (player == X)
		win_line.setFillColor(X_COLOR);
	else
		win_line.setFillColor(O_COLOR);

	window.draw(win_line);
}

void Board::draw_diagonal_win_line_1(sf::RenderWindow& window, const int& player)const
{
	sf::RectangleShape win_line(sf::Vector2f(WIDTH + SQUARE_SIZE / 2, BOARD_LINE_WIDTH));
	float x = (float)(SQUARE_SIZE / 2);
	win_line.setPosition(sf::Vector2f(x - WIN_LINES_EXPAND, x - WIN_LINES_EXPAND));
	win_line.setOrigin(sf::Vector2f(BOARD_LINE_WIDTH / 2, BOARD_LINE_WIDTH / 2));
	win_line.rotate(45.f);

	if (player == X)
		win_line.setFillColor(X_COLOR);
	else
		win_line.setFillColor(O_COLOR);

	window.draw(win_line);
}

void Board::draw_diagonal_win_line_2(sf::RenderWindow& window, const int& player)const
{
	sf::RectangleShape win_line(sf::Vector2f(WIDTH + SQUARE_SIZE / 2, BOARD_LINE_WIDTH));
	float x = (float)(WIDTH - SQUARE_SIZE / 2);
	win_line.setPosition(sf::Vector2f(x + WIN_LINES_EXPAND, SQUARE_SIZE / 2 - WIN_LINES_EXPAND));
	win_line.setOrigin(sf::Vector2f(BOARD_LINE_WIDTH / 2, BOARD_LINE_WIDTH / 2));
	win_line.rotate(135.f);

	if (player == X)
		win_line.setFillColor(X_COLOR);
	else
		win_line.setFillColor(O_COLOR);

	window.draw(win_line);
}

void Board::init_text()
{
	//Font
	if (!font.loadFromFile("batmfa__.ttf"))
	{
		throw std::runtime_error("Could not load font from file");
	}

	//Text
	text.setFont(font);
	text.setCharacterSize(FONT_SIZE);
	text.setFillColor(WIN_TEXT_COLOR);
	text.setOutlineColor(WIN_TEXT_COLOR_OUTLINE);
	text.setOutlineThickness(4.f);
	text.setPosition(sf::Vector2f((float)(WIDTH / 2 - 200), (float)(HEIGHT) / 2 - 70));


	reset.setFont(font);
	reset.setCharacterSize(FONT_SIZE - 40);
	reset.setFillColor(RESET_TEXT_COLOR);
	reset.setOutlineColor(WIN_TEXT_COLOR_OUTLINE);
	reset.setOutlineThickness(4.f);
	reset.setPosition(sf::Vector2f((float)(WIDTH / 2 - 132), (float)(HEIGHT - 40)));
	reset.setString("press R to reset");
}

void Board::init_board(int** board)
{
	for (unsigned int row = 0; row < ROWS; ++row)
	{
		for (unsigned int col = 0; col < COLS; ++col)
		{
			board[row][col] = Free;
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

	//Lines origin point
	line_1_x.setOrigin(line_1_x.getSize().x / 2, line_1_x.getSize().y / 2);
	line_2_x.setOrigin(line_2_x.getSize().x / 2, line_2_x.getSize().y / 2);

	//Lines rotation
	line_1_x.rotate(45.f);
	line_2_x.rotate(135.f);

	//Lines color
	line_1_x.setFillColor(X_COLOR);
	line_2_x.setFillColor(X_COLOR);


	//INIT O

	//Circle radius
	circle.setRadius(CIRCLE_RADIUS);

	//Circle outline color/thickness
	circle.setOutlineThickness(OUTLINE_THICKNESS);
	circle.setOutlineColor(O_COLOR);

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
	line_1.rotate(90.f);

	line_2.setSize(sf::Vector2f(HEIGHT, BOARD_LINE_WIDTH));
	line_2.setFillColor(LINE_COLOR);
	line_2.setPosition(sf::Vector2f(SQUARE_SIZE * 2, 0));
	line_2.rotate(90.f);

	line_3.setSize(sf::Vector2f(WIDTH, BOARD_LINE_WIDTH));
	line_3.setFillColor(LINE_COLOR);
	line_3.setPosition(sf::Vector2f(0, SQUARE_SIZE));

	line_4.setSize(sf::Vector2f(WIDTH, BOARD_LINE_WIDTH));
	line_4.setFillColor(LINE_COLOR);
	line_4.setPosition(sf::Vector2f(0, SQUARE_SIZE * 2));
}
