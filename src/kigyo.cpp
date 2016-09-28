#include "kigyo.h"

kigyo::kigyo()
{




}

kigyo::~kigyo()
{
    //dtor
}


void kigyo::rajzolj(sf::RenderWindow& ablak)
{
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setPosition(20,20);
    ablak.draw(rectangle);
}

