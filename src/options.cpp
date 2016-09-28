#include "options.h"


Options::Options(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}


	options[0].setFont(font);
	options[0].setColor(sf::Color::Red);
	options[0].setString("Sounds");
	options[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


	options[1].setFont(font);
	options[1].setColor(sf::Color::White);
	options[1].setString("Back");
	options[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

void Options::hangar(float width, float height,sf::RenderWindow &window)
{
    hangnegyzett.setPosition(sf::Vector2f(3*width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    hangnegyzett.setSize(sf::Vector2f(40,40));
    hangnegyzett.setFillColor(sf::Color::Red);
    hangnegyzetf.setPosition(sf::Vector2f(3*width / 7 + 5, height / (MAX_NUMBER_OF_ITEMS + 1) + 5));
    hangnegyzetf.setSize(sf::Vector2f(30,30));
    hangnegyzetf.setFillColor(sf::Color::Black);
    window.draw(hangnegyzett);
    window.draw(hangnegyzetf);

    if (hang)
    {

        sf::RectangleShape a(sf::Vector2f(24,24));
        a.setPosition(sf::Vector2f(3*width / 7 + 8, height / (MAX_NUMBER_OF_ITEMS + 1) + 8));
        a.setFillColor(sf::Color::Red);
        window.draw(a);
    };



}

Options::~Options()
{
}

void Options::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(options[i]);
	}

}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		options[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		options[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		options[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		options[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void::Options::pause(float width, float height,sf::RenderWindow &window)
{
    sf::Text szunet;
    szunet.setFont(font);
    szunet.setPosition(sf::Vector2f(3*width / 8, 3*height / 7));
    szunet.setString("Paused");
    szunet.setCharacterSize(60);
    window.draw(szunet);
}
