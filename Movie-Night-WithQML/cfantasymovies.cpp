#include "cfantasymovies.h"
#include <QDebug>


//******Constructor


/*CFantasyMovies::CFantasyMovies(Stack& odd, Stack& even, QObject *parent) : m_stackOdd(odd), m_stackEven(even), m_CRandom(m_stackOdd, m_stackEven), QObject(parent) , m_movieTitle("CFantasy 123"), m_userRandomNumber("")
{
    //qDebug() <<"CFantasyMovies being created";
    //qDebug() << m_userRandomNumber;
}*/



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

//*********************WORKS WITH SIGNALS*************************************
CFantasyMovies::CFantasyMovies(const QString &movieTitle, const QString &userRandomNumber, const Stack &stackOdd, const Stack &stackEven, const CRandom &CRandom) : m_movieTitle(movieTitle),
    m_userRandomNumber(userRandomNumber),
    m_stackOdd(stackOdd),
    m_stackEven(stackEven),
    m_CRandom(CRandom)
{}
CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) , m_movieTitle("Surprise Movies will print here!"), m_userRandomNumber("")
{
    //qDebug() <<"CFantasyMovies being created";
    //qDebug() << m_userRandomNumber;
}

//**********Movie Title Functions
void CFantasyMovies::anotherFunction()
{
    qDebug() <<"Another function";
}

QString CFantasyMovies::getMovieTitle()
{
    ++classCounter;
    qDebug() <<"IN getMovieTitle" <<m_movieTitle <<classCounter;
    QString s = QString::number(classCounter);
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
    //qDebug() <<"in setMovieTitle  Parity = " <<parity;
    if (parity == "2")
    {
        //qDebug() <<"In set movie Even";
        m_movieTitle = m_CRandom.GetEvenTitle();
        //m_movieTitle = m_CRandom.GetEvenTitle();
        //m_movieTitle = "even";
    }
    else if(parity == "odd"){
        //qDebug() <<"Calling GetOddTitle";
        m_movieTitle = m_CRandom.GetOddTitle();
        //qDebug() << "m_movieTitle in else if" << m_movieTitle;
    }
    else
        m_movieTitle = "Trouble in paradise";
    qDebug() << "m_movieTitle before emit" << m_movieTitle;
    //qDebug() <<"Movie title using getMovie: " << getMovieTitle();
    //emit movieTitleChanged(m_movieTitle);
    //qDebug() <<"Movie title after emit: " << m_movieTitle;
}
//********End of Movie Title Functions


//********User Random Number Functions
QString CFantasyMovies::getUserRandomNumber()
{

    qDebug() << "m_userRandom in getUserRandom: " << m_userRandomNumber;
    //return "RandomNumberToMovie";
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

size_t CFantasyMovies::size()
{
    return m_stackEven.size() + m_stackOdd.size();
}

void CFantasyMovies::setUserRandomNumber(QString newNum)
{
    //qDebug() << "newNum is: " << newNum <<"Size is: " << m_CRandom.size();
    m_userRandomNumber = newNum;
    QString selection {};
    if (m_userRandomNumber.toInt() % 2 == 0) {
        selection = "2";
    }
    else
        selection = "odd";
    qDebug() <<"Selection is: "<< selection;
    //test(selection);
    setMovieTitle(selection);
    emit userRandomNumberChanged(QVariant(m_movieTitle));
    emit movieTitleChanged(m_movieTitle);
}


