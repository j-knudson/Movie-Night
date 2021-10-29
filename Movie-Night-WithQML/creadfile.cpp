#include "creadfile.h"


CReadFile::CReadFile()
{

}

void CReadFile::add(Stack & stack)
{
    m_stacks.push_back(stack);
}

Stack CReadFile::getEven()
{
    return m_stacks.back();
}

Stack CReadFile::getOdd()
{
    return m_stacks.front();
}

void CReadFile::replaceEven(Stack stack)
{
    m_stacks[1]=stack;
}

void CReadFile::replaceOdd(Stack stack)
{
    Stack temp2, temp3;
    for (auto& stack : m_stacks) {
        //temp2 = m_stacks.front();
        while(!stack.get().empty()){
             QString test = stack.get().pop();
             temp2.push(test);
             qDebug()<<"Before replace loop: "<<test;
        }
    }
    m_stacks.push_back(temp2);


    Stack temp = m_stacks.back();
    m_stacks.pop_back(); m_stacks.pop_back();
    m_stacks.push_back(stack);
    m_stacks.push_back(temp);

    qDebug() << "replaced stack";
    for (auto& stack : m_stacks) {
        //temp2 = m_stacks.front();
        while(!stack.get().empty()){
             QString test = stack.get().pop();
             temp3.push(test);
             qDebug()<<"After replace loop: "<<test;
        }
    }
     m_stacks.push_back(temp3);
}


int CReadFile::readInput()
{
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
            stack.get().push(line);    //get a stack and add the movie title to it
            count++;                   //increment counter to know how many characters need to be consumed
        }
    }
    return count;
}
