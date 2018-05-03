#include <iostream>
#include <ctime>
#include "LogicGame.h"
#include "console.h"

using namespace std;

int main()
{

    LogicGame Play;
    console console;

    while(1)
    {
        if(Play.VongGame()==1)
        {
            char Kitu;
            cin >> Kitu;
            if(Kitu=='Y' || Kitu=='y')
            {
                console.clrscr();
            }
            if(Kitu=='N' || Kitu=='n')
                break;
        }
    }

    return 0;
}
