#ifndef CRANDOM_H
#define CRANDOM_H
#include <QDebug>

#include "stackadt.h"
#include "creadfile.h"


//*****************INHERITS VERSION*******************
/*
class CRandom : CReadFile
{

private:
    CReadFile m_stacks;


public:
    CRandom(CReadFile& stacks)
        :m_stacks{ stacks }
    {

    }
    QString GetEvenTitle(Stack&);
    QString GetOddTitle(Stack&);
    Stack GetStack(QString parity);
    QString GetMovie(QString parity);
    void test(QString);

};
*/
//***************END INHERITS  VERSION**********************

class CRandom
{

private:
    Stack& m_stackOdd ;
    Stack& m_stackEven ;

public:
    /*CRandom(Stack& stackO, Stack& stackE)
        :m_stackOdd{ stackO }, m_stackEven {stackE}
    {

    }*/
    CRandom(Stack& stackO, Stack& stackE)
        :m_stackOdd{ stackO }, m_stackEven {stackE}
    {

    }
    QString GetRandomTitle(int);
    QString GetOddTitle();
    QString GetEvenTitle();
    Stack& GetOdd();
    Stack& GetEven();
    size_t size();


    void test(QString);
};


#endif // CRANDOM_H




