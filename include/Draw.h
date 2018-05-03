#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "In4Game.h"
#include "DesignBrick.h"
#include "Check.h"
#include <ctime>


using namespace std;

class Draw: public DesignBrick, public Check, public console
{
public:
    Draw();
    virtual ~Draw();

    void VeKhung();
    void DisplayBoard();
    void VeKhoiGach(KhoiGach*);
    void XoaKhoiGach(KhoiGach*);
    void Ve_Next(int ID);
    void Xoa_Next();
protected:

private:
};

#endif // DRAW_H
