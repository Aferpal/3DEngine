#include "Game.h"

Game::Game()
    :Game(1, 20, 90){}

Game::Game(float frontLimit, float backLimit, float cameraViewAngle)
    :frontLimit{frontLimit}, backLimit{backLimit}, engine{cameraViewAngle, frontLimit, backLimit}{}

void Game::readShapeFromFilePath(const std::string& path){
    std::ifstream in_file {path};
    if(!in_file){
        throw GameException("Error trying to read shapes data from file");
    }
    std::string line;
    this->figures.emplace_back();
    while(in_file>>line){
        try{
            processLine(&line);
        }catch (std::exception& e){
            std::cout<<"Exception while reading from file "<<path<<e.what()<<'\n';
        }
    }
}

void Game::processLine(std::string* line){
    std::stringstream stringStreamForTriangleData (*line);
    std::string triangleData, vertexData;
    std::vector<Vector3d> triangleValues;
    Vector3d v;
    while(std::getline(stringStreamForTriangleData, triangleData, ';')){
        std::stringstream stringStreamForVertexData(triangleData);
        std::getline(stringStreamForVertexData, vertexData, ',');
        v.x= std::stof(vertexData);
        std::getline(stringStreamForVertexData, vertexData, ',');
        v.y = -std::stof(vertexData);
        std::getline(stringStreamForVertexData, vertexData, ',');
        v.z = std::stof(vertexData);
        triangleValues.emplace_back(v);
    }
    
    Triangle tr (triangleValues);
    this->figures.back().faces.emplace_back(tr);
}

std::vector<Shape>* Game::getFigures() const{
    return (std::vector<Shape>*)&figures;
};

void Game::fillShapeVectorWithInScreenShapesNormalized(std::vector<Shape>& v){
    this->engine.getShapesNormalizedAndInCamera(this->figures, v);
};

void Game::update(int actionCode){
    if(actionCode == 6){return;}
    if(actionCode>=0 && actionCode <=3){
        moveAll(actionCode);
    }else if(actionCode == 4){
        this->engine.rotate(-0.01);
    }else if(actionCode == 5){
        this->engine.rotate(0.01);
    }
}
void Game::moveAll(int direction){
    Vector3d directionVector{0,0,0};
    switch (direction)
        {
        case 0:
            engine.moveForward(0.05);
            break;
        case 1:
            engine.moveBackwards(0.05);
            break;
        case 2: 
            engine.moveRight(0.05);
            break;
        case 3:
            engine.moveLeft(0.05);
            break;
        default:
            break;
        }
}

