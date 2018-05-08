#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "console.h"
#include "DesignBrick.h"
#include "Draw.h"
#include "MoveBrick.h"
#include "In4Game.h"
#include <fstream>

class LogicGame:public Draw, public In4Game, public MoveBrick
{
public:
    LogicGame();
    virtual ~LogicGame();


    int LoopGame();

    void DrawGameOver(Thongtin, string);

    void nhapDuLieu(string, Thongtin);

protected:

private:
};

#endif // PLAYGAME_H
