#ifndef MOVEBRICK_H
#define MOVEBRICK_H
#include "DesignBrick.h"
#include "Check.h"

class MoveBrick: public DesignBrick, public Check
{
public:
    MoveBrick();
    virtual ~MoveBrick();

    void SangTrai(KhoiGach *pkhoigach); //dich khối gạch sang trái

    void SangPhai(KhoiGach *pkhoigach); //dịch khối gạch sang phải

    int RoiXuong(KhoiGach *pkhoigach); //rơi xuống 1 ô;

    void XoayKhoiGach(KhoiGach* pkhoigach); // Xoay khoi gach



protected:

private:
};

#endif // MOVEBRICK_H
