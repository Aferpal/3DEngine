#include <SFML/Graphics.hpp>
#include "./Game.h"

class Interface{
    private:
        Game game;
        sf::RenderWindow window;
    public:
        Interface(const Game& g, int, int);
        void startGame();
        void drawGame();
        void drawShape(const Shape& s);
        void drawTriangle(Triangle& tri);
};