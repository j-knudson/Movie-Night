/*This program will read a .txt file of Movie Titles
Sort those titles into two stacks and then based on user input 
Randomly select and display a title to the user*/


//********************************NOTE*****************************************
//Current maximum input file size is 84   Each movie stack can hold up to 42 titles 
//To adjust maximum input file size change the capacity variable in StackADT.h

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

/*
class CReadFile : Stack {
    public: 
        void readInput(Stack A, Stack B, ifstream& infile) {
            int count = 0;                  //variable to help determine how many preceeeding characters need to be consumed before saving movie title string 


            while (!infile.eof()) {
                std::string line;   //create a variable to read a line of the file 
                char ch;            //variable needed to consume the number and period preceeding the movie title in the txt
                infile >> ch; infile >> ch; //consume first two characters

                if (count >= 9) {   //If number preceeding title is a two digit number and another character needs to be consumed
                    infile >> ch;
                }

                if (getline(infile, line))  //add a title to the odd movie stack 
                    A.push(line);
                count++;

                //consume characters preceeding movie title
                infile >> ch; infile >> ch; //consume first two characters
                if (count >= 9) {   //If number preceeding title is a two digit number and another character needs to be consumed
                    infile >> ch;
                }

                if (getline(infile, line))  //add a title to the even movie stack
                    B.push(line);
                count++;
            }
        }
};
*/

class CRandom               //attempt to create a CRandom class as an aggregation of Stack 
{
private: 
    Stack& m_stack;
public:
    CRandom(Stack& stack)
        :m_stack{ stack }
    {

    }
    std::string GetRandomTitle(int random_max)
    {
        int selection = rand() % random_max + 1;
        Stack temp;
        while (m_stack.size() > selection) {
            temp.push(m_stack.pop());
        }
        std::string target = m_stack.pop();
        while (temp.size() > 0) {
            m_stack.push(temp.pop());
        }
        //std::cout << "Function found " << target <<std::endl; 
        return target;
    }
};


int main()
{
    std::ifstream infile;                //variable for holding input file
    OpenInputFile(infile);              //call function to open input file 

    srand(time(NULL));                  //generate a seed for the rand function to increase selection randomness
    
    Stack OddMovieStack, EvenMovieStack, TempStack; //create three stacks to hold movies 

    
    int count = 0;                  //variable to help determine how many preceeeding characters need to be consumed before saving movie title string 
    
    //**********TEST
    CRandom odd{ OddMovieStack };
    CRandom even{ EvenMovieStack };
    //**********\TEST



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

    //********* TEST 
      std::string movieTest = odd.GetRandomTitle(OddMovieStack.size());
      std::cout << "I'm in test. This is odd movieTest: " << movieTest <<"\n";
      movieTest = even.GetRandomTitle(EvenMovieStack.size());
      std::cout << "I'm in test. This is even movieTest: " << movieTest << "\n";

    //************* \TEST 


    size_t odd_stack_count {OddMovieStack.size()};      //count for odd stack
    size_t even_stack_count = EvenMovieStack.size();    //count for even stack 

    std::string random_movie;       //create a variable to hold movie title for the randomly selected movie
    while (odd_stack_count > 0 || even_stack_count > 0) {   //if there are still movie titles in either stasck   
     
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