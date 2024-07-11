#include "Engine.h"

Engine::Engine(float angle, float zStart, float zEnd):camera{angle, Vector3d{0,2,0}, zStart, zEnd}{
//normalizer{{{1/tanf(angle*0.5f), 0, 0, 0}, {0, 1/tanf(angle*0.5f), 0, 0}, {0,0,zEnd/(zEnd-zStart),zStart*zEnd/(zEnd-zStart)}, {0,0,1,0}}};
}


void Engine::getShapesNormalizedAndInCamera(const std::vector<Shape>& shape_vector, std::vector<Shape>& shape_vector_result){
    std::vector<Shape> shapesMovedToCamera;
    camera.getShapesFitToCameraPositionAndAngle(shape_vector, shapesMovedToCamera);
    camera.getShapesNormalizedAndInCamera(shapesMovedToCamera, shape_vector_result);
};

void Engine::moveCamera(const Vector3d& v){
    this->camera.addToPosition(v);
}

void Engine::rotate(float angle){
    this->camera.rotateY(angle);
}

void Engine::moveRight(float s){
    camera.moveRight(s);
}
void Engine::moveLeft(float s){
    camera.moveLeft(s);
}
void Engine::moveForward(float s){
    camera.moveForward(s);
}
void Engine::moveBackwards(float s){
    camera.moveBackwards(s);
}