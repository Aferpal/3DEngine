#include "Interface.h"

Interface::Interface(const Game& g, int size_x, int size_y): window{sf::VideoMode(size_x, size_y), "SFML works!"}{
    this->game = g;
    this->window.setFramerateLimit(60);
    startGame();
}
void Interface::startGame(){

     while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                angleX=0; angleY=0; angleZ=0;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                angleX=0.01; angleY=0.005; angleZ=0.02;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                angleX=-0.01; angleY=-0.005; angleZ=-0.02;
            }*/
        }
        window.clear();
        drawGame();
        window.display();
    }    
}

void Interface::drawGame(){
    for(Shape& s : this->game.figures){
        s.rotate(0.01, 0, 0);
        drawShape(s);
    }
}

void Interface::drawShape(const Shape& s){
    for(auto tri:s.faces){
        drawTriangle(tri);
    }
}

void Interface::drawTriangle(Triangle& tri){
    sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(tri[0].x, tri[0].y)),
            sf::Vertex(sf::Vector2f(tri[1].x, tri[1].y))
        };
    sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(tri[1].x, tri[1].y)),
            sf::Vertex(sf::Vector2f(tri[2].x, tri[2].y))
        };
    sf::Vertex line3[] =
        {
            sf::Vertex(sf::Vector2f(tri[2].x, tri[2].y)),
            sf::Vertex(sf::Vector2f(tri[0].x, tri[0].y))
        };

    this->window.draw(line, 2, sf::Lines);
    this->window.draw(line2, 2, sf::Lines);
    this->window.draw(line3, 2, sf::Lines);
}