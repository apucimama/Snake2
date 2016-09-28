#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#ifndef GYUMOLCS_H
#define GYUMOLCS_H


class gyumolcs
{
    public:
        void spawn(sf::RenderWindow&);
        gyumolcs();
        virtual ~gyumolcs();
    protected:
    private:
};

#endif // GYUMOLCS_H
