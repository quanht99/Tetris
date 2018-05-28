#ifndef IN4GAME_H
#define IN4GAME_H
#include <iostream>
#include "IBrick.h"
#include "Check.h"

#include "upLoadGame.h"
#include "console.h"
#include <MMSystem.h>


using namespace std;

struct in4Game
{
    int level;
    int score;
};

struct in4Player
{
    string name;
    int score;
};


class In4Game:public upLoadGame,public console
{
public:
    In4Game();
    virtual ~In4Game();

    int checkGame(Brick *pkhoigach,in4Game *infogame) ;
    /*
        kiểm tra xem có hàm nào ăn được hay k
    */

    void creatIn4Game(in4Game *info);
    /*
        Khởi tạo thông tin cho trò chơi
    */

    void drawScore(in4Game infor);
    /*
        Vẽ ra thông tin về điểm số của người chơi
    */

    bool upDateScore(in4Game *info, int score);
    /*
        cập nhật điểm số sau khi 1 hàng nào đó được ăn
    */

protected:

private:
};

#endif // IN4GAME_H
