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
void MoveBrick :: SangTrai( KhoiGach *pkhoigach )
{
    for(int i = 0; i < pkhoigach->Row ; i++ )
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check::Left(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false)
                    return;
            }

    pkhoigach->iBoard-=1;

}

void MoveBrick :: SangPhai(KhoiGach *pkhoigach)
{
    for(int i=0; i<pkhoigach->Row; i++)
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check::Right(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false)
                    return;
            }

    pkhoigach->iBoard+=1;
}

int MoveBrick :: RoiXuong(KhoiGach *pkhoigach)  //0 : không thể rơi xuống,1 : có thể rơi xuống.
{
    for(int i=0; i<pkhoigach->Row; i++)
        for(int j=0; j<pkhoigach->Col; j++)
            if(pkhoigach->arr[i][j]==1)
            {
                if(Check :: Down(pkhoigach->iBoard+j,pkhoigach->jBoard+i)==false)
                    return 0;
            }
    pkhoigach->jBoard+=1; //Roi xuong 1 so voi Board[20][10]
    return 1;
}

void MoveBrick :: XoayKhoiGach(KhoiGach* pkhoigach)
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
//    if(pkhoigach->Col!=4&&pkhoigach->Col!=1)
//    {
//
//    }
//    else
//    {
//        if(pkhoigach->Row==1)
//        {
//            for(int i=0; i<pkhoigach->Col; i++)
//                tmpArr[i][0]=pkhoigach->arr[0][i];
//        }
//        else
//        {
//            for(int i=0; i<pkhoigach->Row; i++)
//            {
//                tmpArr[0][i]=pkhoigach->arr[i][0];
//
//            }
//        }
//    }

    //Kiểm tra hợp lệ.
    if(pkhoigach->iBoard>=9)
        pkhoigach->iBoard-=1;
    for (i=0; i<tmpRow; i++)
    {
        for(j=0; j<tmpCol; j++)
        {


            if(Check :: Inside(pkhoigach->iBoard+j,pkhoigach->jBoard+i) == false || Board[pkhoigach->jBoard+j][pkhoigach->iBoard+i]==1)
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
