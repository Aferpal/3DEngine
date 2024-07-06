#include "Camera.h"

Camera::Camera()
    :viewAngle{90},position{0,0,0}, angleTangent{tan(viewAngle/2)}, zEnd{10}, zStart{1}{}

Camera::Camera(float viewAngle, const Vector3d& position, float zStart, float zEnd)
    : viewAngle{viewAngle}, position{position}, angleTangent{tan(viewAngle/2)}, zEnd{zEnd}, zStart{zStart}{}

Camera::Camera(const Camera& other) 
    :viewAngle{other.viewAngle}, position{other.position}, angleTangent{other.angleTangent}, zEnd{other.zEnd}, zStart{other.zStart}{}

Camera::Camera(float viewAngle, float zStart, float zEnd):Camera{viewAngle, Vector3d{0, 0, 0}, zStart, zEnd}{}

bool Camera::isShapeOnCamera(const Shape& s){
    for(const Triangle& t: s.faces){
        if(isTriangleOnCamera(t)){
            return true;
        }
    }
    return false;
}

bool Camera::isTriangleOnCamera(const Triangle& t){
    for(const Vector3d& v: t.points){
        if(isVertexOnCamera(v)){
            return true;
        }
    }
    return false;
}

bool Camera::isVertexOnCamera(const Vector3d& v){
    return (abs(v.x)<angleTangent &&  abs(v.y)<angleTangent) && v.z>zStart && v.z<zEnd;
};
