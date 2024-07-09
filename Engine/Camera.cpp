#include "Camera.h"

Camera::Camera()
    :viewAngle{90},position{0,0,0}, forwardDirection{0, 0, 1}, upDirection{0, 1, 0}, rightAxisDirection{1, 0, 0}, angleTangent{tanf(viewAngle/2)}, zEnd{10}, zStart{1}{
        normalizer.m.emplace_back(std::vector<float>{1/tanf(viewAngle*0.5f), 0, 0, 0});
        normalizer.m.emplace_back(std::vector<float>{0, 1/tanf(viewAngle*0.5f), 0, 0});
        normalizer.m.emplace_back(std::vector<float>{0,0,zEnd/(zEnd-zStart),1});
        normalizer.m.emplace_back(std::vector<float>{0, 0, zStart*zEnd/(zEnd-zStart), 0});
    }

Camera::Camera(float viewAngle, const Vector3d& position, float zStart, float zEnd)
    : viewAngle{viewAngle}, position{position}, angleTangent{tanf(viewAngle/2)},forwardDirection{0, 0, -1}, upDirection{0, 1, 0}, rightAxisDirection{-1, 0, 0}, zEnd{zEnd}, zStart{zStart}{
        normalizer.m.emplace_back(std::vector<float>{1/tanf(viewAngle*0.5f), 0, 0, 0});
        normalizer.m.emplace_back(std::vector<float>{0, 1/tanf(viewAngle*0.5f), 0, 0});
        normalizer.m.emplace_back(std::vector<float>{0,0,zEnd/(zEnd-zStart),1});
        normalizer.m.emplace_back(std::vector<float>{0, 0, zStart*zEnd/(zEnd-zStart), 0});
    }

Camera::Camera(const Camera& other) 
    :viewAngle{other.viewAngle}, position{other.position}, angleTangent{other.angleTangent}, zEnd{other.zEnd}, zStart{other.zStart}, forwardDirection{other.forwardDirection}, upDirection{other.upDirection}, rightAxisDirection{other.rightAxisDirection}, normalizer{other.normalizer}{}

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
    return v.z>zStart 
    && v.z<zEnd 
    && (abs(v.x/v.z)<angleTangent 
    &&  abs(v.y/v.z)<angleTangent);
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

void Camera::rotateY(float angle){
    forwardDirection.rotateY(angle);
    rightAxisDirection.rotateY(angle);
}

void Camera::rotateX(float angle){
    forwardDirection.rotateX(angle);
    upDirection.rotateX(angle);
}

void Camera::normalizeShape(Shape& shape){
    for(Triangle& triangle:shape.faces){
        for(Vector3d& v: triangle.points){
            v*=normalizer;
            if(v.q!=0){
                v.x/=v.q; v.y/=v.q;
            }
        }
    }
}

void Camera::getShapesNormalizedAndInCamera(const std::vector<Shape>& shape_vector, std::vector<Shape>& shape_vector_result){
    shape_vector_result.clear();
    for(const Shape& s: shape_vector){
        if(isShapeOnCamera(s)){
            shape_vector_result.emplace_back(s);
            normalizeShape(shape_vector_result.back());
        }
    }
};

void Camera::getShapesFitToCameraPositionAndAngle(const std::vector<Shape>& shape_vector, std::vector<Shape>& shape_vector_result){
    shape_vector_result = shape_vector;
    float transDotA = position.dotProduct(rightAxisDirection);
    float transDotB = position.dotProduct(upDirection);
    float transDotC = position.dotProduct(forwardDirection);
    for(Shape& s: shape_vector_result){
        for(Triangle& t : s.faces){
            for(Vector3d& v : t.points){
                float x, y, z;
                x = v.dotProduct(rightAxisDirection) - transDotA;
                y = -v.dotProduct(upDirection) + transDotB;
                z = v.dotProduct(forwardDirection) - transDotC;
                v.x =x;
                v.y =y;
                v.z=z;
            }
        }
    }
};