#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2

class Options
{
public:
	Options(float width, float height);
	~Options();
    sf::RectangleShape hangnegyzett;
    sf::RectangleShape hangnegyzetf;
    bool hang=true;
    void hangar(float width, float height,sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void pause(float width, float height, sf::RenderWindow &window);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];

};

