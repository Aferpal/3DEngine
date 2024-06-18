#pragma once
#include "Shape.h"

class Engine{
    private:
        float viewAngle;
        Matrix normalizer;
    public:
        Engine(float, float, float);
        Shape normalizeShape(const Shape&);
        float getViewAngle() const;
};