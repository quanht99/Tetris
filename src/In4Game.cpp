#include "In4Game.h"

In4Game::In4Game()
{
    //ctor
}

In4Game::~In4Game()
{
    //dtor
}

int In4Game :: KiemTra(KhoiGach *pkhoigach, Thongtin *inforgame)
 {
    int i,j,count, tmp=0;
    j=pkhoigach->Row-1;
    if(pkhoigach->jBoard<2)
        return -1;
    do
		{
			count=0;
			for(i=1;i<=10;i++)
			{
				if(Board[j+pkhoigach->jBoard][i]==1)
                    count++;
			}
			if(count==10)
			{
				tmp++;
                UpLoadGame :: CapNhatLaiToaDo(pkhoigach->jBoard+j);
				//Draw::DisplayBoard();
			}
			else
			{
				j=j-1;
			}
		}while(j>=0);
    if(tmp==1)
        In4Game ::capnhat(inforgame,20);
    if(tmp==2)
        In4Game ::capnhat(inforgame,45);
    if(tmp==3)
        In4Game ::capnhat(inforgame,70);
    if(tmp==4)
        In4Game ::capnhat(inforgame,100);

    return 0;
 }

 void In4Game :: CreatIn4(Thongtin *info)
{
    info->level=1000;
	info->score=0;
}

 bool In4Game :: capnhat(Thongtin *info, int score)
 {
     if(info->score>=(1100-info->level))
        info->level-=100;
     info->score+=score;
     return true;
 }

 void In4Game :: DrawScore(Thongtin infor)
 {
    console::TextColor(15);
	console::gotoXY(70,15);
	cout << "  SCORE: " << infor.score;
	console::gotoXY(70,16);
	cout << "  LEVEL: " << (1100-infor.level)/100;
 }
