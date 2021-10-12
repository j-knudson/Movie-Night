/*This program will read a .txt file of Movie Titles
Sort those titles into two stacks and then based on user input 
Randomly select and display a title to the user*/

#include <iostream> 
#include <cstdlib>			//for size_t and rand 
#include <fstream>
#include "StackADT.h"


//function declarations
void OpenInputFile(std::ifstream& in_f);
//Postcondition: A file stream has been opened for input



int main()
{
    std::ifstream infile;                //variable for holding input file
    OpenInputFile(infile);          //call function to open input file 
    



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