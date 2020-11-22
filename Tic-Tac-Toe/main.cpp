#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tic Tac Toe", sf::Style::Close);

	/*sf::RectangleShape line1(sf::Vector2f(100.f, 5.f));
	sf::RectangleShape line2(sf::Vector2f(100.f, 5.f));

	sf::CircleShape circle(40.f);
	circle.setOutlineThickness(5);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(sf::Color::Green);

	line1.setPosition(sf::Vector2f(450.f, 300.f));
	line2.setPosition(sf::Vector2f(450.f, 300.f));

	line1.setOrigin(line1.getSize().x / 2, line1.getSize().y / 2);
	line2.setOrigin(line2.getSize().x / 2, line2.getSize().y / 2);


	line1.rotate(45.f);
	line2.rotate(135.f);

	line1.setFillColor(sf::Color::Red);
	line2.setFillColor(sf::Color::Red);*/
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
		/*window.draw(circle);
		window.draw(line1);
		window.draw(line2);*/
	
		window.display();
	}
	delete board;

	return EXIT_SUCCESS;
}