#include "Vector3d.h"
Vector3d::Vector3d():x{0}, y{0}, z{0}{}
Vector3d::Vector3d(float x, float y, float z, float q): x{x}, y{-y}, z{z}, q{q}{
    
 }
Vector3d::Vector3d(const Vector3d& other):x{other.x}, y{other.y}, z{other.z}, q{other.q}{
}
Vector3d::Vector3d(Vector3d && other): x{other.x}, y{-other.y}, z{other.z}, q{other.q}{
};
void Vector3d::add(float a, float b, float c){
    x+=a; y+=b; z+=c;
}

void Vector3d::add(const Vector3d& v){
    add(v.x, v.y, v.z);
}

Vector3d& Vector3d::operator*=(const Matrix& matrix){
    if (matrix.size() != 4 || matrix[0].size()!=4) {
        return *this;
    }
    x = x*matrix[0][0] + y*matrix[1][0] + z*matrix[2][0] + q*matrix[3][0];
    y = x*matrix[0][1]+ y*matrix[1][1] + z*matrix[2][1] + q*matrix[3][1];
    z = x*matrix[0][2] + y*matrix[1][2] + z*matrix[2][2] + q*matrix[3][2];
    q = x*matrix[0][3] + y*matrix[1][3] + z*matrix[2][3] + q*matrix[3][3];
    return *this;
}
Vector3d& Vector3d::operator=(const Vector3d &other){
    x= other.x; y=other.y; z=other.z; q=other.q;
    return *this;
};

Vector3d& Vector3d::operator*=(float scalar){
    this->x*=scalar;
    this->y*=scalar;
    this->z*=scalar;
    return *this;
}

bool Vector3d::validate(const std::vector<float>& vec){
    return vec.size()==3;
}

Vector3d Vector3d::operator*(float scalar){
    return {x*scalar, y*scalar, z*scalar, q};
}

float Vector3d::dotProduct(const Vector3d& v){
    return (x*v.x) + (y*v.y) + (z*v.z);
}

Vector3d Vector3d::crossProduct(const Vector3d& v){
    float resultX = y*v.z - z*v.y;
    float resultY = z*v.x - x*v.z;
    float resultZ = x*v.y - y*v.x;
    return {resultX, resultY, resultZ};
}

void Vector3d::rotateY(float angle){
    float cos = cosf(angle);
    float sin = sinf(angle);
    float nx, nz;
    nx = x * cos - z * sin;
    nz = x * sin + z * cos;
    x = nx;
    z = nz;
}

void Vector3d::rotateX(float angle){
    float cos = cosf(angle);
    float sin = sinf(angle);
    float ny, nz;
    ny = y * cos + z * sin;
    nz =  - y * sin + z * cos;
    y = ny;
    z = nz;
}