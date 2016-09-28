#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#ifndef KIGYO2_H
#define KIGYO2_H


class kigyo
{

    public:
        sf::Sound sound;
        sf::SoundBuffer buffer;
        void keret();
        void raharapotte(sf::RenderWindow&);
        void novekszik();
        sf::Vector2f veg;
        int kigyohossz;
        void bekaptae(bool);
        bool almab=true;
        void spawn();
        void rajzolj(sf::RenderWindow&);
        kigyo();
        void irany(int);
        void test();
        virtual ~kigyo();
        void fej();
        sf::RectangleShape alma;
        int direction=4;
        std::vector<int> x;
        std::vector<int> y;
        std::vector<sf::RectangleShape> testresz;
    protected:
    private:



};

#endif // KIGYO_H
