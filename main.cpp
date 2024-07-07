#include "iostream"
#include "./Game/Interface.h"
# define M_PI  3.14159265358979323846  /* pi */


int main()
{   
    Game g{1, 20, (70*M_PI)/180};
    g.readShapeFromFilePath("./data/cube.txt");
    g.readShapeFromFilePath("./data/triangle.txt");
    g.readShapeFromFilePath("./data/cube2.txt");
    g.readShapeFromFilePath("./data/triangle2.txt");
    Interface i = {g, 1920, 1080};
    return 0;
}
