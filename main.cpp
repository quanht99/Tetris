#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "logicGame.h"
#include "console.h"

using namespace std;

int main()
{

    logicGame Play;
    console console;
    bool isplaying=true;
    while(isplaying)
    {
        if(Play.loopGame()==0)
        {
            char onClick;
            cin >> onClick;
            if(onClick=='Y' || onClick=='y')
            {
                console.clrscr();
            }
            if(onClick=='N' || onClick=='n')
            {
                isplaying=false;
            }
        }
    }

    return 0;
}
