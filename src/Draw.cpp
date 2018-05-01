#include "Draw.h"

Draw::Draw()
{
    //ctor
}

Draw::~Draw()
{
    //dtor
}

void Draw :: VeKhung()
{
    int i, j;
    for(i=4;i<=55;i++)
    {
        for(j=1;j<=41;j++)
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
    for(i=7;i<=55;i+=5)
    {
        gotoXY(i,0);
        cout << tmp++;
    }
    tmp=1;
    for(j=3;j<=41;j+=2)
    {
        gotoXY(2,j);
        cout << tmp++;
    }
}
void Draw :: VeKhoiGach(KhoiGach* pkhoigach)
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
                        console::TextColor(12);
                        console::gotoXY((pkhoigach->iBoard)*5+j*5+h-1,(pkhoigach->jBoard)*2+i*2+k-1);
                        cout << char(219);
                    }
                }
            }
        }
    }
}

void Draw :: XoaKhoiGach(KhoiGach* pkhoigach)
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
                        console::TextColor(12);
                        console::gotoXY((pkhoigach->iBoard+j)*5+h-1,(pkhoigach->jBoard+i)*2+k-1);
                        cout << " ";
                    }
                }
            }
        }
    }
}

void Draw :: DisplayBoard()
{
    int i, j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=20;j++)
        {
            if(Board[j][i]==0)
            {
                for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::TextColor(12);
                        console::gotoXY(i*5+h-1,j*2+k-1);
                        cout << " ";
                    }
                }
            }
            if(Board[j][i]==0&&j==20)
            {
                for(int h=1;h<=5;h++)
                {
                    console::TextColor(7);
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
                        console::TextColor(7);
                        console::gotoXY(i*5+h-1,j*2+k-1);
                        cout << char(219);
                    }
                }
            }
        }
    }
}

void Draw :: Ve_Next(int ID)
{
	KhoiGach *pnext=new KhoiGach;
	pnext=TaoKhoiGach(ID);
	for(int i=0;i<pnext->Row;i++)
	{
		for (int j=0;j<pnext->Col;j++)
		{
			if(pnext->arr[i][j]==1)
			{
				for(int k=1; k<=2; k++)
                {
                    for(int h=1; h<=5; h++)
                    {
                        console::TextColor(12);
                        console::gotoXY(60+h+j*5,5+k+i*2);
                        cout << char(219);
                    }
                }
			}
		}

	}
	DesignBrick::HuyKhoiGach(pnext);
}

void Draw :: Xoa_Next()
{
    for(int i=0;i<=20;i++)
	{
		for (int j=0;j<=8;j++)
		{
                console::TextColor(0);
				console::gotoXY(60+i,5+j);
				cout << " ";
		}

	}

}

