#include "kigyo2.h"

kigyo::kigyo()
{
    x.push_back(0); y.push_back(0);
    sf::RectangleShape a;
    a.setPosition(0,0);
    a.setFillColor(sf::Color::Magenta);
    testresz.push_back(a);

    x.push_back(20); y.push_back(0);
    sf::RectangleShape b;
    b.setPosition(20,0);
    testresz.push_back(b);

    buffer.loadFromFile("alma4.wav");

    sound.setBuffer(buffer);
  //  sound.setVolume(100);
  //  sound.play();



}



void kigyo::fej()
{
 //   int a1=testresz[0].getPosition().x,a3=(102000-(0-testresz[0].getPosition().x)),a4=testresz[0].getPosition().y,a5=(72000-(0-testresz[0].getPosition().y));
    if (direction==1)
    {
        x[0] = x[0]-20;
        testresz[0].setPosition(testresz[0].getPosition().x-20,testresz[0].getPosition().y);
    }
    if (direction==2)
    {
        x[0] = x[0]+20;
        testresz[0].setPosition(testresz[0].getPosition().x+20,testresz[0].getPosition().y);
    }
    if (direction==3)
    {
        y[0] = y[0]-20;
        testresz[0].setPosition(testresz[0].getPosition().x,testresz[0].getPosition().y-20);
    }
    if (direction==4)
    {
        y[0] = y[0]+20;
        testresz[0].setPosition(testresz[0].getPosition().x,testresz[0].getPosition().y+20);
    }
/*
        if (testresz[0].getPosition().x>1019)
        {
            testresz[0].setPosition(a1%1020,testresz[0].getPosition().y);
            x[0]=a1%1020;
            y[0]=testresz[0].getPosition().y;
        }
        if (testresz[0].getPosition().x<0)
        {
            testresz[0].setPosition(a3%1020,testresz[0].getPosition().y);
            x[0]=a3%1020;
            y[0]=testresz[0].getPosition().y;
        }
        if (testresz[0].getPosition().y>719)
        {
            testresz[0].setPosition(testresz[0].getPosition().x,a4%720);
            x[0]=testresz[0].getPosition().x;
            y[0]=a4%720;
        }
        if (testresz[0].getPosition().y<0)
        {
            testresz[0].setPosition(testresz[0].getPosition().x,a5%720);
            x[0]=testresz[0].getPosition().x;
            y[0]=a5%720;
        }
*/
}

kigyo::~kigyo()
{

}

void kigyo::irany(int i)
{
    direction=i;
}

void kigyo::test()
{

    int n=x.size();
    veg.x=x[n-1];
    veg.y=y[n-1];
    for (int i=n-1;i>0;i--)
    {
 //       int a1=testresz[i].getPosition().x,a3=(102000-(0-testresz[i].getPosition().x)),a4=testresz[i].getPosition().y,a5=(72000-(0-testresz[i].getPosition().y));
        x[i]=testresz[i-1].getPosition().x;
        y[i]=testresz[i-1].getPosition().y;
        testresz[i].setPosition(testresz[i-1].getPosition().x,testresz[i-1].getPosition().y);
/*
        if (testresz[i].getPosition().x>1019)
        {
            testresz[i].setPosition(a1%1020,testresz[i].getPosition().y);
            x[i]=a1%1020;
            y[i]=testresz[i].getPosition().y;
        }
        if (testresz[i].getPosition().x<0)
        {
            testresz[i].setPosition(a3%1020,testresz[i].getPosition().y);
            x[i]=a3%1020;
            y[i]=testresz[i].getPosition().y;
        }
        if (testresz[i].getPosition().y>719)
        {
            testresz[i].setPosition(testresz[i].getPosition().x,a4%720);
            x[i]=testresz[i].getPosition().x;
            y[i]=a4%720;
        }
        if (testresz[i].getPosition().y<0)
        {
            testresz[i].setPosition(testresz[i].getPosition().x,a5%720);
            x[i]=testresz[i].getPosition().x;
            y[i]=a5%720;
        }
*/
    }
  //  std::cout<<x[2]<<" "<<y[2]<<std::endl;
    kigyohossz=n;
  //  std::cout<<n<<std::endl;
}

void kigyo::rajzolj(sf::RenderWindow& ablak)
{
    int kigyohossz=testresz.size();
  //  std::cout<<n<<std::endl<<std::endl<<std::endl;
    for (int i=0;i<kigyohossz;i++)
    {

        sf::Vector2f size;
        size.x=20;
        size.y=20;
        testresz[i].setSize(size);

        ablak.draw(testresz[i]);
   //     std::cout<<testresz[i].getPosition().x<<" "<<testresz[i].getPosition().y<<std::endl;
        ablak.draw(alma);
    }
/*    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setPosition(20,20);
    ablak.draw(rectangle); */
}

void kigyo::spawn()
{
    int rx,ry;
    sf::Vector2f size;
    size.x=20;
    size.y=20;
    srand(time(0));
    rx=(rand()%720);
    ry=(rand()%720);
    sf::RectangleShape gy;
    gy.setSize(size);
    gy.setPosition((rx-rx%20),(ry-ry%20));
    gy.setFillColor(sf::Color::Red);
    alma=gy;
}

void kigyo::bekaptae(bool kelle)
{

        if (x[0]==alma.getPosition().x && y[0]==alma.getPosition().y)
        {
            almab=false;

        if (kelle) sound.play();
   //         std::cout<<"sound played";
        }
}

void kigyo::novekszik()
{
    x.push_back(veg.x); y.push_back(veg.y);
    sf::RectangleShape c;
    c.setPosition(veg);
    testresz.push_back(c);
  //  std::cout<<veg.x<<" "<<veg.y<<std::endl;
    kigyohossz=x.size();
   // std::cout<<"asd"<<kigyohossz<<std::endl;
}

bool kigyo::raharapotte()
{
    bool ivn=false;
    kigyohossz=x.size();
    for (int i=1;i<kigyohossz;i++)
        if (x[i]==x[0] && y[i]==y[0]) ivn=true;
    return ivn;
}

void kigyo::keret()
{

    kigyohossz=x.size();
    for (int i=0;i<kigyohossz;i++)
    {
        int a1=testresz[i].getPosition().x,a3=(72000-(0-testresz[i].getPosition().x)),a4=testresz[i].getPosition().y,a5=(72000-(0-testresz[i].getPosition().y));
        if (testresz[i].getPosition().x>719)
        {
            testresz[i].setPosition(a1%720,testresz[i].getPosition().y);
            x[i]=a1%720;
            y[i]=testresz[i].getPosition().y;
        }
        if (testresz[i].getPosition().x<0)
        {
            testresz[i].setPosition(a3%720,testresz[i].getPosition().y);
            x[i]=a3%720;
            y[i]=testresz[i].getPosition().y;
        }
        if (testresz[i].getPosition().y>719)
        {
            testresz[i].setPosition(testresz[i].getPosition().x,a4%720);
            x[i]=testresz[i].getPosition().x;
            y[i]=a4%720;
        }
        if (testresz[i].getPosition().y<0)
        {
            testresz[i].setPosition(testresz[i].getPosition().x,a5%720);
            x[i]=testresz[i].getPosition().x;
            y[i]=a5%720;
        }
    }
}
