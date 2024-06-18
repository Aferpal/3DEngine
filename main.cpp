#include "iostream"
#include "./Game/Interface.h"



int main()
{   
    Game g;
    g.readShapeFromFilePath("./data/cube.txt");
    g.readShapeFromFilePath("./data/triangle.txt");
    g.readShapeFromFilePath("./data/cube2.txt");
    g.readShapeFromFilePath("./data/triangle2.txt");
    Interface i = {g, 1000, 1000};
    return 0;
}
