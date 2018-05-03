#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "console.h"
#include "DesignBrick.h"
#include "Draw.h"
#include "MoveBrick.h"
#include "UpLoadGame.h"
#include "In4Game.h"



class LogicGame:public Draw, public In4Game, public MoveBrick
{
public:
    LogicGame();
    virtual ~LogicGame();


    int VongGame();

protected:

private:
};

#endif // PLAYGAME_H
