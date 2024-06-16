#pragma once
#include <vector>

class Matrix{
    protected:
        
    public:
        std::vector<std::vector<float>> m;
        Matrix();
        Matrix(const std::vector<std::vector<float>>& m);
        Matrix(std::vector<std::vector<float>>&& m);
        Matrix(const Matrix&);
        Matrix operator*(const Matrix&);
        void operator*=(const Matrix&);
        std::vector<float> operator[](int) const;
        int size() const {return m.size();};



};