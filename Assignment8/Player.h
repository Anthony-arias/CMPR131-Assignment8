#ifndef PLAYER_LOCK
#define PLAYER_LOCK

#include "Deck.h"

class Player 
{
private: 
	Card card;
	Deck* deck;
public:
	
	// Precondition: N/A
	// Postcondition: Player takes in an initialized deck
	Player(Deck* newDeck) 
	{
		deck = newDeck;
	}

	// Precondition: N/a
	// Postcondition: Player draws a card from the deck
	bool draw() 
	{
		if (!deck->isEmpty()) 
		{
			card = deck->draw();
			return true;
		}

		return false;
	}

	// Precondition: input card
	// Postcondition: insert the card into the deck

	void insert(const Card card) 
	{
		deck->insert(card);
	}

	// Precondition: N/A
	// Postcondition: this card is returned;
	Card flipCard() 
	{
		return this->card;
	}
	// Precondition: input newdeck
	// Postcondition: set new value for the deck
	void setDeck(Deck &newDeck) 
{
		deck = &newDeck;
	}

	// Precondition: NA
	// Postcondition: get deck size
	int getDeckSize() const {
		return deck->getSize();
	}

};

#endif