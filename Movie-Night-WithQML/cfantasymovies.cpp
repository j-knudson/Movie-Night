#include "cfantasymovies.h"
#include <QDebug>


//******Constructor
CFantasyMovies::CFantasyMovies(QObject *parent, Stack& odd, Stack& even ) :QObject(parent), m_stackOdd(odd), m_stackEven(even), m_CRandom(m_stackOdd, m_stackEven), m_movieTitle("CFantasy 123"), m_userRandomNumber("")
{
    //qDebug() <<"CFantasyMovies being created";
    //qDebug() << m_userRandomNumber;
}



/*CFantasyMovies::CFantasyMovies(QObject *parent) :  QObject(parent) ,
{
    //qDebug() <<"CFantasyMovies being created";
    //qDebug() << m_userRandomNumber;

    m_stackOdd = Stack();
    m_stackEven = Stack();
    m_CRandom = new CRandom(m_stackOdd, m_stackEven);
    m_movieTitle ="CFantasy 123";
    m_userRandomNumber= "";
}*/

/*
CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) , m_movieTitle("CFantasy 123"), m_userRandomNumber("")
{
    //qDebug() <<"CFantasyMovies being created";
    //qDebug() << m_userRandomNumber;
}*/

//**********Movie Title Functions
void CFantasyMovies::anotherFunction()
{
    qDebug() <<"Another function";
}

QString CFantasyMovies::getMovieTitle()
{
    return m_movieTitle;
}
/*
void CFantasyMovies::callMe()
{
   qDebug() << "I'm being called";
}*/

QString CFantasyMovies::movieTitle()
{
    return m_movieTitle;
}

//void CFantasyMovies::setMovieTitle(QString newVar)
void CFantasyMovies::setMovieTitle(QString parity)
{
    if (parity == "even")
        m_movieTitle = m_CRandom.GetEvenTitle();
    else if(parity == "odd")
        m_movieTitle = m_CRandom.GetOddTitle();
    else
        m_movieTitle = "Trouble in paradise";
    emit movieTitleChanged(m_movieTitle);
    /*
    if(m_movieTitle != newVar)
    {
       m_movieTitle = newVar;
       qDebug() <<"SetMovie --> m_movieTitle is: " <<m_movieTitle;
       emit movieTitleChanged(m_movieTitle);
    }*/
}
//********End of Movie Title Functions


//********User Random Number Functions
QString CFantasyMovies::getUserRandomNumber()
{
    return m_userRandomNumber;
}

void CFantasyMovies::callMe()
{
    qDebug() << "I'm being called";
}




QString CFantasyMovies::userRandomNumber()
{
    return m_userRandomNumber;
}

void CFantasyMovies::setUserRandomNumber(QString newNum)
{
    qDebug() << "newNum is: " << newNum;
    m_userRandomNumber = newNum;
    QString selection {};
    if (m_userRandomNumber.toInt() % 2 == 0) {
        selection = "even";
    }
    else
        selection = "odd";
    qDebug() <<"Selection is: "<< selection;
    //test(selection);
    setMovieTitle(selection);
    //emit userRandomNumberChanged(selection);

}
