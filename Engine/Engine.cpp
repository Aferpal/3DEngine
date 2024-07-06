#include "Engine.h"

Engine::Engine(float angle, float zStart, float zEnd):viewAngle{angle}, camera{angle, Vector3d{0,0,0}, zStart, zEnd}{
//normalizer{{{1/tanf(angle*0.5f), 0, 0, 0}, {0, 1/tanf(angle*0.5f), 0, 0}, {0,0,zEnd/(zEnd-zStart),zStart*zEnd/(zEnd-zStart)}, {0,0,1,0}}};
    normalizer.m.emplace_back(std::vector<float>{1/tanf(angle*0.5f), 0, 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0, 1/tanf(angle*0.5f), 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0,0,zEnd/(zEnd-zStart),1});
    normalizer.m.emplace_back(std::vector<float>{0, 0, zStart*zEnd/(zEnd-zStart), 0});
}

void Engine::normalizeShape(Shape& shape){
    for(Triangle& triangle:shape.faces){
        for(Vector3d& v: triangle.points){
            v*=normalizer;
            if(v.q!=0){
                v.x/=v.q; v.y/=v.q;
            }
        }
    }
}

float Engine::getViewAngle() const {
    return this->viewAngle;
}

void Engine::getShapesNormalizedAndInCamera(const std::vector<Shape>& shape_vector, std::vector<Shape>& shape_vector_result){
    shape_vector_result.clear();
    for(const Shape& s: shape_vector){
        if(camera.isShapeOnCamera(s)){
            shape_vector_result.emplace_back(s);
            normalizeShape(shape_vector_result.back());
        }
    }
};