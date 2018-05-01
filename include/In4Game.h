#ifndef IN4GAME_H
#define IN4GAME_H
#include <iostream>
#include "DesignBrick.h"
#include "Check.h"

#include "UpLoadGame.h"
#include "console.h"

using namespace std;

struct Thongtin{
    int level;
    int score;
};


class In4Game:public UpLoadGame,public console
{
    public:
        In4Game();
        virtual ~In4Game();

        int KiemTra(KhoiGach *pkhoigach,Thongtin *infogame) ;

        void CreatIn4(Thongtin *info);

        void DrawScore(Thongtin infor);

        bool capnhat(Thongtin *info, int score);

    protected:

    private:
};

#endif // IN4GAME_H
