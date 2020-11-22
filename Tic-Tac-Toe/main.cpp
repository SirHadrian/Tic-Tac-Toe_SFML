#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tic Tac Toe", sf::Style::Close);

	Board* board = new Board();
	board->print_board(board->get_board());
	
	while (window.isOpen())
	{
		window.clear(BG_COLOR);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		board->draw_lines(window);
		board->draw_shapes(window);
	
		window.display();
	}
	delete board;

	return EXIT_SUCCESS;
}