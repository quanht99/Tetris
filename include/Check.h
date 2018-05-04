#ifndef CHECK_H
#define CHECK_H

extern int Board[10][20];

class Check
{
public:
    Check();
    virtual ~Check();

    bool CheckInside(int i,int j);

    bool CheckLeft(int i,int j);

    bool CheckRight(int i,int j);

    bool CheckDown(int i,int j);

protected:

private:
};

#endif // CHECK_H
