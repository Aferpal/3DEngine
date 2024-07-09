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
};