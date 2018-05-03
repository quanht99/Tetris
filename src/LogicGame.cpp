#include "LogicGame.h"


LogicGame::LogicGame()
{
    //ctor
}

LogicGame::~LogicGame()
{
    //dtor
}

int LogicGame :: VongGame()
{
    MoveBrick Move1;
    DesignBrick Design;
    Draw Draw1;
    UpLoadGame Upload;
    console console;
    In4Game In4;
    Thongtin INFOR;

    string arr;
    clock_t Start, End;
    KhoiGach* curr;
    int IDKhoiTiepTheo=Design.Loai();
    //Lay thong tin nguoi choi
    console.gotoXY(60,5);
    cout << "Nhap Ten Nguoi Choi: ";
    cin >> arr;
    console.clrscr();
    //Bat Dau
    In4.CreatIn4(&INFOR);
    Draw1.VeKhung();
    srand(time(NULL));
    curr=Design.TaoKhoiGach(Design.Loai());

    //Khoi tao gia tri cho mang luu thong tin tro choi
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=10; j++)
            Board[i][j]=0;
    }

    do
    {
        Draw1.VeKhoiGach(curr);
        In4.DrawScore(INFOR);
        Draw1.Xoa_Next();
        Draw1.Ve_Next(IDKhoiTiepTheo);
        Start=clock();
        do
        {
            if(_kbhit())
            {
                char kitu=_getch();
                Draw1.XoaKhoiGach(curr);
                if(kitu=='a' || kitu==75 )
                    Move1.SangTrai(curr);
                if(kitu=='s' || kitu==80)
                    Move1.RoiXuong(curr);
                if(kitu=='d' || kitu==77)
                    Move1.SangPhai(curr);
                if(kitu=='w' || kitu==72 )
                {
                    Move1.XoayKhoiGach(curr);
                }
                Draw1.VeKhoiGach(curr);
            }
            End=clock();
        }
        while(End-Start<INFOR.level);
        Draw1.XoaKhoiGach(curr);
        if(Move1.RoiXuong(curr)!=1)
        {
            Upload.GanGiaTri(curr);

            if(In4.KiemTra(curr, &INFOR)==-1)
                break;

            Design.HuyKhoiGach(curr);
            In4.DrawScore(INFOR);
            curr=Design.TaoKhoiGach(IDKhoiTiepTheo);
            IDKhoiTiepTheo=Design.Loai();
            Draw1.DisplayBoard();
        }
    }
    while(1);
    Design.HuyKhoiGach(curr);
    console.clrscr();
    console.TextColor(7);
    console.gotoXY(50,5);
    cout << "Ten: " << arr ;
    console.gotoXY(50,6);
    cout << "Diem: " << INFOR.score;
    console.gotoXY(50,7);
    cout << "Game Over";
    console.gotoXY(50,8);
    cout << "Ban co muon tiep tuc choi(Y/N): ";
    return 1;
}
