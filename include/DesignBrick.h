#ifndef DESIGN_BRICK_H
#define DESIGN_BRICK_H

#include<stdlib.h>
#include "ctime"

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

    KhoiGach *TaoKhoiGach(int ID);

    void HuyKhoiGach(KhoiGach* pkhoigach);

    int Loai();

protected:

private:
};
#endif // DESIGN_BRICK_H
