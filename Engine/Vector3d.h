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
        bool validate(std::vector<float>);
        Vector3d operator*(const Matrix&) const;
        void operator=(const Vector3d &);
        float& operator[](int i)const;
};