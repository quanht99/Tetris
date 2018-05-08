#ifndef DESIGN_BRICK_H
#define DESIGN_BRICK_H
#include <iostream>
#include<stdlib.h>
#include "ctime"

using namespace std;
//Luu hinh dang cua khoi gach
struct KhoiGach
{
    int **arr;
    int Row,Col;
    int iBoard,jBoard;
};

class DesignBrick
{
public:
    DesignBrick();
    virtual ~DesignBrick();

    KhoiGach *CreatBrick(int ID);

    void Delete_Object(KhoiGach* pkhoigach);

    int NumRandom();//random ra cac so tuong ung voi hinh dang ca khoi gach

protected:

private:
};
#endif // DESIGN_BRICK_H
