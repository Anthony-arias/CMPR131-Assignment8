// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 8: Applications using Queues
// 10/14/2021


#include <iostream>
#include <string>
#include "optionOne.h""
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"

void displayMainMenu(void);
void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: return;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: 
void programOne(void)
{
    clearScreen();
    cout << "\t1> Simulation of War (card game) using deque STL" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    /*stuff here*/
    pause("\tdelete this");
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    clearScreen();
    cout << "\t2> Simulation of an emergency room (ER) using priority queue STL" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    /*stuff here*/
    pause("\tdelete this");
}

//PreCondition: NA
//PostCondition:
void programThree(void)
{
    clearScreen();
    cout << "\t3> Simulation of checkout lines at a CostCo warehouse store" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    /*stuff here*/
    pause("\tdelete this");
}


//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 8: Applications using Queues by Anthony, An, Van, Vincent, Nhan (10/28/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Simulation of War (card game) using deque STL" << endl;
    cout << "\t\t2> Simulation of an emergency room (ER) using priority queue STL" << endl;
    cout << "\t\t3> Simulation of checkout lines at CostCo using multiple queues STL" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}