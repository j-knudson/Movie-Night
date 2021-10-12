/*This program will read a .txt file of Movie Titles
Sort those titles into two stacks and then based on user input 
Randomly select and display a title to the user*/

#include <iostream> 
#include <cstdlib>			//for size_t and rand 
#include <fstream>
#include <string>           //for getline
#include "StackADT.h"


//function declarations
void OpenInputFile(std::ifstream& in_f);
//Postcondition: A file stream has been opened for input





int main()
{
    std::ifstream infile;                //variable for holding input file
    OpenInputFile(infile);              //call function to open input file 

    Stack OddMovieStack, EvenMovieStack, TempStack; //create three stacks to hold movies 

    //***** test variable
    int count = 0; 
    //**** test variable 

    while (!infile.eof()) {
        std::string line;   //create a variable to read a line of the file 
        char ch;            //variable needed to consume the number and period preceeding the movie title in the txt
        infile >> ch; infile >> ch; //consume first two characters
        
        if (count >= 9) {   //If number preceeding title is a two digit number and another character needs to be consumed
            infile >> ch; 
        }
        
        if (getline(infile, line))  //add a title to the odd movie stack 
            OddMovieStack.push(line);
        count++;

        //consume characters preceeding movie title
        infile >> ch; infile >> ch; //consume first two characters
        if (count >= 9) {   //If number preceeding title is a two digit number and another character needs to be consumed
            infile >> ch;
        }

        if (getline(infile, line))  //add a title to the even movie stack
            EvenMovieStack.push(line);
        count++;
    }

    std::cout << count<< std::endl;
    size_t odd_stack_count = OddMovieStack.size(); 
    size_t even_stack_count = EvenMovieStack.size(); 

    //test
    std::cout << odd_stack_count << std::endl; 
    std::cout << even_stack_count << std::endl;

    while (OddMovieStack.size() > 0) {
        std::string title;
        title = OddMovieStack.pop(); 
        std::cout << title <<std::endl; 
    }

    while (EvenMovieStack.size() > 0) {
        std::string title;
        title = EvenMovieStack.pop();
        std::cout << title << std::endl;
    }


    return EXIT_SUCCESS;
}



void OpenInputFile(std::ifstream& in_f)    //function to open an input file
{
    std::string input_filename;              //filename to be opened stored as string
    do {                                //do while to ensure file opens
        in_f.close();
        in_f.clear();
        std::cout << "Please enter an input file name: \n";
        std::cin >> input_filename;
        in_f.open(input_filename.c_str());
    } while (in_f.fail());
}