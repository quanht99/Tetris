
#include "DesignBrick.h"


DesignBrick::DesignBrick()
{
    //ctor
}

DesignBrick::~DesignBrick()
{
    //dtor
}


KhoiGach *DesignBrick :: CreatBrick(int ID)
{
    KhoiGach *pKhoiGach;
    pKhoiGach = new KhoiGach;
    switch(ID)
    {
    case 15:
        pKhoiGach->Row=4;
        pKhoiGach->Col=1;
        pKhoiGach->iBoard=5;
        pKhoiGach->jBoard=1;
        break;
    case 31:
        pKhoiGach->Row=pKhoiGach->Col=2;
        pKhoiGach->iBoard=5;
        pKhoiGach->jBoard=1;
        break;
    default:
        pKhoiGach->Row=2;
        pKhoiGach->Col=3;
        pKhoiGach->iBoard=5;
        pKhoiGach->jBoard=1;
        break;
    }
    pKhoiGach->arr=new int *[pKhoiGach->Row];
    for(int i=0; i<pKhoiGach->Row; i++)
    {
        pKhoiGach->arr[i] = new int [pKhoiGach->Col];
    }
    for(int k=0; k<pKhoiGach->Col*pKhoiGach->Row; k++)
    {
        pKhoiGach->arr[k/pKhoiGach->Col][k%pKhoiGach->Col]=(ID>>(pKhoiGach->Col*pKhoiGach->Row-1-k))&1;     //Tham Khao
    }
    return pKhoiGach;
}

int DesignBrick :: NumRandom()
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

void DesignBrick :: Delete_Object(KhoiGach* pkhoigach)
{
    int i;
    //Huy bo nho cua ma tran trang thai arr.
    for(i=0; i<pkhoigach->Row; i++)
        delete(pkhoigach->arr[i]);
    delete(pkhoigach->arr);
}


