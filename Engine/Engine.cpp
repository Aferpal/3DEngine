#include "Engine.h"

Engine::Engine(float angle, float zEnd, float zStart):viewAngle{angle}{
//normalizer{{{1/tanf(angle*0.5f), 0, 0, 0}, {0, 1/tanf(angle*0.5f), 0, 0}, {0,0,zEnd/(zEnd-zStart),zStart*zEnd/(zEnd-zStart)}, {0,0,1,0}}};
    normalizer.m.emplace_back(std::vector<float>{1/tanf(angle*0.5f), 0, 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0, 1/tanf(angle*0.5f), 0, 0});
    normalizer.m.emplace_back(std::vector<float>{0,0,zEnd/(zEnd-zStart),1});
    normalizer.m.emplace_back(std::vector<float>{0, 0, zStart*zEnd/(zEnd-zStart), 0});
}

Shape Engine::normalizeShape(const Shape& shape){
    Shape normalizedShape{{}};
    for(const Triangle& triangle:shape.faces){
        std::vector<Vector3d>tri;
        
        for(size_t i=0; i<3; i++){
            tri.emplace_back();
            tri[i]=triangle.points[i]*normalizer;
            if(triangle.points[i].z!=0){
                tri[i].x/=triangle.points[i].z;
                tri[i].y/=triangle.points[i].z;
                
            }
            tri[i].x=(tri[i].x+1.0f)*500;
            tri[i].y=(tri[i].y+1.0f)*500;
            
        }
        normalizedShape.faces.emplace_back(tri);
    }
    return normalizedShape;
}