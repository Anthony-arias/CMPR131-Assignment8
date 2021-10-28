// optionThree.h
// Team: Anthony, An, Van, Vincent, Nhan
#include <iostream>
#include <queue>
#include "input.h"
#include <vector>

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

// Functions Prototype
void displayCashierLine(vector<queue<int>> v, int operationTime, int customerCapacity);

// Functions Implementation

// Precondition: NA
// Postcondition: display the content of cashier lines
void displayCashierLine(vector<queue<int>> v, int operationTime, int customerCapacity)
{
	cout << "\n\tCostCo Warehouse stores " << operationTime << "\t\t Number of served customers: " << customerCapacity << "\n";

	string customer_in_line = string(3, char(254));

	for (int i = 0; i < v.size(); i++)
	{
		cout << "\n\t\tCash register #" << i + 1 << ": \n";
		queue<int> temp = v.at(i); // this queue will display the symbol
		cout << "\t\t\t\t";
		for (int j = 0; j < v.at(i).size(); j++)
		{
			int temp_val = temp.front();
			if (j == 0)
				cout << char(254) + to_string(temp_val) + char(254) << " ";
			else
				cout << customer_in_line << " ";

			temp.pop();
		}
	}
}
#endif
