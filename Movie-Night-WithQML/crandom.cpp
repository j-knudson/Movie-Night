#include "crandom.h"

// ********Inherit Version
/*
QString CRandom::GetEvenTitle(Stack& stack)                             //Function to return a random movie title from a stack and remove it from that stack
{

    Stack temp;
    stack = m_stacks.getEven();
    int selection = rand() % stack.size()+1;
    while (stack.size() > selection) {            //pop items off the stack unitl we reach our random value selection
         temp.push(stack.pop());                   //save the values we're popping in temp
    }
    QString title = stack.pop();             //save the value in the stack at our random selection
    return title;                                  //return the random value
}

QString CRandom::GetOddTitle(Stack& stack)
{
    Stack temp;
    //stack = m_stacks.getOdd();
    int selection = rand() % stack.size()+1;
    while (stack.size() > selection) {            //pop items off the stack unitl we reach our random value selection
         temp.push(stack.pop());                   //save the values we're popping in temp
    }
    QString title = stack.pop();             //save the value in the stack at our random selection
    return title;                                  //return the random value
}


Stack CRandom::GetStack(QString parity)
{

    if (parity.toInt() % 2 == 0){
        qDebug() <<"found an even stack";
        return m_stacks.getEven();
    }
    else {
        qDebug() <<"found an odd stack";
        return m_stacks.getOdd();
    }
}

QString CRandom::GetMovie(QString parity)
{
    Stack temp, stack;
    Stack odd = m_stacks.getOdd();
    QString title;
    if (parity.toInt() % 2 == 0) {
        if(!m_stacks.getEven().empty()){
            title = GetEvenTitle(stack);
        }
        else if (!m_stacks.getOdd().empty())
            title = GetOddTitle(stack);
        else
            title = "No movies available";
    }
    /*else if (!m_stacks.getOdd().empty()){
        title = GetOddTitle(stack);
        qDebug()<<"In odd else if";
        while(!stack.empty()){
             QString test = stack.pop();
             qDebug()<<"while loop stack items: "<<test;
        }
    }*/
    /*
    else if (!odd.empty()){
            title = GetOddTitle(odd);

            //TEST
            qDebug()<<"In odd else if before replace";
            while(!odd.empty()){
                 QString test = odd.pop();
                 qDebug()<<"while loop stack items: "<<test;
            }
            qDebug() <<"ODD Size: " << m_stacks.getOdd().size();
            //m_stacks.replaceOdd(odd);
            qDebug()<<"In odd else if after replace";
            qDebug() <<"ODD Size2: " << m_stacks.getOdd().size();
            while(!odd.empty()){
                 QString test = odd.pop();
                 qDebug()<<"after replace stack items: "<<test;
            }
            //</Test
    }
    else if (!m_stacks.getEven().empty())
        title = GetEvenTitle(stack);
    else
        title = "No movies available";


    /*if (parity.toInt() % 2 == 0){
        target = m_stacks.getEven().getRandom();
    }
    else {
        target = m_stacks.getOdd().getRandom();
        qDebug() <<"target is: "<< target;
    }*/
    /*
    return title;
}

void CRandom::test(QString tester)
{
    qDebug() <<"This is the string :" <<tester;
}
*/ //END OF INHERIT VERSION *********************

QString CRandom::GetRandomTitle(int)
{

}

QString CRandom::GetOddTitle()
{
    Stack temp;
    QString title;
    if (!m_stackOdd.empty()){
        int selection = rand() % m_stackOdd.size()+1;
        qDebug() <<"Selection: "<<selection <<"Odd size" << m_stackOdd.size();
        while (m_stackOdd.size() > selection) {            //pop items off the stack unitl we reach our random value selection
             temp.push(m_stackOdd.pop());                   //save the values we're popping in temp
        }
        while(temp.size() > 0)                //return titles back to odd
            m_stackOdd.push(temp.pop());
        title = m_stackOdd.pop();             //save the value in the stack at our random selection
    }
    else if (!m_stackEven.empty())
        return GetEvenTitle();
    else
        title = "No More Movies";
    qDebug() << "TITLE in GETODD: " <<title;
    return title;                                  //return the random value
}

QString CRandom::GetEvenTitle()
{
    Stack temp;
    QString title;
    qDebug() <<"In CRandom::GetEvenTitle   m_stackEven.size: "<<m_stackEven.size();
    if (!m_stackEven.empty()){
        qDebug() << "in stackEven not empty ";
        int selection = rand() % m_stackEven.size()+1;
        while (m_stackEven.size() > selection) {            //pop items off the stack unitl we reach our random value selection
             temp.push(m_stackEven.pop());                   //save the values we're popping in temp
        }
        title = m_stackEven.pop();             //save the value in the stack at our random selection
        qDebug() <<"In if  title: "<<title;
        while(temp.size() > 0)                //return titles back to odd
            m_stackEven.push(temp.pop());

    }
    else if (!m_stackOdd.empty()){
        qDebug() << "in stackOdd not empty ";
        return GetOddTitle();
    }
    else
        title = "No More Movies";
        //title = "How bout you work";
    qDebug() <<"Title before return title in GetEvenTitle: " <<title;
    return title;                                  //return the random value
}

Stack& CRandom:: GetOdd()
{
    return m_stackOdd;
}

Stack &CRandom::GetEven()
{
    return m_stackEven;
}

size_t CRandom::size()
{
    return m_stackEven.size()+m_stackOdd.size();
}
