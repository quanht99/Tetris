#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "console.h"
#include "DesignBrick.h"
#include "Check.h"

using namespace std;

class Draw: public console, public DesignBrick, public Check
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
