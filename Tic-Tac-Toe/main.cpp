#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tic Tac Toe", sf::Style::Close);

	Board* board = new Board();
	bool game_over = false;

	int player = X;

	while (window.isOpen())
	{
		window.clear(BG_COLOR);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && game_over==false)
			{
				sf::Vector2f pos(sf::Mouse::getPosition(window));

				int row = (int)(pos.y / SQUARE_SIZE);
				int col = (int)(pos.x / SQUARE_SIZE);

				if (player == X)
				{
					if (board->set_X(row, col)) { player = O; }
				}
				else {
					if (board->set_O(row, col)) { player = X; }
				}
			}
		}


		board->draw_lines(window);
		board->draw_shapes(window);

		if (board->win_check(window, player))
		{
			game_over = true;
		}

		window.display();
	}
	delete board;

	return EXIT_SUCCESS;
}