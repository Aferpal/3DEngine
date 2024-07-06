#pragma once
#include"../Engine/Engine.h"
#include<fstream>
#include "../Exceptions/GameException.h"
#include<iostream>
#include<sstream>
class Game {
    private:
        void processLine(std::string* line);
        float backLimit;
        float frontLimit;
        std::vector<Shape> figures;
        Engine engine;
    private:
        void moveAll(int);
    public:
        Game();
        Game(float, float, float);
        std::vector<Shape>* getFigures() const;
        void readShapeFromFilePath(const std::string& filePath);
        void fillShapeVectorWithInScreenShapesNormalized(std::vector<Shape>& v);
        void update(int);
};