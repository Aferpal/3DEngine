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

Vector3d Vector3d::operator*(const Matrix& matrix) const{
    std::vector<float> mult={x, y, z, q};
    std::vector<float> res;
    if (4 != matrix.size()) {
        Vector3d error = Vector3d{};
        return error;
    }
    for (size_t j = 0; j < matrix[0].size(); j++) {
        res.emplace_back(0);
        for (size_t k = 0; k < 4; k++) {
            res[j]+=( mult[k] * matrix[k][j] );
        }
    }
    Vector3d r={res[0], res[1], res[2], res[3]};
    return r;
}
void Vector3d::operator=(const Vector3d &other){
    x= other.x; y=other.y; z=other.z; q=other.q;

};

bool Vector3d::validate(std::vector<float> vec){
    return vec.size()==3;
}
