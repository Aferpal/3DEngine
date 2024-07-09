#pragma once
#include"Matrix.h"
#include<math.h>
class Vector3d{
    public:
        float x, y, z, q;
        //float realLength, lengthXY, lengthXZ, lengthZY;
        Vector3d();
        Vector3d(float, float, float, float=1.0f);
        Vector3d(const Vector3d&);
        Vector3d(Vector3d &&);
        void add(float, float, float);
        void add(const Vector3d&);
        bool validate(const std::vector<float>&);
        Vector3d& operator=(const Vector3d &);
        Vector3d& operator*=(const Matrix&);
        Vector3d& operator*=(float);
        Vector3d operator*(float);
        float dotProduct(const Vector3d&);
        Vector3d crossProduct(const Vector3d&);
        void rotateZ(float);
        void rotateY(float);
        void rotateX(float);
};