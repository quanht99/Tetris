
#include "DesignBrick.h"


DesignBrick::DesignBrick()
{
    //ctor
}

DesignBrick::~DesignBrick()
{
    //dtor
}


KhoiGach *DesignBrick :: TaoKhoiGach(int ID)
{
    KhoiGach *pkhoigach;
    pkhoigach = new KhoiGach;
    switch(ID)
    {
    case 15:
        pkhoigach->Row=4;
        pkhoigach->Col=1;
        pkhoigach->iBoard=5;
        pkhoigach->jBoard=1;
        break;
    case 31:
        pkhoigach->Row=pkhoigach->Col=2;
        pkhoigach->iBoard=5;
        pkhoigach->jBoard=1;
        break;
    default:
        pkhoigach->Row=2;
        pkhoigach->Col=3;
        pkhoigach->iBoard=5;
        pkhoigach->jBoard=1;
        break;
    }
    pkhoigach->arr=new int *[pkhoigach->Row];
    for(int i=0; i<pkhoigach->Row; i++)
    {
        pkhoigach->arr[i] = new int [pkhoigach->Col];
    }
    for(int k=0; k<pkhoigach->Col*pkhoigach->Row; k++)
    {
        pkhoigach->arr[k/pkhoigach->Col][k%pkhoigach->Col]=(ID>>(pkhoigach->Col*pkhoigach->Row-1-k))&1;     //Tham Khao
    }
    return pkhoigach;
}

int DesignBrick :: Loai()
{
    srand(time(NULL));
    int x=rand()%7;
    switch(x)
    {
    case 0:
        return 57;
        break;
    case 1:
        return 58;
        break;
    case 2:
        return 51;
        break;
    case 3:
        return 30;
        break;
    case 4:
        return 31;
        break;
    case 5:
        return 15;
        break;
    case 6:
        return 60;
        break;
    }
}

void DesignBrick :: HuyKhoiGach(KhoiGach* pkhoigach)
{
    int i;
    //Huy bo nho cua ma tran trang thai arr.
    for(i=0; i<pkhoigach->Row; i++)
        delete(pkhoigach->arr[i]);
    delete(pkhoigach->arr);

    //Sau do moi delete (pkhoigach)
    delete(pkhoigach);
    pkhoigach=NULL;
}


