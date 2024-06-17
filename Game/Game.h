#pragma once
#include"../Engine/Engine.h"
#include<fstream>
#include "../Exceptions/GameException.h"
#include<iostream>
#include<sstream>
class Game {
    private:
        void processLine(std::string* line);
        int backLimit;
        int leftLimit;
        int rightLimit;
        int frontLimit;
        std::vector<Shape> figures;
    public:
        Game();
        Game(int, int, int);
        std::vector<Shape>* getFigures() const;
        Engine engine {90, 10, 1};
        void readShapeFromFilePath(const std::string& filePath);
        Shape getNormalizedShape(const Shape& s);
        bool isShapeInLimits(const Shape& s);
        bool isPointInLimits(const Vector3d& v);
};