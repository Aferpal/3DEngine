#include "Camera.h"

Camera::Camera()
    :viewAngle{90},position{0,0,0}, forwardDirection{0, 0, 1}, upDirection{0, 1, 0}, rightAxisDirection{1, 0, 0}, angleTangent{tanf(viewAngle/2)}, zEnd{10}, zStart{1}{}

Camera::Camera(float viewAngle, const Vector3d& position, float zStart, float zEnd)
    : viewAngle{viewAngle}, position{position}, angleTangent{tanf(viewAngle/2)},forwardDirection{0, 0, 1}, upDirection{0, 1, 0}, rightAxisDirection{1, 0, 0}, zEnd{zEnd}, zStart{zStart}{
        std::cout<<viewAngle<<" "<<angleTangent<<'\n';
    }

Camera::Camera(const Camera& other) 
    :viewAngle{other.viewAngle}, position{other.position}, angleTangent{other.angleTangent}, zEnd{other.zEnd}, zStart{other.zStart}, forwardDirection{other.forwardDirection}, upDirection{other.upDirection}, rightAxisDirection{other.rightAxisDirection}{}

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
    Vector3d relativePositionOfVectorAndCamera = this->position;
    relativePositionOfVectorAndCamera*=-1;
    relativePositionOfVectorAndCamera.add(v);
    return relativePositionOfVectorAndCamera.z>zStart 
    && relativePositionOfVectorAndCamera.z<zEnd 
    && (abs(relativePositionOfVectorAndCamera.x/relativePositionOfVectorAndCamera.z)<angleTangent 
    &&  abs(relativePositionOfVectorAndCamera.y/relativePositionOfVectorAndCamera.z)<angleTangent);
};

const Vector3d& Camera::getPosition(){
    return this->position;
}

void Camera::moveTo(const Vector3d& v){
    this->position = v;
}
void Camera::addToPosition(const Vector3d& v){
    this->position.add(v.x, v.y, v.z);
}

void Camera::moveForward(float scalar){
    this->position.add(this->forwardDirection*scalar);
}

void Camera::moveBackwards(float scalar){
    this->position.add(this->forwardDirection*(-scalar));
}

void Camera::moveRight(float scalar){
    this->position.add(this->rightAxisDirection*scalar);
}

void Camera::moveLeft(float scalar){
    this->position.add(this->rightAxisDirection*(-scalar));
}


void Camera::moveUp(float scalar){
    this->position.add(this->upDirection*scalar);
}

void Camera::moveDown(float scalar){
    this->position.add(this->upDirection*(-scalar));
}
