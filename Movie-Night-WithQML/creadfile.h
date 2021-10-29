#ifndef CREADFILE_H
#define CREADFILE_H
#include <functional>
#include <QDebug>
#include <QTextStream>
#include <QFile>

#include "stackadt.h"

class CReadFile
{
private:
    std::vector<std::reference_wrapper< Stack>> m_stacks{};     //create a wrapper to hold stacks
public:
    CReadFile();
    void add(Stack&);       //function to add a stack to the stacks collection
    Stack getEven();
    Stack getOdd();
    void replaceEven(Stack stack);
    void replaceOdd(Stack stack);
    int readInput();       //function to read values into a stack in the collection
};

#endif // CREADFILE_H
