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

    bool itplaying=true;
    string arr;
    clock_t Start, End;
    KhoiGach* curr;
    int IDKhoiTiepTheo=Design.NumRandom();

    //Lay thong tin nguoi choi
    console.gotoXY(60,5);
    cout << "Nhap Ten Nguoi Choi: ";
//    cin.ignore();
//    getline(cin, arr);
    cin >> arr;
    console.clrscr();

    //Bat Dau
    In4.CreatIn4(&INFOR);
    Draw1.DrawFrame();
    DrawHightScore();
    srand(time(NULL));
    curr=Design.CreatBrick(Design.NumRandom());

    while(itplaying)
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
                char kiTu=_getch();
                Draw1.DeleteBrick(curr);
                if(kiTu=='a' || kiTu==75 )
                    Move1.moveLeft(curr);
                if(kiTu=='s' || kiTu==80)
                    Move1.moveDown(curr);
                if(kiTu=='d' || kiTu==77)
                    Move1.moveRight(curr);
                if(kiTu=='w' || kiTu==72 )
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
                itplaying=false;

            Design.Delete_Object(curr);
            In4.DrawScore(INFOR);
            curr=Design.CreatBrick(IDKhoiTiepTheo);
            IDKhoiTiepTheo=Design.NumRandom();
            Draw1.DisplayBoard();
        }

    }

    Design.Delete_Object(curr);
    LogicGame::DrawGameOver(INFOR,arr);
    return 0;
}

void LogicGame :: DrawGameOver(Thongtin infor, string arr)
{
    console console;
    console.clrscr();
    LogicGame::nhapDuLieu(arr, infor);
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

void LogicGame :: nhapDuLieu(string arr, Thongtin info)
{
    In4Player ng[6];
    In4Player player;
    int vitri;

    player.name=arr;
    player.score=info.score;

    fstream file;
    file.open("HightScore.txt");
    for(int i = 0; i < 5 ; i++)
    {
        file >> ng[i].name;
        file >> ng[i].score;
    }
    file.close();

    for(int i=0;i<=4;i++)
    {
        if(ng[i].score < player.score)
            {
                vitri=i;
                break;
            }
    }

    for(int i=4;i>vitri;i--)
    {
        ng[i].name=ng[i-1].name;
        ng[i].score=ng[i-1].score;
    }
    ng[vitri].name=arr;
    ng[vitri].score=info.score;

    for(int i = 0; i < 5 ; i++)
    {
        cout << ng[i].name << " " << ng[i].score << endl;
    }

    fstream input1;
    input1.open("HightScore.txt");
    for(int i=0; i<=4; i++)
    {
        input1 << ng[i].name << " ";
        input1 << ng[i].score << endl;
//        input << "abcd" << " ";
//        input << 100*i << endl;
    }
    input1.close();
}

