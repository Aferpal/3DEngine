#include "iostream"
#include "./Game/Interface.h"



int main()
{   
    Game g{1, 20, 70};
    g.readShapeFromFilePath("./data/cube.txt");
    g.readShapeFromFilePath("./data/triangle.txt");
    g.readShapeFromFilePath("./data/cube2.txt");
    g.readShapeFromFilePath("./data/triangle2.txt");
    Interface i = {g, 1920, 1080};
    return 0;
}
