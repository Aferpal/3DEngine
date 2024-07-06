#pragma once
#include "Shape.h"
#include "Camera.h"
class Engine{
    private:
        float viewAngle;
        Matrix normalizer;
        Camera camera;
    public:
        Engine(float, float, float);
        void normalizeShape(Shape&);
        float getViewAngle() const;
        void getShapesNormalizedAndInCamera(const std::vector<Shape>&, std::vector<Shape>&);
};