// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 8: Applications using Queues
// 10/28/2021


#include <iostream>
#include <string>
#include <vector>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "Patient.h"
#include "queue"
#include "input.h"
#include "Card.h"
#include "Deck.h"
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
    int suitSize = inputInteger("\n\tEnter a number of cards per suite (1..13): ", 1, 13);
    play(suitSize);
    pause("\n\nPress enter to return..");
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    clearScreen();
    cout << "\t2> Simulation of an emergency room (ER) using priority queue STL" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    priority_queue<Patient> priorityList;
    vector<Patient> transferedList;
    do
    {
        cout << "\n\t\t A> Register a patient";
        cout << "\n\t\t B> Transfer patient(s) to the designation";
        cout << "\n\t\t C> Display transferred patients";
        cout << "\n\t\t 0> return\n";
        cout << "\t" + string(100, char(205)) << endl;
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'A': registerPatient(priorityList); break;
        case 'B': transferPatients(priorityList, transferedList); break;
        case 'C': displayTransferedPatients(transferedList); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B' or 'C'" << endl;
        }
        cout << endl;
    } while (true);
}

//PreCondition: NA
//PostCondition: display the contents in program Three: Simulation of checkout lines at CostCo using multiple queues STL
void programThree(void)
{
    clearScreen();
	srand(time(NULL));
    cout << "\t3> Simulation of checkout lines at a CostCo warehouse store" << '\n';
    cout << "\t" + string(100, char(196)) << '\n';

	int operationTime = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int cashRegister = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);

	vector<queue<int>> availableCheckoutCashier; // use vector to store multiple queues

	for (int i = 0; i < cashRegister; i++)
		availableCheckoutCashier.push_back(queue<int>()); // vector will now store queue(s) based on the assigned cash register (from 1 to 10)

	// Randomly running program
	int checkout_estimateTime = rand() % 10 + 1; // checkout time
	int customerArrival_estimateTime = rand() % 5 + 1; // customers arrive
	int cashierIndex = 0; 
	int customerCapacity = 0;

	do
	{
		int leastBusiestCashier_capacity = availableCheckoutCashier.at(0).size();
		int leastBusiestCashier_index = 0;

		// Find the least busiest cashier line
		for (int i = 1; i < cashRegister; i++)
		{
			if (leastBusiestCashier_capacity > availableCheckoutCashier.at(i).size())
			{
				leastBusiestCashier_capacity = availableCheckoutCashier.at(i).size();
				leastBusiestCashier_index = i;
			}
		}

		//Add customer to the least busiest cashier
		availableCheckoutCashier.at(leastBusiestCashier_index).push(rand() % 100 + 1);
		customerCapacity++;

		clearScreen();
		if (customerCapacity > 0)
			displayCashierLine(availableCheckoutCashier, operationTime, customerCapacity);

		if (checkout_estimateTime == 0)
		{
			for (int i = cashierIndex; i < cashRegister; i++)
			{
				if (availableCheckoutCashier.at(i).size() > 0)
					availableCheckoutCashier.at(i).pop();
			}
			checkout_estimateTime = rand() % 10 + 2;
		}

		customerArrival_estimateTime--;
		checkout_estimateTime--;
		operationTime--;
	} while (operationTime >= 0);

	cout << "\n\n\t";
    system("pause");
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
