#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "console.h"
#include "DesignBrick.h"
#include "Draw.h"
#include "MoveBrick.h"
#include "UpLoadGame.h"
#include "In4Game.h"


class PlayGame:public Draw, public In4Game, public MoveBrick
{
    public:
        PlayGame();
        virtual ~PlayGame();


        int VongGame();

    protected:

    private:
};

#endif // PLAYGAME_H
