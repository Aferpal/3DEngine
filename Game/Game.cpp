#include "Game.h"

void Game::readShapeFromFilePath(const std::string& path){
    std::ifstream in_file {path};
    if(!in_file){
        throw GameException("Error trying to read shapes data from file");
    }
    std::string line;
    this->figures.emplace_back();
    while(in_file>>line){
        try{
            processLine(line);
        }catch (std::exception& e){
            std::cout<<"Exception while reading from file "<<path<<e.what()<<'\n';
        }
    }
}

void Game::processLine(const std::string& line){
    std::stringstream stringStreamForTriangleData (line);
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