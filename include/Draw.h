#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "In4Game.h"
#include "DesignBrick.h"
#include "Check.h"
#include <ctime>
#include "fstream"


using namespace std;

class Draw: public DesignBrick, public Check, public console
{
public:
    Draw();
    virtual ~Draw();

    void DrawFrame();

    void DisplayBoard();

    void DrawBrick(KhoiGach*);

    void DeleteBrick(KhoiGach*);

    void DrawBrick_Next(int ID);

    void DeleteBrick_Next();

    void DrawHightScore();

protected:

private:
};

#endif // DRAW_H
