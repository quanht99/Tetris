#ifndef UPLOADGAME_H
#define UPLOADGAME_H
#include "Check.h"
#include "IBrick.h"


class upLoadGame: public Check, public IBrick
{
public:
    upLoadGame();
    virtual ~upLoadGame();

    void upDateLocation(int hang);
    /*
        xóa đi hàng đã ăn được, dịch chuyển các hàm ở trên hàng đã ăn xuống dưới 1 đơn vị
    */

    void saveValue(Brick* pkhoigach);
    /*
        sau khi khối gạch không rơi xuống được nữa, dùng mảng 2 chiều lưu lại thông tin của khối gạch đó
    */

protected:

private:
};

#endif // UPLOADGAME_H
