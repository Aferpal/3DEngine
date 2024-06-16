#include "Triangle.h"

Triangle::Triangle(std::vector<Vector3d> p):points{p}{}
Triangle::Triangle(const Triangle& other){
    points=other.points;
}
Triangle::Triangle(Triangle&& other): Triangle(other.points){}