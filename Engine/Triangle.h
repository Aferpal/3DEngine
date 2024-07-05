#pragma once
#include "Vector3d.h"
class Triangle{
    
    public:
        std::vector<Vector3d> points;
        Triangle(std::vector<Vector3d>);
        Triangle(const Triangle&);
        Triangle(Triangle&&);
        void operator=(const Triangle&);
        Vector3d& operator[](int i){
            return points[i%3];
        }
};