#include "iostream"
#include "./Game/Interface.h"



int main()
{   
    Game g;
    g.readShapeFromFilePath("./data/cube.txt");
    Interface i = {g, 1000, 1000};
    return 0;
}

/*Shape cube{
        std::vector<Triangle>{
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {1, 0, 0+3}, {1, 1, 0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0, 1, 0+3}, {1, 1, 0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0,0,1+3}, {0,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3},{0,1,0+3}, {0,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,0+3},{1,1,0+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,0+3},{0,1,1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,1+3}, {1, 0, 1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,1,1+3}, {0, 0, 1+3}, {1,1,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {1,0,1+3}, {1, 1, 1+3}, {1,1,0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {1,0,1+3}, {1, 0, 0+3}, {1,1,0+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {1, 0, 0+3}, {1,0,1+3}
            }},
            Triangle{std::vector<Vector3d>{
                {0,0,0+3}, {0, 0, 1+3}, {1,0,1+3}
            }}
        }
    };*/