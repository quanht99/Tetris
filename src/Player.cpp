#include "IPlayer.h"


IPlayer::IPlayer()
{
    //ctor
}

IPlayer::~IPlayer()
{
    //dtor
}
//Row la cot, Col la hang
void IPlayer :: moveLeft( Brick *pKhoiGach )
{
    for(int i = 0; i < pKhoiGach->Row ; i++ )
        for(int j=0; j<pKhoiGach->Col; j++)
            if(pKhoiGach->arr[i][j]==1)
            {
                if(Check::checkLeft(pKhoiGach->iBoard+j,pKhoiGach->jBoard+i) == false)
                    return;
            }

    pKhoiGach->iBoard-=1;

}

void IPlayer :: moveRight(Brick *pKhoiGach)
{
    for(int i=0; i<pKhoiGach->Row; i++)
        for(int j=0; j<pKhoiGach->Col; j++)
            if(pKhoiGach->arr[i][j]==1)
            {
                if(Check::checkRight(pKhoiGach->iBoard+j,pKhoiGach->jBoard+i) == false)
                    return;
            }

    pKhoiGach->iBoard+=1;
}

int IPlayer :: moveDown(Brick *pKhoiGach)  //0 : không thể rơi xuống,1 : có thể rơi xuống.
{
    for(int i=0; i<pKhoiGach->Row; i++)
        for(int j=0; j<pKhoiGach->Col; j++)
            if(pKhoiGach->arr[i][j]==1)
            {
                if(Check :: checkDown(pKhoiGach->iBoard+j,pKhoiGach->jBoard+i)==false)
                    return 0;
            }
    pKhoiGach->jBoard+=1; //Roi xuong 1 so voi Board[20][10]
    return 1;
}

void IPlayer :: turnBrick(Brick* pKhoiGach)
{
    int i,j;
    int ** tmpArr;
    int tmpRow=pKhoiGach->Col;
    int tmpCol=pKhoiGach->Row;
    //Cấp phát bộ nhớ cho ma trận phụ tmpArr.
    tmpArr=new int *[tmpRow];
    for( i=0; i<=tmpRow; i++)
    {
        tmpArr[i]=new int [tmpCol];
    }
    ///////////////////////////////////////////////
    for(i=pKhoiGach->Row-1; i>=0; i--)
        for(j=pKhoiGach->Col-1; j>=0; j--)
        {
            tmpArr[j][pKhoiGach->Row-i-1]=pKhoiGach->arr[i][j];
        }


    //Kiểm tra hợp lệ.
    if(pKhoiGach->iBoard>=9)
        pKhoiGach->iBoard-=1;
    if(pKhoiGach->iBoard>7 && pKhoiGach->Row==4)
        pKhoiGach->iBoard=7;
    for (i=0; i<tmpRow; i++)
    {
        for(j=0; j<tmpCol; j++)
        {

            if(Check :: checkInside(pKhoiGach->iBoard+j,pKhoiGach->jBoard+i) == false || Board[pKhoiGach->jBoard+i][pKhoiGach->iBoard+j+1]==1)
                return;
        }
    }
    for(i=0; i<pKhoiGach->Row; i++)
        delete(pKhoiGach->arr[i]);
    delete(pKhoiGach->arr);
    //Cập nhật thay đổi sau khi xoay.
    pKhoiGach->Col=tmpCol;
    pKhoiGach->Row=tmpRow;
    pKhoiGach->arr=tmpArr;

}
