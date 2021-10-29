#pragma once
#include <string>
using namespace std;

class Patient
{
private:
	int priority;
	unsigned int checkedInTime;
	string name;
	int age;
	char gender;
	unsigned int admittedTime;
	string careUnit;
	static string ER_description[5];
public:

	// Default constructor
	Patient()
	{
		checkedInTime;
		priority = 0;
		name = "unknown";
		age = 0;
		gender = 'u';
	}

	// Precondition: valid input
	// Postcondition: assign value
	void setCheckedInTime(unsigned int t)
	{
		this->checkedInTime= t;
	}

	// Precondition: NA
	// Postcondition: return value
	unsigned int getCheckedInTime() const
	{
		return checkedInTime;
	}

	// Precondition: valid input
	// Postcondition: assign value
	void setPriority(int priority)
	{
		this->priority = priority;
	}

	// Precondition: NA
	// Postcondition: return value
	int getPriority() const
	{
		return priority;
	}

	// Precondition: valid input
	// Postcondition: assign value
	void setName(string name)
	{
		this->name = name;
	}

	// Precondition: NA
	// Postcondition: return value
	string getName() const
	{
		return name;
	}

	// Precondition: valid input
	// Postcondition: assign value
	void setAge(int age)
	{
		this->age = age;
	}

	// Precondition: NA
	// Postcondition: return value
	int getAge() const
	{
		return age;
	}

	// Precondition: valid input
	// Postcondition: assign value
	void setGender(char gender)
	{
		this->gender = gender;
	}
	 
	// Precondition: valid input
	// Postcondition: assign value
	char getGender() const
	{
		return gender;
	}

	friend bool operator <(const Patient& P1, const Patient& P2); //key in priority queue

	friend ostream& operator<<(ostream& outs, const Patient& obj);
};

// Precondition: valid input
// Postcondition: return true if object 1 is smaller than object 2
bool operator <(const Patient& P1, const Patient& P2)
{
	return P1.priority < P2.priority;
}

string Patient::ER_description[5] = { "Stable, with no resources anticipated or prescriptions", "Stable, with only one type of resource anticipated " ,"Stable, with multiple types of resources needed to investigate or treat", "High risk of deterioration, or signs of a time-critical problem", "Immediate, life-saving intervention required without delay" };

// Precondition: valid input
// Postcondition: overloading operator << 
ostream& operator <<(ostream& outs, const Patient& obj)
{
	outs << "ER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority()-1] << '\n';
	outs << "\t\t\tChecked-In time: " << obj.getCheckedInTime() << '\n';
	outs << "\t\t\tPatient's name: " << obj.getName() << '\n';
	outs << "\t\t\tPatient's age: " << obj.getAge() << '\n';
	outs << "\t\t\tPatient's gender: " << obj.getGender() << '\n';
	return outs;
}
