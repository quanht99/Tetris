#ifndef LOGICGAME_H
#define LOGICGAME_H
#include "console.h"
#include "IBrick.h"
#include "IDisPlayGame.h"
#include "IPlayer.h"
#include "In4Game.h"
#include <fstream>


class logicGame:public IDisPlayGame, public In4Game, public IPlayer
{
public:
    logicGame();
    virtual ~logicGame();


    int loopGame();
    /*
        cách thức hoạt động của game. Dùng để chơi game nhiều lần mà không cần thoát ra chạy lại
    */

    void DrawGameOver(in4Game, string);
    /*
        In ra thông báo trò chơi đã kết thúc
    */

    void takeData(string, in4Game);
    /*
        Lấy thông tin gồm tên và điểm số của người chơi sau khi bị game over
    */

protected:

private:
};

#endif // LOGICGAME_H
