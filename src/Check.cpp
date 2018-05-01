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

bool Check :: Inside(int i,int j)  //Xem i,j có thuộc mảng Board[20][10] hay không?
{
    if(i>=1 && i<=10 && j>=1 && j<=20)
        return true;
    else
        return false;
}

bool Check :: Left(int i,int j)
{
    if(i>1 && Check::Inside(i,j)==true && Board[j][i-1]==0)
        return true;
    else
        return false;
}

bool Check :: Right(int i,int j)
{
    if(i<10 && Check::Inside(i,j)==true && Board[j][i+1]==0)
        return true;
    else
        return false;
}

bool Check :: Down(int i,int j)
{
    if(j<20 && Check::Inside(i,j)==true && Board[j+1][i]==0)
        return true;
    else
        return false;
}

