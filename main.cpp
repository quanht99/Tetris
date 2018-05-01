#include <iostream>
#include <ctime>
#include "PlayGame.h"
#include "console.h"

using namespace std;

int main()
{
//    MoveBrick Move1;
//    DesignBrick Design;
//    Draw Draw1;
//    UpLoadGame Upload;
//    console console;
//    In4Game In4;
//
//    Thongtin INFOR;
//    In4.CreatIn4(&INFOR);
//    clock_t Start, End;
//    KhoiGach* curr;
//    Draw1.VeKhung();
//    int IDKhoiTiepTheo=Design.Loai();
//    curr=Design.TaoKhoiGach(Design.Loai());
//    Draw1.VeKhoiGach(curr);
//    Sleep(1000);
//    //Draw1.XoaKhoiGach(curr);
//    for(int i=1;i<=20;i++)
//    {
//        for(int j=1;j<=10;j++)
//            Board[i][j]=0;
//    }
//
//    do
//    {
//        Draw1.VeKhoiGach(curr);
//        In4.DrawScore(INFOR);
//        Draw1.Xoa_Next();
//		Draw1.Ve_Next(IDKhoiTiepTheo);
//        Start=clock();
//        do
//        {
//            if(_kbhit())
//            {
//                char kitu=_getch();
//                Draw1.XoaKhoiGach(curr);
//                if(kitu=='a' || kitu==75 )
//                    Move1.SangTrai(curr);
//                if(kitu=='s' || kitu==80)
//                    Move1.RoiXuong(curr);
//                if(kitu=='d' || kitu==77)
//                    Move1.SangPhai(curr);
//                if(kitu=='w' || kitu==72 )
//                    {Move1.XoayKhoiGach(curr);}
//                Draw1.VeKhoiGach(curr);
//            }
//            End=clock();
//        }while(End-Start<INFOR.level);
//        Draw1.XoaKhoiGach(curr);
//        if(Move1.RoiXuong(curr)!=1)
//        {
//            Upload.GanGiaTri(curr);
//
//            if(In4.KiemTra(curr, &INFOR)==-1)
//                break;
//            Design.HuyKhoiGach(curr);
//            In4.DrawScore(INFOR);
//            curr=Design.TaoKhoiGach(IDKhoiTiepTheo);
//            IDKhoiTiepTheo=Design.Loai();
//            Draw1.DisplayBoard();
//        }
//    }
//    while(1);
//    Design.HuyKhoiGach(curr);
        PlayGame Play;
        console console;
        while(1)
        {
            if(Play.VongGame()==1)
            {
    //            while(1)
    //            {
    //                if(_kbhit())
    //                {
    //                    char c=_getch();
    //                    if(c=='t')
    //                        {
    //                            console.clrscr();
    //                            Play.VongGame();
    //                        }
    //                    if(c=='m')
    //                        return 0;
    //                }
    //            }
                char YesNo;
                cin >> YesNo;
                if(YesNo=='Y')
                {
                    console.clrscr();
                }
                if(YesNo=='N')
                    break;
            }
        }
        return 0;
}
