#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include "stackadt.h"
#include "crandom.h"



class CFantasyMovies : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString movieTitle READ movieTitle WRITE setMovieTitle NOTIFY movieTitleChanged)
    Q_PROPERTY(QString userRandomNumber READ userRandomNumber WRITE setUserRandomNumber NOTIFY userRandomNumberChanged)


public:
    explicit CFantasyMovies(QObject *parent = nullptr, Stack& oddStack, Stack& evenStack);
    //explicit CFantasyMovies(QObject *parent = nullptr);
    Q_INVOKABLE void anotherFunction();
    Q_INVOKABLE QString getMovieTitle();
    Q_INVOKABLE QString getUserRandomNumber();
    QString movieTitle();
    QString userRandomNumber();

    //CRandom& m_CRandom{};

signals:
    void movieTitleChanged(QString);
    void userRandomNumberChanged(QString);

public slots:
    void setMovieTitle(QString);
    void setUserRandomNumber(QString);
    void callMe();
private:
    QString m_movieTitle;
    QString m_userRandomNumber;
    Stack  m_stackOdd;
    Stack  m_stackEven;
    CRandom  m_CRandom;


};

#endif // CFANTASYMOVIES_H
