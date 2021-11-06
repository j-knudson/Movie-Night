#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include "stackadt.h"
#include "crandom.h"
#include <QVariant>



class CFantasyMovies : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString movieTitle READ movieTitle WRITE setMovieTitle NOTIFY movieTitleChanged)
    Q_PROPERTY(QString userRandomNumber READ userRandomNumber WRITE setUserRandomNumber NOTIFY userRandomNumberChanged)


public:
    //explicit CFantasyMovies(Stack& oddStack, Stack& evenStack, QObject *parent = nullptr);

    //***below is signals working constructor
    explicit CFantasyMovies(QObject *parent = nullptr);
    CFantasyMovies(const QString &movieTitle, const QString &userRandomNumber, const Stack &stackOdd, const Stack &stackEven, const CRandom &CRandom);



    Q_INVOKABLE void anotherFunction();
    Q_INVOKABLE QString getMovieTitle();
    Q_INVOKABLE QString getUserRandomNumber();
    QString movieTitle();
    QString userRandomNumber();
    size_t size();

    //CRandom& m_CRandom{m_StackOdd, mStackEven};



signals:
    void movieTitleChanged(QString);
    void userRandomNumberChanged(QVariant data);

public slots:
    void setMovieTitle(QString);
    void setUserRandomNumber(QString);
    void callMe();
private:
    QString m_movieTitle;
    QString m_userRandomNumber;
    Stack  m_stackOdd;
    Stack  m_stackEven;
    CRandom m_CRandom{m_stackOdd, m_stackEven};
    int classCounter = 0;




};

#endif // CFANTASYMOVIES_H
