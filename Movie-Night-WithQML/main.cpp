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

/*
class CReadFile {
    private:
        std::vector<std::reference_wrapper< Stack>> m_stacks{};     //create a wrapper to hold stacks

    public:
        void add(Stack& stack) {
            m_stacks.push_back(stack);
        }
        void readInput() {
            int count = 0;                  //variable to help determine how many preceeeding characters need to be consumed before saving movie title string

            QFile inputfile("C:/Users/knuds/Desktop/Fall 2021/Se460/QT/MontyV2/movie_list.txt");                //variable for holding input file
            //QFile infile("QT:/movie_list.txt");
            if(!inputfile.exists())                                                                             //try to find input file
            {
                qCritical() << "File not found";                                                             //error message if file not found
            }
            if(!inputfile.open(QIODevice::ReadOnly))                                                            //try to open input file
            {
                qCritical() << "Could not open file";
                qCritical() <<inputfile.errorString();                                                          //error message if file could not be opened
            }


            QTextStream infile(&inputfile);
            //qDebug() <<"About to read";
            while (!infile.atEnd()) {
                QString line;   //create a variable to read a line of the file
                char ch;            //variable needed to consume the number and period preceeding the movie title in the txt

                for (auto& stack : m_stacks) {
                    infile >> ch; infile >> ch; //consume first two characters

                    if (count >= 9) {   //If number preceeding title is a two digit number and another character needs to be consumed
                        infile >> ch;
                    }
                    line = infile.readLine();  //add a title to the movie stack
                   // qDebug() << line;
                    stack.get().push(line);
                    count++;
                }
            }
        }
};
*/

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
    //int movieCount = readfile.readInput();                                 //call readfile readInput to add values from infile to the stacks
    readfile.readInput();
    CRandom movieList{OddMovieStack, EvenMovieStack};  //create CRandom object and add stacks to it
    CFantasyMovies movieNight(OddMovieStack, EvenMovieStack);



 //Default object connection

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    //CFantasyMovies movieNight;      //creat a CFantasy object to communicate with QML frontend


/*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *topLevel = engine.rootObjects().at(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    // connect - from QML to C++
    QObject::connect(window, SIGNAL(userNumber(QString)),
                         &movieNight, SLOT(setUserRandomNumber(QString)));
    // connect - from C++ to QML
    QObject::connect(&movieNight,
                     SIGNAL(movieTitleChanged(QString)),
                     window, SLOT(qmlMovieUpdate(QString)));

    //Test connection c++ class to class
    QObject::connect(&movieNight,
                     SIGNAL(userRandomNumberChanged(QString)),
                     &movieNight, SLOT(movieTitleChanged(QString)));
*/

    srand(time(NULL));                  //generate a seed for the rand function to increase selection randomness

    //Stack OddMovieStack, EvenMovieStack; //create two stacks to hold movies
    //CReadFile readfile{};   //create empty CReadFile
    //readfile.add(OddMovieStack); readfile.add(EvenMovieStack);  //add our two stacks to readfile
    //int movieCount = readfile.readInput();                                 //call readfile readInput to add values from infile to the stacks
                                                          //file location is static and defined in the CReadFile class

    //qDebug() <<"MovieCount: " <<movieCount;
    //size_t odd_stack_count {OddMovieStack.size()};      //count for odd stack
    //size_t even_stack_count = EvenMovieStack.size();    //count for even stack

    //CRandom movieList{OddMovieStack, EvenMovieStack};  //create CRandom object and add stacks to it
    //CFantasyMovies movieNight(OddMovieStack, EvenMovieStack

    //Test Code
    /*while (!movieList.GetOdd().empty()&& !movieList.GetEven().empty())
    {
        QString newTest = movieList.GetOddTitle();
        qDebug() <<"This is my new Crandom test loop: " <<newTest;
        newTest = movieList.GetEvenTitle();
        qDebug() <<"Even Crandom test loop: " <<newTest;
    }*/

/*
    while (odd_stack_count > 0 || even_stack_count > 0) {   //if there are still movie titles in either stasck

        //QTextStream out(stdout); out << "Please input a number used to randomly select a movie title: ";     //get a random number from user

        int user_random_number = movieNight.getUserRandomNumber().toInt();
        qDebug() << "This is user_random_number in while loop: " << user_random_number;
        if (odd_stack_count && even_stack_count > 0) {              //first condition if there are movies in both the even and odd movie stack
            if (user_random_number % 2 == 0) {                      //if the user number indicates pulling from the even stack
                random_movie = even.GetRandomTitle(EvenMovieStack.size());;
                even_stack_count--;
                movieNight.setMovieTitle(random_movie);
                qDebug() <<"This is random_movie: " <<random_movie;
            }
            else {                                                  //if the user number indicates pulling from the odd stack
                random_movie = odd.GetRandomTitle(OddMovieStack.size());
                odd_stack_count--;
                movieNight.setMovieTitle(random_movie);
                qDebug() <<"This is Odd random_movie: " <<random_movie;
            }
        }

        else if (odd_stack_count > 0) {                             //second condition: only odd stack titles available
            random_movie = odd.GetRandomTitle(OddMovieStack.size());
            odd_stack_count--;
            movieNight.setMovieTitle(random_movie);
        }

        else {                                                      //third condition: only even stack titles available
            random_movie = even.GetRandomTitle(EvenMovieStack.size());;
            even_stack_count--;
            movieNight.setMovieTitle(random_movie);
        }

        //out << "Your surprise movie is:  " << random_movie << "\n";      //print surprise movie selection

    }

    if (odd_stack_count == 0 && even_stack_count == 0) {            //if both stacks are empty display message and quit
       QTextStream out(stdout); out << "No other available films \n";
       movieNight.setMovieTitle("No other available films");
    }
*/

    return app.exec();
}

