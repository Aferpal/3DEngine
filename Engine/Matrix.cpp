#include "Matrix.h"

Matrix::Matrix():m{0}{}

Matrix::Matrix(const std::vector<std::vector<float>>& m): m{m}{}

Matrix::Matrix(std::vector<std::vector<float>>&& m): m{m}{}

Matrix::Matrix(const Matrix& other): m{other.m}{}

std::vector<float> Matrix::operator[](int i) const{
    if(i>m.size()){
        return {0};
    }
    return m[i];
}


Matrix Matrix::operator*(const Matrix& other){
    Matrix mult;
    if (m[0].size() != other.size()) {
        Matrix error = Matrix{};
        return error;
    }

    for (size_t i = 0; i < m.size(); i++) {
        mult.m.emplace_back();
        for (size_t j = 0; j < other[i].size(); j++) {
            mult[i].emplace_back(0);
            for (size_t k = 0; k < m.size(); k++) {
                mult[i][j] += m[i][k] * other[k][j];
            }
        }
    }
    return mult;
}
void Matrix::operator*=(const Matrix& other){
    Matrix mult;
    if (m[0].size() != other.size()) {
        return;
    }

    for (size_t i = 0; i < m.size(); i++) {
        mult.m.emplace_back();
        for (size_t j = 0; j < other[i].size(); j++) {
            mult[i].emplace_back(0);
            for (size_t k = 0; k < m.size(); k++) {
                mult[i][j] += m[i][k] * other[k][j];
            }
        }
    }
    m=mult.m;
}