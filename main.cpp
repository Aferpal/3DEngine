#include "iostream"
#include "./Game/Interface.h"



int main()
{   
    Game g;
    g.readShapeFromFilePath("./data/cube.txt");
    g.readShapeFromFilePath("./data/triangle.txt");
    Interface i = {g, 1000, 1000};
    return 0;
}
