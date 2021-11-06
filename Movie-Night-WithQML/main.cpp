#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QFile>
#include <iostream>
#include <functional>       //for std::reference_wrapper
#include <vector>           //for vector
#include <cstdlib>			//for size_t and rand
#include <fstream>
#include <string>           //for getline
#include <time.h>           //for time() used with seeding
#include <QTextStream>

#include "stackadt.h"
#include "someclass.h"
#include "cfantasymovies.h"
#include "crandom.h"
#include "creadfile.h"

//#include "crandom.h"
//main file currently contains one class, CReadFile, that have not yet been moved to its own files
//this class contains the filepath for movie_list.txt


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //SomeClass testClass; ***********
    //qmlRegisterType < SomeClass > ("Monty", 1, 0, "SomeClass");   //tutorial test
    // </ testClass ************


    qmlRegisterType < CFantasyMovies > ("Comms", 1, 0, "CFantasyMovies");  //create Comms package from CFantasyMovies class that is used by the QML frontend


    Stack OddMovieStack, EvenMovieStack; //create two stacks to hold movies
    CReadFile readfile{};   //create empty CReadFile
    readfile.add(OddMovieStack); readfile.add(EvenMovieStack);  //add our two stacks to readfile
    readfile.readInput();
    CRandom movieList{OddMovieStack, EvenMovieStack};
    CFantasyMovies movieNight("testTitle", "testNumber", OddMovieStack, EvenMovieStack, movieList);      //creat a CFantasy object to communicate with QML frontend
    srand(time(NULL));                  //generate a seed for the rand function to increase selection randomness


//******TEST
    qDebug() <<"CFantasySize: " << movieNight.size();



 //Default object connection

/*
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
*/








    //NOTES CONNECTION

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *topLevel = engine.rootObjects().at(0);


    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    //connect - from QML to C++
    QObject::connect(window, SIGNAL(userNumber(QString)),
                        &movieNight, SLOT(setUserRandomNumber(QString)));
    // connect - from C++ to QML
    QObject::connect(&movieNight,
                     SIGNAL(userRandomNumberChanged(QVariant)),
                     window, SLOT(qmlMovieUpdate(QVariant)));


    //Test connection c++ class to class
    //QObject::connect(&movieNight,
    //                 SIGNAL(userRandomNumberChanged(QString)),
    //                 &movieNight, SLOT(movieTitleChanged(QString)));




    return app.exec();
}

