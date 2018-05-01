#ifndef CHECK_H
#define CHECK_H

extern int Board[10][20];
class Check
{
    public:
        Check();
        virtual ~Check();

        bool Inside(int i,int j);

        bool Left(int i,int j);

        bool Right(int i,int j);

        bool Down(int i,int j);

    protected:

    private:
};

#endif // CHECK_H
