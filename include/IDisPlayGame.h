#ifndef IDisPlayGame_H
#define IDisPlayGame_H

#include <iostream>
#include "In4Game.h"
#include "IBrick.h"
#include "Check.h"
#include <ctime>
#include "fstream"


using namespace std;

class IDisPlayGame: public IBrick, public Check, public console
{
public:
    IDisPlayGame();
    virtual ~IDisPlayGame();

    void drawFrame();
    /*
        vẽ khung
    */

    void disPlayBoard();
    /*
        vẽ lại trạng thái trò chơi sau khi khối gạch rơi xuống xong
    */

    void drawBrick(Brick*); //
    /*
        vẽ khối gạch đó ra màn hình
    */

    void deleteBrick(Brick*);
    /*
        xóa khối gạch đó
    */

    void drawBrickNext(int ID);
    /*
        vẽ khối gạch tiếp theo sẽ được rơi xuống
    */

    void deleteBrickNext();
    /*
        xóa khối gạch tiếp theo
    */

    void drawHightScore();
    /*
        vẽ ra màn hình thông tin điểm cao đã được lưu vào file
    */
protected:

private:
};

#endif // IDisPlayGame_H
