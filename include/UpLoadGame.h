#ifndef UPLOADGAME_H
#define UPLOADGAME_H
#include "Check.h"
#include "DesignBrick.h"


class UpLoadGame: public Check, public DesignBrick
{
public:
    UpLoadGame();
    virtual ~UpLoadGame();

    void UpdateLocation(int hang);

    void SaveValue(KhoiGach* pkhoigach);

protected:

private:
};

#endif // UPLOADGAME_H
