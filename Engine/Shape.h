#pragma once
#include"Triangle.h"
#include <iostream>
class Shape{
    Vector3d rotateOrigin;
    Matrix getRotationMatrixX(float);
    Matrix getRotationMatrixY(float);
    Matrix getRotationMatrixZ(float);
    public:
    
        std::vector<Triangle> faces;
        Shape(std::vector<Triangle>&);
        Shape(std::vector<Triangle>&&);
        void rotate(float, float, float);
        void rotateX(float);
        void rotateY(float);
        void rotateZ(float);
        void setRotateOrigin(const Vector3d&);
        void translate(const Vector3d&);
        void translate(float, float, float);
        friend std::ostream& operator<<(std::ostream&, Shape&);
        
};