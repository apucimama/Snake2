#include "gyumolcs.h"

gyumolcs::gyumolcs()
{

}

void gyumolcs::spawn(sf::RenderWindow& ablak)
{
    int rx,ry;
    sf::Vector2f size;
    size.x=20;
    size.y=20;
    rx=(rand()%1020);
    ry=(rand()%1020);
    sf::RectangleShape gy;
    gy.setSize(size);
    gy.setPosition((rx-rx%20),(ry-ry%20));
  //  gy.setFillColor(sf::Color::Red);
    ablak.draw(gy);
    std::cout<<rx-rx%20<<" "<<(ry-ry%20);
}

gyumolcs::~gyumolcs()
{
    //dtor
}
