#include "Triangle.h"

Triangle::Triangle(std::vector<Vector3d> p):points{p}{}
Triangle::Triangle(const Triangle& other){
    points=other.points;
}
Triangle::Triangle(Triangle&& other): Triangle(other.points){}
void Triangle::operator=(const Triangle& other){
    this->points.reserve(other.points.size());
    for(int i=0; i<this->points.size(); i++){
        this->points.emplace_back(other.points[i]);
    }
};