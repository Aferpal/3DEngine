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
        }
        window.clear();
        drawGame();
        window.display();
    }    
}

void Interface::drawGame(){
    for(Shape& s : *(this->game.getFigures())){
        s.setRotateOrigin({0.5, 0.5, 3.5});
        s.rotate(0.0, 0.005, 0.0);
        if(shouldDrawShape(s)){
            drawShape(this->game.getNormalizedShape(s));
        }
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

bool Interface::shouldDrawShape(const Shape& s){
    return this->game.isShapeInLimits(s);
}