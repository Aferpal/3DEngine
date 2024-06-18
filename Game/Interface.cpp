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
        s.setRotateOrigin({0, 0, 0});
        s.rotate(0.0, 0.0, 0.03);
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
    float resolutionX = this->window.getSize().x/2;
    float resolutionY = this->window.getSize().y/2;
    float resolution = resolutionX>resolutionY?resolutionY:resolutionX;
    for(int i = 0; i<3; i++){
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(tri[i].x*resolution, tri[i].y*resolution)),
            sf::Vertex(sf::Vector2f(tri[(i+1)%3].x*resolution, tri[(i+1)%3].y*resolution))
        };
        this->window.draw(line, 2, sf::Lines);
    }
}

bool Interface::shouldDrawShape(const Shape& s){
    return this->game.isShapeInLimits(s);
}