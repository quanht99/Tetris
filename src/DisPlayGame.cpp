#include "IDisPlayGame.h"

IDisPlayGame::IDisPlayGame()
{
    //ctor
}

IDisPlayGame::~IDisPlayGame()
{
    //dtor
}

void IDisPlayGame :: drawFrame()
{
    int i, j;
    for(i=4; i<=55; i++)
    {
        for(j=1; j<=41; j++)
        {
            if((i==4 || i==55)&&j!=1)
            {
                console::gotoXY(i,j);
                console::TextColor(7);
                cout << char(186);
            }
            if((j==1||j==41)&&i!=4&&i!=55)
            {
                console::gotoXY(i,j);
                console::TextColor(7);
                cout << "_";
            }

        }
    }
    int tmp=1;
    for(i=7; i<=55; i+=5)
    {
        gotoXY(i,0);
        cout << tmp++;
    }
    tmp=1;
    for(j=3; j<=41; j+=2)
    {
        gotoXY(2,j);
        cout << tmp++;
    }
}
void IDisPlayGame :: drawBrick(Brick* pkhoigach)
{
    int i, j;
    if(pkhoigach->Row==1 || pkhoigach->Row==4)
        console::TextColor(14);
    if(pkhoigach->Col==pkhoigach->Row)
        console::TextColor(1);
    if(pkhoigach->Row==3 || pkhoigach->Col==3)
    {
        srand(time(NULL));
        int num=rand()%4;
        if(num==0)
            console::TextColor(12);
        if(num==1)
            console::TextColor(11);
        if(num==2)
            console::TextColor(13);
        if(num==3)
            console::TextColor(10);
    }
    for(i=0; i<pkhoigach->Row; i++)
    {
        for(j=0; j<pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j]==1)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::gotoXY((pkhoigach->iBoard)*5+j*5+h-1,(pkhoigach->jBoard)*2+i*2+k-1);
                        cout << char(219);
                    }
                }
            }
        }
    }
}

void IDisPlayGame :: deleteBrick(Brick* pkhoigach)
{
    int i, j;
    for(i=0; i<pkhoigach->Row; i++)
    {
        for(j=0; j<pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j]==1)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::TextColor(ColorCode_Red);
                        console::gotoXY((pkhoigach->iBoard+j)*5+h-1,(pkhoigach->jBoard+i)*2+k-1);
                        cout << " ";
                    }
                }
            }
        }
    }
}

void IDisPlayGame :: disPlayBoard()
{
    int i, j;
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=20; j++)
        {
            if(Board[j][i]==0)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::gotoXY(i*5+h-1,j*2+k-1);
                        cout << " ";
                    }
                }
            }
            if(Board[j][i]==0&&j==20)
            {
                for(int h=1; h<=5; h++)
                {
                    console::TextColor(ColorCode_DarkWhite);
                    console::gotoXY(i*5+h-1,j*2+1);
                    cout << "_";
                }
            }
            if(Board[j][i]==1)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::TextColor(ColorCode_White);
                        console::gotoXY(i*5+h-1,j*2+k-1);
                        cout << char(219);
                    }
                }
            }
        }
    }
}

void IDisPlayGame :: drawBrickNext(int ID)
{
    Brick *pNext=new Brick;
    pNext=IBrick::creatBrick(ID);
    if(pNext->Row==1 || pNext->Row==4)
        console::TextColor(ColorCode_Yellow);
    if(pNext->Col==pNext->Row)
        console::TextColor(ColorCode_DarkBlue);
    if(pNext->Row==3 || pNext->Col==3)
    {
        srand(time(NULL));
        int num=rand()%4;
        if(num==0)
            console::TextColor(ColorCode_Cyan);
        if(num==1)
            console::TextColor(ColorCode_Pink);
        if(num==2)
            console::TextColor(ColorCode_Green);
        if(num==3)
            console::TextColor(ColorCode_Red);
    }
    for(int i=0; i<pNext->Row; i++)
    {
        for (int j=0; j<pNext->Col; j++)
        {
            if(pNext->arr[i][j]==1)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::gotoXY(60+h+j*5,5+k+i*2);
                        cout << char(219);
                    }
                }
            }
        }

    }
    IBrick::deleteObject(pNext);
}

void IDisPlayGame :: deleteBrickNext()
{
    for(int i=0; i<=20; i++)
    {
        for (int j=0; j<=8; j++)
        {
            console::TextColor(ColorCode_Back);
            console::gotoXY(60+i,5+j);
            cout << " ";
        }

    }

}

void IDisPlayGame :: drawHightScore()
{
    in4Player ng[5];
    fstream file;
    file.open("HightScore.txt");
    for(int i=0; i<=4; i++)
    {
        file >> ng[i].name;
        file >> ng[i].score;
    }
    console::TextColor(ColorCode_DarkWhite);
    gotoXY(130,5);
    cout << "HIGHT SCORE";
    for(int i=0; i<=4; i++)
    {
        console::gotoXY(120,7+i*2);
        cout << ng[i].name;
        console::gotoXY(140,7+2*i);
        cout << ng[i].score;
    }
}
