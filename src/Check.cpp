#include "Check.h"



int Board[20][10];



Check::Check()
{
    //ctor
}

Check::~Check()
{
    //dtor
}

bool Check :: checkInside(int i,int j)
{
    if(i>=1 && i<=10 && j>=1 && j<=20)
        return true;
    else
        return false;
}

bool Check :: checkLeft(int i,int j)
{
    if(i>1 && Check::checkInside(i,j)==true && Board[j][i-1]!=1)
        return true;
    else
        return false;
}

bool Check :: checkRight(int i,int j)
{
    if(i<10 && Check::checkInside(i,j)==true && Board[j][i+1]!=1)
        return true;
    else
        return false;
}

bool Check :: checkDown(int i,int j)
{
    if(j<20 && Check::checkInside(i,j)==true && Board[j+1][i]!=1)
        return true;
    else
        return false;
}

