/*This program will read a .txt file of Movie Titles
Sort those titles into two stacks and then based on user input 
Randomly select and display a title to the user*/

#include <iostream> 
#include <cstdlib>			//for size_t and rand 
#include <fstream>
#include <string>           //for getline
#include <time.h>           //for time() used with seeding 
#include "StackADT.h"


//function declarations
void OpenInputFile(std::ifstream& in_f);
//Postcondition: A file stream has been opened for input

std::string GetRandomTitle(Stack &source, int random_max);





int main()
{
    std::ifstream infile;                //variable for holding input file
    OpenInputFile(infile);              //call function to open input file 

    srand(time(NULL));                  //generate a seed for the rand function to increase selection randomness
    
    Stack OddMovieStack, EvenMovieStack, TempStack; //create three stacks to hold movies 

    
    int count = 0;                  //variable to help determine how many preceeeding characters need to be consumed before saving movie title string 
    

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

    
    size_t odd_stack_count = OddMovieStack.size();      //count for odd stack
    size_t even_stack_count = EvenMovieStack.size();    //count for even stack 

    std::string random_movie;       //create a variable to hold movie title for the randomly selected movie
    while (odd_stack_count > 0 || even_stack_count > 0) {
     
        std::cout << "Please input a number used to randomly select a movie title: \n";     //get a random number from user 
        int user_random_number;  std::cin >> user_random_number; 

        if (odd_stack_count && even_stack_count > 0) {              //first condition if there are movies in both the even and odd movie stack
            if (user_random_number % 2 == 0) {                      //if the user number indicates pulling from the even stack
                random_movie = GetRandomTitle(EvenMovieStack, EvenMovieStack.size());
                even_stack_count--;
            }
            else {                                                  //if the user number indicates pulling from the odd stack
                random_movie = GetRandomTitle(OddMovieStack, OddMovieStack.size());
                odd_stack_count--; 
            }
        }

        else if (odd_stack_count > 0) {                             //second condition: only odd stack titles available
            random_movie = GetRandomTitle(OddMovieStack, OddMovieStack.size());
            odd_stack_count--; 
        }

        else {                                                      //third condition: only even stack titles available
            random_movie = GetRandomTitle(EvenMovieStack, EvenMovieStack.size());
            even_stack_count--;
        }
            
        std::cout << "Your surprise movie is:  " << random_movie << std::endl;      //print surprise movie selection
    }

    if (odd_stack_count == 0 && even_stack_count == 0) {            //if both stacks are empty display message and quit 
        std::cout << "No other available films \n";
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


std::string GetRandomTitle(Stack &source, int random_max)
{
    int selection = rand() % random_max + 1;   
    Stack temp;
    while (source.size() > selection) {
        temp.push(source.pop());
    }
    std::string target = source.pop(); 
    while (temp.size() > 0) {
        source.push(temp.pop());
    }
    //std::cout << "Function found " << target <<std::endl; 
    return target; 
}