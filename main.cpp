#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <kigyo2.h>
#include <menu.h>
#include <options.h>
std::string FloatToString(float d)
{
   std::stringstream ss;
   ss << d;
   std::string s = ss.str();
   std::string r = "";

   int db = 0;
   while (s[db] != '.'){
        db++;
   }
   int i = 0;
   while (i < db + 2){
        r += s[i];
        i++;
   }
   return r;
}

std::string IntToString(int d)
{
   std::stringstream ss;
   ss << d;
   std::string s = ss.str();
   return s;
}

int main()
{

    int asdf=0,f=0;
    sf::Font font2;
    font2.loadFromFile("arial.ttf");
    sf::Text stopperido;
    sf::Text pont;
    pont.setFont(font2);
    pont.setPosition(100,0);
    pont.setColor(sf::Color::Yellow);
    stopperido.setFont(font2);
    stopperido.setPosition(0,0);
    bool asd=false;
    sf::RenderWindow ablak(sf::VideoMode(720,720),"Snake");
    kigyo a;

    sf::Time ido;
    sf::Clock ora,ora2;
    sf::Time stopper=sf::seconds(60);
    Menu menu(ablak.getSize().x, ablak.getSize().y);
    Options options(ablak.getSize().x, ablak.getSize().y);
    while (ablak.isOpen())
    {
    switch (asdf){
    case 1:
    {

        if (asd==false) {a.spawn();ablak.draw(a.alma);asd=true;}
        sf::Event event;
        while(ablak.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                case sf::Keyboard::Left:
                    if (a.x[0]-20!=a.x[1]) a.irany(1);
                    break;

                case sf::Keyboard::Right:
                    if (a.x[0]!=a.x[1]-20) a.irany(2);
                    break;

                case sf::Keyboard::Up:
                    if (a.y[0]!=a.y[1]+20) a.irany(3);
                    break;

                case sf::Keyboard::Down:
                    if (a.y[0]+20!=a.y[1]) a.irany(4);
                    break;

                case sf::Keyboard::Escape:
                    {
                  a.x.clear();
                    a.y.clear();
                    a.testresz.clear();
                    a.x.push_back(0); a.y.push_back(0);
                    sf::RectangleShape r;
                    r.setPosition(0,0);
                    r.setFillColor(sf::Color::Magenta);
                    a.testresz.push_back(r);
                    a.x.push_back(20); a.y.push_back(0);
                    sf::RectangleShape t;
                    t.setPosition(20,0);
                    a.testresz.push_back(t);
                    asdf=0;f=1;
                    std::cout<<a.x[0];
                    break;
                    }

                case sf::Keyboard::Space:
                    asdf=3;
                    break;
                }
            break;
            }

/*

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (a.x[0]-20!=a.x[1]) a.irany(1);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (a.x[0]!=a.x[1]-20) a.irany(2);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (a.y[0]!=a.y[1]+20) a.irany(3);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (a.y[0]+20!=a.y[1]) a.irany(4);
            }
*/
            if (event.type==sf::Event::Closed)
                ablak.close();
        }



    ablak.clear();
    ido=ora.getElapsedTime();
    if (ido>sf::milliseconds(100))
    {

        ido=sf::milliseconds(0);
        ora.restart();
        a.test();
        a.fej();
        a.raharapotte(ablak);
      //  std::cout<<options.hang<<std::endl;

        a.bekaptae(options.hang);
        if (a.almab==false)
        {
            a.spawn();
            a.almab=true;
            a.novekszik();
        }
        a.keret();
    }
  //  sf::sleep(sf::milliseconds(100));
    stopper-=ora2.getElapsedTime();
    ora2.restart();
 //   std::cout<<ora2.getElapsedTime().asSeconds();
    a.rajzolj(ablak);
    stopperido.setString(FloatToString(stopper.asSeconds()));
    pont.setString(IntToString(a.x.size()-2));
    ablak.draw(pont);
    ablak.draw(stopperido);
    ablak.display();

    break;
    }
    case 0:
    {
        sf::Event event;

		while (ablak.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
			//			std::cout << "Play button has been pressed" << std::endl;
						asdf=1;
						break;
					case 1:
			//			std::cout << "Option button has been pressed" << std::endl;
						asdf=2;
						break;
					case 2:
						ablak.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				ablak.close();

				break;

			}
		}

		ablak.clear();

		menu.draw(ablak);
		ablak.display();
		break;
    }
    case 2:
    {
        sf::Event event;

		while (ablak.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					options.MoveUp();
					break;

				case sf::Keyboard::Down:
					options.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (options.GetPressedItem())
					{
					case 0:
		//				std::cout << "Sound button has been pressed" << std::endl;
						options.hang=!(options.hang);
		//				std::cout<<options.hang;

						break;
					case 1:
		//				std::cout << "Menu button has been pressed" << std::endl;
						asdf=0;
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				ablak.close();

				break;

			}
		}
        ablak.clear();
        options.hangar(ablak.getSize().x, ablak.getSize().y,ablak);

		options.draw(ablak);
		ablak.display();
		break;
    }
    case 3:
    {
        sf::Event event;
        while (ablak.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                asdf=1;

            if (event.type == sf::Event::Closed)
                ablak.close();
        }
   //     ablak.clear();
        options.pause(ablak.getSize().x, ablak.getSize().y,ablak);
        ablak.display();
        break;
    }

    }
    }
}

