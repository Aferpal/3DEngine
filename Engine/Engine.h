#pragma once
#include "Shape.h"
#include "Camera.h"
class Engine{
    private:
        Camera camera;
    public:
        Engine(float, float, float);
        void getShapesNormalizedAndInCamera(const std::vector<Shape>&, std::vector<Shape>&);
        void moveCamera(const Vector3d& v);
        void rotateY(float);
        void rotateX(float);
        void moveRight(float);
        void moveLeft(float);
        void moveForward(float);
        void moveBackwards(float);
};