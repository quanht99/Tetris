#include "Check.h"



int Board[10][20];



Check::Check()
{
    //ctor
}

Check::~Check()
{
    //dtor
}

bool Check :: CheckInside(int i,int j)  //Xem i,j có thuộc mảng Board[20][10] hay không?
{
    if(i>=1 && i<=10 && j>=1 && j<=20)
        return true;
    else
        return false;
}

bool Check :: CheckLeft(int i,int j)
{
    if(i>1 && Check::CheckInside(i,j)==true && Board[j][i-1]==0)
        return true;
    else
        return false;
}

bool Check :: CheckRight(int i,int j)
{
    if(i<10 && Check::CheckInside(i,j)==true && Board[j][i+1]==0)
        return true;
    else
        return false;
}

bool Check :: CheckDown(int i,int j)
{
    if(j<20 && Check::CheckInside(i,j)==true && Board[j+1][i]==0)
        return true;
    else
        return false;
}

