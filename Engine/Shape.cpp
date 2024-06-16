#include "Shape.h"


Shape::Shape(std::vector<Triangle>&& other):faces{other}, rotateOrigin{0,0,0}{

}

Shape::Shape(std::vector<Triangle>& other):faces{other}, rotateOrigin{0,0,0}{

}
void Shape::setRotateOrigin(const Vector3d& vec){rotateOrigin=vec;};


void Shape::rotate(float angleX, float angleY, float angleZ){

    for(auto& face : faces){
        for(auto& vector : face.points){
            vector.add(-rotateOrigin.x, -rotateOrigin.y, -rotateOrigin.z);
            vector = vector*getRotationMatrixX(angleX);
            vector = vector*getRotationMatrixY(angleY);
            vector = vector*getRotationMatrixZ(angleZ);
            vector.add(rotateOrigin.x, rotateOrigin.y, rotateOrigin.z);
        }
    }
};
void Shape::rotateX(float angle){
    for(auto&tri : faces){
        for(auto& vec:tri.points){
            vec.add(-rotateOrigin.x, -rotateOrigin.y, -rotateOrigin.z);
            vec=vec*getRotationMatrixX(angle);
            vec.add(rotateOrigin.x, rotateOrigin.y, rotateOrigin.z);
        }
    }
};
void Shape::rotateY(float angle){
    for(auto&tri:faces){
        for(auto& vec:tri.points){
            vec.add(-rotateOrigin.x, -rotateOrigin.y, -rotateOrigin.z);
            vec=vec*getRotationMatrixY(angle);
            vec.add(rotateOrigin.x, rotateOrigin.y, rotateOrigin.z);
        }
    }
};
void Shape::rotateZ(float angle){
    for(auto&tri:faces){
        for(auto& vec:tri.points){
            vec.add(-rotateOrigin.x, -rotateOrigin.y, -rotateOrigin.z);
            vec=vec*getRotationMatrixZ(angle);
            vec.add(rotateOrigin.x, rotateOrigin.y, rotateOrigin.z);
        }
    }
};

Matrix Shape::getRotationMatrixX(float angle){
    return {
        {
            {cosf(angle), sinf(angle), 0, 0}, 
            {-sinf(angle), cosf(angle), 0, 0}, 
            {0,0,1,0}, 
            {0,0,0,1}
        }
    };
};
Matrix Shape::getRotationMatrixY(float angle){
    return {
        {
            {1, 0, 0, 0}, 
            {0, cosf(angle), -sinf(angle), 0}, 
            {0,sinf(angle),cosf(angle),0}, 
            {0,0,0,1}
        }
    };
};
Matrix Shape::getRotationMatrixZ(float angle){
    return {
        {
            {cosf(angle), 0, sinf(angle), 0}, 
            {0, 1, 0, 0}, 
            {-sinf(angle),0,cosf(angle),0}, 
            {0,0,0,1}
        }
    };
};


void Shape::translate(float x, float y, float z){
    for(auto& tri:faces){
        for(auto& vec:tri.points){
            vec.add(x, y, z);
        }
    }
};

void Shape::translate(const Vector3d& v){
    translate(v.x, v.y, v.z);
};
