// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include "Player.h"
#include "input.h"
#include <iostream>
#include<vector>

using namespace std;


void war(Player Player1, Player Player2, Deck*& deck1, Deck*& deck2)
{
	vector<Card>smallDeck1, smallDeck2;

	int count = 1;
	bool flag = true;

	if (deck1->isEmpty())
		cout << "\n\tPlayer2 takes all because Player1 has no more card." << endl;
	else if (deck2->isEmpty())
		cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
	else
	{
		do
		{
			int smallDeck1Size = deck1->getSize();
			int smallDeck2Size = deck2->getSize();
			if (smallDeck1Size < 4)
			{
				if ((smallDeck2Size < 4 && smallDeck1Size <= smallDeck2Size) || smallDeck2Size >= 4)
				{
					for (int i = 1; i < smallDeck1Size; i++)
					{
						Player1.draw();
						Player2.draw();
						Player2.insert(Player2.flipCard());
						Player2.insert(Player1.flipCard());
					}
					cout << "\n\tPlayer2 takes all because Player1 has no more card." << endl;
					flag = false;
				}
				else
				{
					for (int i = 1; i < smallDeck2Size; i++)
					{
						Player1.draw();
						Player2.draw();
						Player1.insert(Player1.flipCard());
						Player1.insert(Player2.flipCard());
					}
					cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
					flag = false;
				}
			}
			else
			{
				if (smallDeck2Size < 4)
				{
					for (int i = 1; i < smallDeck2Size; i++)
					{
						Player1.draw();
						Player2.draw();
						Player1.insert(Player1.flipCard());
						Player1.insert(Player2.flipCard());
					}
					cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
					flag = false;
				}
				else
				{
					int size = 4 * count;
					for (int i = 0; i < size; i++)
					{
						Player1.draw();
						Player2.draw();
						smallDeck1.push_back(Player1.flipCard());
						smallDeck2.push_back(Player2.flipCard());
					}
					if (smallDeck1[size - 1] < smallDeck2[size - 1])
					{
						cout << "\n\tPlayer2 wins tie breaker!" << endl;
						for (int i = 0; i < size; i++)
						{
							Player2.insert(smallDeck1[i]);
							Player2.insert(smallDeck2[i]);
						}
						flag = false;

					}
					else if (smallDeck1[size - 1] > smallDeck2[size - 1])
					{
						cout << "\n\tPlayer1 wins tie breaker!" << endl;
						for (int i = 0; i < size; i++)
						{
							Player1.insert(smallDeck1[i]);
							Player1.insert(smallDeck2[i]);
						}
						flag = false;
					}
					else
					{
						cout << "\n\t-> Tie breaker again!" << endl;
						count++;
					}

				}
			}
		} while (flag);
	}

}

// Precondition: suitSize must be between 1 and 13
// Postcondition: Plays a card game of War
void play(int suitSize) 
{
	Deck deck(suitSize);
	deck.shuffle();

	Deck* Player1Deck = new Deck;
	Deck* Player2Deck = new Deck;
	
	deck.splitInto(Player1Deck, Player2Deck);

	Player Player1(Player1Deck);
	Player Player2(Player2Deck);


	while (!Player1Deck->isEmpty() && !Player2Deck->isEmpty())
	{
		Player1.draw();
		Player2.draw();

		cout << "\n\tPlayer1: " << Player1.flipCard() << "\tPlayer2: " << Player2.flipCard();

		if (Player1.flipCard() < Player2.flipCard()) 
		{
			Player2.insert(Player2.flipCard());
			Player2.insert(Player1.flipCard());
			cout << "\t ->Player2 wins!" << endl;
		}	
		else if (Player1.flipCard() > Player2.flipCard()) 
		{
			Player1.insert(Player1.flipCard());
			Player1.insert(Player2.flipCard());
			cout << "\t ->Player1 wins!" << endl;
		}
		else if (Player1.flipCard() == Player2.flipCard()) 
		{
			cout << "\t ->Tie breaker begins!" << endl;
			war(Player1, Player2, Player1Deck, Player2Deck);
		}
		pause("");
	}

	if (Player1Deck->isEmpty()) 
	{
		cout << "\n\tPlayer2 takes all because Player1 has no more card." << endl;
	}

	if (Player2Deck->isEmpty()) 
	{
		cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
	}

	delete Player1Deck;
	delete Player2Deck;
	return;
	
}



#endif