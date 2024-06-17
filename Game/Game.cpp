#include "Game.h"

Game::Game():rightLimit{5}, leftLimit{-5}, frontLimit{1}, backLimit{20}{

}

Game::Game(int sidesLimit, int fl, int bl):rightLimit{sidesLimit}, leftLimit{-sidesLimit}, frontLimit{fl}, backLimit{bl}{

}

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

Shape Game::getNormalizedShape(const Shape& s){
    return this->engine.normalizeShape(s);
};

bool Game::isShapeInLimits(const Shape& s){
    for(const Triangle& t: s.faces){
        for(const Vector3d& v : t.points){
           if(!isPointInLimits(v)){
            return false;
           }
        }
    }
    return true;
}

bool Game::isPointInLimits(const Vector3d& v){
    return !(v.x>rightLimit || v.x<leftLimit || v.z>backLimit || v.z<frontLimit);
}