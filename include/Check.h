#ifndef CHECK_H
#define CHECK_H

extern int Board[20][10];

class Check
{
public:
    Check();
    virtual ~Check();

    bool checkInside(int i,int j);
    /*
        kiểm tra xem 1 ô gạch của khối gạch đó có nằm trong khung hay không
    */

    bool checkLeft(int i,int j);
    /*
        kiểm tra xem bên trái của ô gạch đang xét có khối nào khác hay k
    */

    bool checkRight(int i,int j);
    /*
        kiểm tra xem bên phải của ô gạch đang xét có khối nào khác hay k
    */

    bool checkDown(int i,int j);
    /*
        kiểm tra xem bên dưới của ô gạch đang xét có khối nào khác hay k
    */
protected:

private:
};

#endif // CHECK_H
