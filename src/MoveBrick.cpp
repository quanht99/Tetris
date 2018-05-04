#include "MoveBrick.h"


MoveBrick::MoveBrick()
{
    //ctor
}

MoveBrick::~MoveBrick()
{
    //dtor
}
//Row la cot, Col la hang
void MoveBrick :: moveLeft( KhoiGach *pkhoigach )
{
    for(int i = 0; i < pkhoigach->Row ; i++ )
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check::CheckLeft(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false)
                    return;
            }

    pkhoigach->iBoard-=1;

}

void MoveBrick :: moveRight(KhoiGach *pkhoigach)
{
    for(int i=0; i<pkhoigach->Row; i++)
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check::CheckRight(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false)
                    return;
            }

    pkhoigach->iBoard+=1;
}

int MoveBrick :: moveDown(KhoiGach *pkhoigach)  //0 : không thể rơi xuống,1 : có thể rơi xuống.
{
    for(int i=0; i<pkhoigach->Row; i++)
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check :: CheckDown(pkhoigach->iBoard+j,pkhoigach->jBoard+i)==false)
                    return 0;
            }
    pkhoigach->jBoard+=1; //Roi xuong 1 so voi Board[20][10]
    return 1;
}

void MoveBrick :: turnBrick(KhoiGach* pkhoigach)
{
    int i,j;
    int ** tmpArr;
    int tmpRow=pkhoigach->Col;
    int tmpCol=pkhoigach->Row;
    //Cấp phát bộ nhớ cho ma trận phụ tmpArr.
    tmpArr=new int *[tmpRow];
    for( i=0; i<=tmpRow; i++)
    {
        tmpArr[i]=new int [tmpCol];
    }
    ///////////////////////////////////////////////
    for(i=pkhoigach->Row-1; i>=0; i--)
        for(j=pkhoigach->Col-1; j>=0; j--)
        {
            tmpArr[j][pkhoigach->Row-i-1]=pkhoigach->arr[i][j];
        }


    //Kiểm tra hợp lệ.
    if(pkhoigach->iBoard>=9)
        pkhoigach->iBoard-=1;
    if(pkhoigach->iBoard>7 && pkhoigach->Row==4)
        pkhoigach->iBoard=7;
    for (i=0; i<tmpRow; i++)
    {
        for(j=0; j<tmpCol; j++)
        {

            if(Check :: CheckInside(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false || Board[pkhoigach->jBoard+i][pkhoigach->iBoard+j+1]==1)
                return;
        }
    }
    for(i=0; i<pkhoigach->Row; i++)
        delete(pkhoigach->arr[i]);
    delete(pkhoigach->arr);
    //Cập nhật thay đổi sau khi xoay.
    pkhoigach->Col=tmpCol;
    pkhoigach->Row=tmpRow;
    pkhoigach->arr=tmpArr;

}
