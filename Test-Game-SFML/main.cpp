//#include <SFML/Color.hpp>

//#include "personnage.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <stack>
using namespace std;
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>



const int w = 1250;
const int h = 700;
const int pas_cases = 50;
const int nb_cases_h = h/pas_cases;
const int nb_cases_w = w/pas_cases;


void dessinHerbe(sf::RenderWindow *fenetre, sf::Texture t)
{
    sf::Sprite s(t);
    s.setScale(w,h);
    fenetre->draw(s);
    for(int j=0; j<nb_cases_w; j++)
    {
        // Lignes verticales
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(j*pas_cases,0),sf::Color::White),
            sf::Vertex(sf::Vector2f(j*pas_cases,h-1),sf::Color::White)
        };
        fenetre->draw(line, 4, sf::Lines);
    }

    for(int i=0; i<nb_cases_h; i++)
    {
        // Lignes horizontales
        sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(0,i*pas_cases),sf::Color::White),
            sf::Vertex(sf::Vector2f(w-1, i*pas_cases),sf::Color::White)
        };
        fenetre->draw(line2, 4, sf::Lines);
    }
    //fenetre->display();
}

void dessinMvt(sf::Sprite *sprite)
{
    sf::Vector2f pos = sprite->getPosition();
}

float norm(sf::Vector2i v1, sf::Vector2i v2)
{
    return abs(v1.x-v2.x) + abs(v1.y-v2.y);
}

struct noeud{
    float cout_g, cout_h, cout_f;
    sf::Vector2i parent;    // 'adresse' du parent (qui sera toujours dans la map fermée)
};

bool deja_present_dans_liste(sf::Vector2i v,)
{

}
void AstarAlgo(sf::Vector2i init)
{
    // Vecteur des cases du chemin minimal
    vector<sf::Vector2i> v_cases;
    vector<sf::Vector2i> v_chemin;
    v_cases.push_back(init);
}

void getCase(int& i, int& j,sf::Vector2i vect)
{
    while(i<vect.x)
    {
        i+=pas_cases;
    }
    while(j<vect.y)
    {
        j+=pas_cases;
    }
    i -= pas_cases;
    j -= pas_cases;
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(w,h), "SFML window");
    // Load a sprite to display
    sf::Texture texture,texture2;
    if (!texture.loadFromFile("images/textureforetscaled2.png"))
        return EXIT_FAILURE;
    /*
    sf::Sprite sprite(texture);
    sprite.setScale(w,h);
    */

    if (!texture2.loadFromFile("images/Personnage/1.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite2(texture2);
    sprite2.setPosition(50 ,40);
    sprite2.setScale(1,1);
    int compteur = 0;
    sf::Texture jaune;
    if (!jaune.loadFromFile("images/textureforetdeplacement.png"))
        return EXIT_FAILURE;
    sf::Sprite sp(jaune);
    sp.setScale(1,1);
    int i=0;
    int j=0;
    sf::Vector2i vect;
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        /*
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && compteur == 0)
        {
            texture2.loadFromFile("images/Personnage/droited.png");
            sprite2.setTexture(texture2);
            sprite2.setPosition(sprite2.getPosition() + sf::Vector2f(3,0));
            window.clear();
            dessinHerbe(&window,texture);
            window.draw(sp);
            window.draw(sprite2);
            compteur++;
        }
        sf::sleep(sf::milliseconds(50));
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && compteur ==1)
        {
            texture2.loadFromFile("images/Personnage/droiteg.png");
            sprite2.setTexture(texture2);
            sprite2.setPosition(sprite2.getPosition() + sf::Vector2f(3,0));
            window.clear();
            dessinHerbe(&window,texture);
            window.draw(sprite2);
            window.display();
            compteur = 0;
        }
        dessinHerbe(&window,texture);
        window.draw(sprite2);
        window.display();

        sf::sleep(sf::milliseconds(50));
        texture2.loadFromFile("images/Personnage/3.png");
        sprite2.setTexture(texture2);
        window.clear();
        dessinHerbe(&window,texture);
        window.draw(sprite2);
        window.display();
        sf::Vector2i choix = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            std::cout << position.x << " " << position.y << std::endl;
            sprite2.setPosition(position.x,position.y);
            window.clear();
            window.draw(sprite);
            window.draw(sprite2);
            window.display();
        }*/

        // AFFICHAGE :

        window.clear();
        dessinHerbe(&window,texture);
        vect = sf::Mouse::getPosition(window);
        getCase(i,j,vect);
        sp.setPosition(i+1,j+1);
        window.draw(sp);
        window.draw(sprite2);
        window.display();
        //sf::sleep(sf::milliseconds(10));

    }
    return EXIT_SUCCESS;
}
