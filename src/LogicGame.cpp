#include "logicGame.h"


logicGame::logicGame()
{
    //ctor
}

logicGame::~logicGame()
{
    //dtor
}

int logicGame :: loopGame()
{
    IPlayer classMove;
    IBrick classBrick;
    IDisPlayGame classDisPlayGame;
    upLoadGame classUpLoadGame;
    console console;
    In4Game classIn4Game;
    in4Game INFOR;

    bool itPlaying=true;
    string arr;
    clock_t Start, End;
    Brick* curr;
    int IDKhoiTiepTheo=classBrick.numRanDom();

    //Lay thong tin nguoi choi
    console.gotoXY(90,20);
    cout << "Nhap Ten Nguoi Choi(viet lien khong dau): ";
    //cin.ignore();
    //getline(cin, arr);
    cin >> arr;
    console.clrscr();

    //Khoi tao mang luu gia tri
    for(int i=0; i<=20; i++)
    {
        for(int j=0; j<=10; j++)
        {
            Board[i][j]=0;
        }
    }

    //Bat Dau
    classIn4Game.creatIn4Game(&INFOR);
    classDisPlayGame.drawFrame();
    drawHightScore();
    srand(time(NULL));
    console.deletePointer();
    curr=classBrick.creatBrick(classBrick.numRanDom());
    while(itPlaying)
    {

        classDisPlayGame.drawBrick(curr);
        classIn4Game.drawScore(INFOR);
        classDisPlayGame.deleteBrickNext();
        classDisPlayGame.drawBrickNext(IDKhoiTiepTheo);
        Start=clock();
        do
        {
            if(_kbhit())
            {
                char click=_getch();
                classDisPlayGame.deleteBrick(curr);
                if(click=='a' || click==75 )
                    classMove.moveLeft(curr);
                if(click=='s' || click==80)
                    classMove.moveDown(curr);
                if(click=='d' || click==77)
                    classMove.moveRight(curr);
                if(click=='w' || click==72 )
                {
                    classMove.turnBrick(curr);
                }
                classDisPlayGame.drawBrick(curr);
            }

            End=clock();
        }
        while(End-Start<INFOR.level);
        classDisPlayGame.deleteBrick(curr);
        if(classMove.moveDown(curr)!=1)
        {
            classUpLoadGame.saveValue(curr);

            if(classIn4Game.checkGame(curr, &INFOR)==-1)
                itPlaying=false;

            classBrick.deleteObject(curr);
            classIn4Game.drawScore(INFOR);
            curr=classBrick.creatBrick(IDKhoiTiepTheo);
            IDKhoiTiepTheo=classBrick.numRanDom();
            classDisPlayGame.disPlayBoard();
        }

    }

    classBrick.deleteObject(curr);
    logicGame::DrawGameOver(INFOR,arr);
    return 0;
}

void logicGame :: DrawGameOver(in4Game infor, string arr)
{
    console console;
    console.clrscr();

    logicGame::takeData(arr, infor);
    console.TextColor(ColorCode_DarkWhite);
    console.gotoXY(50,5);
    cout << "Ten: " << arr ;
    console.gotoXY(50,6);
    cout << "Diem: " << infor.score;
    console.gotoXY(50,7);
    cout << "Game Over";
    console.gotoXY(50,8);
    cout << "Ban co muon tiep tuc choi(Y/N): ";
}

void logicGame :: takeData(string arr, in4Game info)
{
    in4Player ng[6];
    in4Player player;
    int vitri=6;

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

    for(int i=0; i<=4; i++)
    {
        if(ng[i].score < player.score)
        {
            vitri=i;
            break;
        }
    }

    for(int i=4; i>vitri; i--)
    {
        ng[i].name=ng[i-1].name;
        ng[i].score=ng[i-1].score;
    }
    ng[vitri].name=player.name;
    ng[vitri].score=player.score;

    fstream input1;
    input1.open("HightScore.txt");
    for(int i=0; i<=4; i++)
    {
        input1 << ng[i].name << " ";
        input1 << ng[i].score << endl;
    }
    input1.close();
}

