// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK
#include <iostream>
#include <string>
#include "Patient.h"
#include "input.h"
#include "queue"

//PreCondition: input a priority queue patient
//PostCondition: Adding a patient into the queue
void registerPatient(priority_queue<Patient> &priorityList)
{
	Patient patient;
	patient.setName(inputString("\n\t\tEnter the patient's name: ", true));
	patient.setAge(inputInteger("\t\tEnter the patient's age: ", true));
	patient.setCheckedInTime(time(0));
	patient.setGender(toupper(inputChar("\t\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M')));
	patient.setPriority(inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
	priorityList.push(patient); // enqueue
	cout << "\n\t\tPatient information has been registered.\n";
}

//PreCondition: input a priority queue patient and a vector patient
//PostCondition: transfer patients from the queue to the vector
void transferPatients(priority_queue<Patient>& priorityList, vector<Patient> &transferedList)
{
	if (priorityList.empty())
		cout << "\n\t\tNo patients in the list" << endl;
	else
	{
		while (!priorityList.empty())
		{
			if (priorityList.top().getPriority() == 5)
			{
				transferedList.push_back(priorityList.top());
				cout << "\n\t\t" << priorityList.top().getName() << " - transfers to ICU...\n";
				priorityList.pop(); // dequeue
			}
			else if (priorityList.top().getPriority() == 4)
			{
				transferedList.push_back(priorityList.top());
				cout << "\n\t\t" << priorityList.top().getName() << " - transfers to surgery room...\n";
				priorityList.pop();
			}
			else if (priorityList.top().getPriority() == 3)
			{
				transferedList.push_back(priorityList.top());
				cout << "\n\t\t" << priorityList.top().getName() << " - transfers to emergency room...\n";
				priorityList.pop();
			}
			else if (priorityList.top().getPriority() == 2)
			{
				transferedList.push_back(priorityList.top());
				cout << "\n\t\t" << priorityList.top().getName() << " - transfers to xray lab...\n";
				priorityList.pop();
			}
			else if (priorityList.top().getPriority() == 1)
			{
				transferedList.push_back(priorityList.top());
				cout << "\n\t\t" << priorityList.top().getName() << " - examines and gives prescription...\n";
				priorityList.pop();
			}
		}
	}
}

//PreCondition: input a vector patient
//PostCondition: showing patient information into the screen
void displayTransferedPatients(vector<Patient> transferedList)
{
	if (!transferedList.empty())
	{
		sort(transferedList.begin(), transferedList.end());
		reverse(transferedList.begin(), transferedList.end());
		cout << '\n';
		for (int i = 0; i < transferedList.size(); i++)
			cout << "\t\t" << i + 1 << " - " << transferedList[i] << '\n';
	}
	else
		cout << "\n\t\tNo patient has been transferred.\n";
}
#endif