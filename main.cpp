#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "LogicGame.h"
#include "console.h"
#include <MMSystem.h>

using namespace std;

int main()
{

    LogicGame Play;
    console console;
//    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    bool isplaying=true;

    while(isplaying)
    {
        if(Play.LoopGame()==0)
        {
            char kiTu;
            cin >> kiTu;
            if(kiTu=='Y' || kiTu=='y')
            {
                console.clrscr();
            }
            if(kiTu=='N' || kiTu=='n')
            {
                isplaying=false;
            }
        }
    }

    return 0;
}
