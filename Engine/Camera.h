#pragma once
#include "Shape.h"
class Camera{
    private:
        Vector3d position;
        Vector3d forwardDirection;
        Vector3d rightAxisDirection;
        Vector3d upDirection;
        float viewAngle;
        Matrix normalizer;
        Matrix rotateTranslateMatrix;
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
        void moveRight(float);
        void moveLeft(float);
        void moveForward(float);
        void moveBackwards(float);
        void moveUp(float);
        void moveDown(float);
        void rotateY(float);
        void rotateX(float);
        void getShapesNormalizedAndInCamera(const std::vector<Shape>&, std::vector<Shape>&);
        void getShapesFitToCameraPositionAndAngle(const std::vector<Shape>&, std::vector<Shape>&);
        void normalizeShape(Shape&);
        
};