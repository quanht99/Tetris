#ifndef IN4GAME_H
#define IN4GAME_H
#include <iostream>
#include "DesignBrick.h"
#include "Check.h"

#include "UpLoadGame.h"
#include "console.h"

using namespace std;

struct Thongtin
{
    int level;
    int score;
};

struct In4Player
{
    string name;
    int score;
};


class In4Game:public UpLoadGame,public console
{
public:
    In4Game();
    virtual ~In4Game();

    int CkeckGame(KhoiGach *pkhoigach,Thongtin *infogame) ;

    void CreatIn4(Thongtin *info);

    void DrawScore(Thongtin infor);

    bool UpDateScore(Thongtin *info, int score);

protected:

private:
};

#endif // IN4GAME_H
