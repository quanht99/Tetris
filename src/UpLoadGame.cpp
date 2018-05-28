#include "upLoadGame.h"

upLoadGame::upLoadGame()
{
    //ctor
}

upLoadGame::~upLoadGame()
{
    //dtor
}

void upLoadGame :: upDateLocation(int hang)
{
    int i,j;
    for(i=hang; i>1; i--)
        for(j=1; j<=10; j++)
        {
            Board[i][j]=Board[i-1][j];
        }
}

void upLoadGame :: saveValue(Brick* pkhoigach)
{
    for(int i=0; i<pkhoigach->Row; i++)
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                Board[pkhoigach->jBoard+i][pkhoigach->iBoard+j]=1;
            }
}
