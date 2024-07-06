#pragma once
#include "Shape.h"
class Camera{
    private:
        Vector3d position;
        float viewAngle;
        float angleTangent;
        float zEnd;
        float zStart;
    public:
        Camera();
        Camera(float, const Vector3d&, float, float);
        Camera(float, float, float);
        Camera(const Camera&);
        bool isShapeOnCamera(const Shape&);
        bool isTriangleOnCamera(const Triangle&);
        bool isVertexOnCamera(const Vector3d&);
        const Vector3d& getPosition();
        void moveTo(const Vector3d& v);
        void addToPosition(const Vector3d& v);
};