#include "Engine.h"

Engine::Engine(float angle, float zEnd, float zStart):viewAngle{angle}{
//normalizer{{{1/tanf(angle*0.5f), 0, 0, 0}, {0, 1/tanf(angle*0.5f), 0, 0}, {0,0,zEnd/(zEnd-zStart),zStart*zEnd/(zEnd-zStart)}, {0,0,1,0}}};
    normalizer.m.emplace_back(std::vector<float>{1/tanf(angle*0.5f), 0, 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0, 1/tanf(angle*0.5f), 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0,0,zEnd/(zEnd-zStart),1});
    normalizer.m.emplace_back(std::vector<float>{0, 0, zStart*zEnd/(zEnd-zStart), 0});
}

Shape Engine::normalizeShape(const Shape& shape){
    Shape normalizedShape{shape.faces};
    for(Triangle& triangle:normalizedShape.faces){
        for(Vector3d& v: triangle.points){
            v*=normalizer;
            if(v.q!=0){
                v.x/=v.q; v.y/=v.q;
            }
        }
    }
    return normalizedShape;
}

float Engine::getViewAngle() const {
    return this->viewAngle;
}