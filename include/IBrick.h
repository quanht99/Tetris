#ifndef IBRICK_H
#define IBRICK_H
#include <iostream>
#include<stdlib.h>
#include "ctime"

using namespace std;
//Luu hinh dang cua khoi gach
struct Brick
{
    int **arr;
    int Row,Col;
    int iBoard,jBoard;
};

class IBrick
{
public:
    IBrick();
    virtual ~IBrick();

    Brick *creatBrick(int ID);
    /*
        tạo hình dạng cho khối gạch đó
    */
    void deleteObject(Brick* pkhoigach);
    /*
        xóa khối gạch đó
    */

    int numRanDom();
    /*
        random ra cac so tuong ung voi hinh dang ca khoi gach
    */

protected:

private:
};
#endif // DESIGN_BRICK_H
