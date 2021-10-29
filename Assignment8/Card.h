// Card.h
// Vincent Moreno & Van Luu

#ifndef CARD_LOCK
#define CARD_LOCK

#include<iostream>
using namespace std;

class Card
{
private:
	int value;
public:
	// Precondition: N/A
	// Postcondition: Initializes a card with the suite type and value
	Card(int newValue = 1)
	{
		value = newValue;
	}

	// Precondition: N/A
	// Postcondition: copies the value of card into this card
	Card(const Card& card) 
	{

		value = card.value;
	}

	// Precondition: N/A
	// Postcondition: Returns the value of the card
	int getValue() const 
	{
		return value;
	}

	// Precondition: Value shouldn't be lower than 1 and higher than 13
	// Postcondition: Sets the value to newValue
	void setValue(const int newValue) 
	{
		if (newValue < 1 || newValue > 13)
			value = 1;
		else
			value = newValue;
	}

	// Precondition: compare two cards
	// Postcondition: return true if the left card value less than the right one and otherwise return false
	bool operator <(const Card& card)
	{
		if (value < card.value)
			return true;

		return false;
	}
	// Precondition: compare two cards
	// Postcondition: return true if the left card value greater than the right one and otherwise return false
	bool operator >(const Card& card) 
	{
		if (value > card.value)
			return true;

		return false;
	}
	// Precondition: compare two cards
	// Postcondition: return true if the left card value less or equal than the right one and otherwise return false
	bool operator <=(const Card& card) 
	{
		if (value <= card.value)
			return true;

		return false;
	}
	// Precondition: compare two cards
	// Postcondition: return true if the left card value equal or greater than the right one and otherwise return false
	bool operator >=(const Card& card) 
	{
		if (value >= card.value)
			return true;

		return false;
	}
	// Precondition: compare two cards
	// Postcondition: return true if the left card value equal than the right one and otherwise return false
	bool operator ==(const Card& card) 
	{
		if (value == card.value)
			return true;

		return false;
	}

	// Precondition: input cart
	// Postcondition: support cout function

	friend ostream& operator << (ostream& out, const Card& card) 
	{

		out << card.value;

		return out;

	}

};

#endif