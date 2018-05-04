#ifndef MOVEBRICK_H
#define MOVEBRICK_H
#include "DesignBrick.h"
#include "Check.h"

class MoveBrick: public DesignBrick, public Check
{
public:
    MoveBrick();
    virtual ~MoveBrick();

    void moveLeft(KhoiGach *pkhoigach); //dich khối gạch sang trái

    void moveRight(KhoiGach *pkhoigach); //dịch khối gạch sang phải

    int moveDown(KhoiGach *pkhoigach); //rơi xuống 1 ô;

    void turnBrick(KhoiGach* pkhoigach); // Xoay khoi gach



protected:

private:
};

#endif // MOVEBRICK_H
