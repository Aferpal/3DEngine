#include <SFML/Graphics.hpp>
#include "iostream"
#include "Engine/Engine.h"


void drawTriangle(sf::RenderWindow& window, Triangle& tri){
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

    window.draw(line, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(line3, 2, sf::Lines);
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(60);
    float angleX=0.01, angleY=0.005, angleZ=0.02;


    Engine engine{90, 10, 1};
    Shape cube{
        std::vector<Triangle>{
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {1, 0, 0+3}, {1, 1, 0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0, 1, 0+3}, {1, 1, 0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0,0,1+3}, {0,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3},{0,1,0+3}, {0,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,0+3},{1,1,0+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,0+3},{0,1,1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,1+3}, {1, 0, 1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,1+3}, {0, 0, 1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {1,0,1+3}, {1, 1, 1+3}, {1,1,0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {1,0,1+3}, {1, 0, 0+3}, {1,1,0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {1, 0, 0+3}, {1,0,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0, 0, 1+3}, {1,0,1+3}
            }}
        }
    };


    cube.setRotateOrigin({0.5,0.5,3.5});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                angleX=0; angleY=0; angleZ=0;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                angleX=0.01; angleY=0.005; angleZ=0.02;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                angleX=-0.01; angleY=-0.005; angleZ=-0.02;
            }
            

        }

        window.clear();
        
        cube.rotate(angleX, angleY, angleZ);
        Shape normalCube=engine.display(cube);
        for(auto tri:normalCube.faces){
            drawTriangle(window, tri);
        }

       

        /*
        particle.updatePosition(source);

        source.render(window);
        particle.render(window);
        */
        window.display();
    }

    return 0;
}