#include "LogicGame.h"


LogicGame::LogicGame()
{
    //ctor
}

LogicGame::~LogicGame()
{
    //dtor
}

int LogicGame :: LoopGame()
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
    int IDKhoiTiepTheo=Design.NumRandom();

    //Lay thong tin nguoi choi
    console.gotoXY(60,5);
    cout << "Nhap Ten Nguoi Choi: ";
    cin >> arr;
    console.clrscr();

    //Bat Dau
    In4.CreatIn4(&INFOR);
    Draw1.DrawFrame();
    srand(time(NULL));
    curr=Design.CreatBrick(Design.NumRandom());

    //Khoi tao gia tri cho mang luu thong tin tro choi
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=10; j++)
            Board[i][j]=0;
    }

    do
    {
        Draw1.DrawBrick(curr);
        In4.DrawScore(INFOR);
        Draw1.DeleteBrick_Next();
        Draw1.DrawBrick_Next(IDKhoiTiepTheo);
        Start=clock();
        do
        {
            if(_kbhit())
            {
                char kitu=_getch();
                Draw1.DeleteBrick(curr);
                if(kitu=='a' || kitu==75 )
                    Move1.moveLeft(curr);
                if(kitu=='s' || kitu==80)
                    Move1.moveDown(curr);
                if(kitu=='d' || kitu==77)
                    Move1.moveRight(curr);
                if(kitu=='w' || kitu==72 )
                {
                    Move1.turnBrick(curr);
                }
                Draw1.DrawBrick(curr);
            }
            End=clock();
        }
        while(End-Start<INFOR.level);
        Draw1.DeleteBrick(curr);
        if(Move1.moveDown(curr)!=1)
        {
            Upload.SaveValue(curr);

            if(In4.CkeckGame(curr, &INFOR)==-1)
                break;

            Design.Delete_Object(curr);
            In4.DrawScore(INFOR);
            curr=Design.CreatBrick(IDKhoiTiepTheo);
            IDKhoiTiepTheo=Design.NumRandom();
            Draw1.DisplayBoard();
        }
    }
    while(1);
    Design.Delete_Object(curr);
    LogicGame::DrawGameOver(INFOR,arr);
    return 1;
}

void LogicGame :: DrawGameOver(Thongtin infor, string arr)
{
    console console;
    console.clrscr();
    LogicGame::nhapDuLieu(arr, infor,"HightScore.txt");
    console.TextColor(7);
    console.gotoXY(50,5);
    cout << "Ten: " << arr ;
    console.gotoXY(50,6);
    cout << "Diem: " << infor.score;
    console.gotoXY(50,7);
    cout << "Game Over";
    console.gotoXY(50,8);
    cout << "Ban co muon tiep tuc choi(Y/N): ";
}

void LogicGame :: nhapDuLieu(string arr, Thongtin infor, string file)
{
    ofstream input;
    input.open(file.c_str());
    input << arr << " " << infor.score << endl;
    input.close();
}

