#include "Interface.h"

Interface::Interface(const Game& g, int size_x, int size_y): game{g}, window{sf::VideoMode(size_x, size_y), "SFML works!"}{
    this->window.setFramerateLimit(60);
    startGame();
}
void Interface::startGame(){
    int opcode = 0;
     while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                opcode = 0;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                opcode = 1;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                opcode = 2;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                opcode = 3;
            }
        }
        updateGame(opcode);
    }    
}

void Interface::drawGame(){
    std::vector<Shape> normalizedShapes;
    this->game.fillShapeVectorWithInScreenShapesNormalized(normalizedShapes);
    for(const Shape& s :normalizedShapes){
        drawShape(s);
    }
}

void Interface::drawShape(const Shape& s){
    for(auto tri:s.faces){
        scaleTriangle(tri);
        drawTriangle(tri);
    }
}

void Interface::scaleTriangle(Triangle& tri){
    float resolutionX = this->window.getSize().x/2;
    float resolutionY = this->window.getSize().y/2;
    float xFactor = resolutionX>=resolutionY ? (resolutionY/resolutionX) : 1;
    float yFactor = resolutionX>=resolutionY ? 1 : (resolutionX/resolutionY);
    for(Vector3d& v : tri.points){
        v.x = ((v.x * xFactor) + 1 ) * resolutionX;
        v.y = ((v.y * yFactor) + 1 ) * resolutionY;
    }
}

void Interface::drawTriangle(Triangle& tri){
    for(int i = 0; i<3; i++){
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(tri[i].x, tri[i].y)),
            sf::Vertex(sf::Vector2f(tri[(i+1)%3].x, tri[(i+1)%3].y))
        };
        this->window.draw(line, 2, sf::Lines);
    }
}


void Interface::updateGame(int actionCode){
    this->game.update(actionCode);
    window.clear();
    drawGame();
    window.display();
}