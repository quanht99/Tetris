#ifndef IPLAYER_H
#define IPLAYER_H
#include "IBrick.h"
#include "Check.h"

class IPlayer: public IBrick, public Check
{
public:
    IPlayer();
    virtual ~IPlayer();

    void moveLeft(Brick *pKhoiGach);
    /*
        dich khối gạch sang trái 1 đơn vị của trò chơi
    */

    void moveRight(Brick *pKhoiGach);
    /*
        dich khối gạch sang phải 1 đơn vị của trò chơi
    */
    int moveDown(Brick *pKhoiGach);
    /*
        dich khối gạch xuống dưới 1 đơn vị của trò chơi
    */
    void turnBrick(Brick* pKhoiGach);
    /*
        xoay khối gạch, biến khối gạch từ dạng dọc sang dạng ngang
    */



protected:

private:
};

#endif // MOVEBRICK_H
