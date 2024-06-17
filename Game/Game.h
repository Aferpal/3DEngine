#pragma once
#include"../Engine/Engine.h"
#include<fstream>
#include "../Exceptions/GameException.h"
#include<iostream>
#include<sstream>
class Game {
    private:
        void processLine(std::string* line);
    public:
        std::vector<Shape> figures;
        Engine engine {90, 10, 1};
        void readShapeFromFilePath(const std::string& filePath);
};