#pragma once
#include "Vector3d.h"
class Triangle{
    
    public:
        std::vector<Vector3d> points;
        Triangle(std::vector<Vector3d>);
        Triangle(const Triangle&);
        Triangle(Triangle&&);
        Vector3d& operator[](int i){
            if(i>2){
                return points[0];
            }
            return points[i];
        }
};