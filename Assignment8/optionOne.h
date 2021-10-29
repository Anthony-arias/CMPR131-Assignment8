// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include "Player.h"
#include "input.h"
#include <iostream>
#include<vector>

using namespace std;


void war(Card Player1, Card Player2, Deck*& deck1, Deck*& deck2)
{
	vector<Card>smallDeck1, smallDeck2;

	int count = 1;
	bool flag = true;

	if (deck1->isEmpty())
	{
		deck2->insert(Player1);
		deck2->insert(Player2);
		cout << "\n\tPlayer2 takes all because Player1 has no more card." << endl;
	}
	else if (deck2->isEmpty())
	{
		deck1->insert(Player1);
		deck1->insert(Player2);
		cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
	}
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
					deck2->insert(Player1);
					deck2->insert(Player2);
					for (int i = 1; i <= smallDeck1Size; i++)
					{
						deck2->insert(deck1->draw());
						deck2->insert(deck2->draw());
					}
					cout << "\n\tPlayer2 takes all because Player1 has no more card." << endl;
					flag = false;
				}
				else
				{
					deck1->insert(Player1);
					deck1->insert(Player2);
					for (int i = 1; i <= smallDeck2Size; i++)
					{
						deck1->insert(deck1->draw());
						deck1->insert(deck2->draw());
					}
					cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
					flag = false;
				}
			}
			else
			{
				if (smallDeck2Size < 4)
				{
					deck1->insert(Player1);
					deck1->insert(Player2);
					for (int i = 1; i <= smallDeck1Size; i++)
					{
						deck1->insert(deck1->draw());
						deck1->insert(deck2->draw());
					}
					cout << "\n\tPlayer1 takes all because Player2 has no more card." << endl;
					flag = false;
				}
				else
				{
					int size = 4 * count;
					for (int i = 0; i < size; i++)
					{
						smallDeck1.push_back(deck1->draw());
						smallDeck2.push_back(deck2->draw());
					}
					if (smallDeck1[size - 1] < smallDeck2[size - 1])
					{

						cout << "\n\tPlayer2 wins tie breaker!" << endl;
						deck2->insert(Player1);
						deck2->insert(Player2);
						for (int i = 0; i < size; i++)
						{
							deck2->insert(smallDeck1[i]);
							deck2->insert(smallDeck2[i]);
						}
						flag = false;

					}
					else if (smallDeck1[size - 1] > smallDeck2[size - 1])
					{
						cout << "\n\tPlayer1 wins tie breaker!" << endl;
						deck1->insert(Player1);
						deck1->insert(Player2);
						for (int i = 0; i < size; i++)
						{
							deck1->insert(smallDeck1[i]);
							deck1->insert(smallDeck2[i]);
						}
						flag = false;
					}
					else
					{
						cout << "\n\tPlayer1: " << smallDeck1[size - 1] << "\tPlayer2: " << smallDeck1[size - 1];
						cout << "\t ->Tie breaker again!" << endl;
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
			war(Player1.flipCard(), Player2.flipCard(), Player1Deck, Player2Deck);
		}
		pause("");
	}

	if (Player1Deck->isEmpty())
		cout << "\n\tPlayer2 wins the war with most number of cards(" << suitSize * 4 << ")." << endl;

	else 
		cout << "\n\tPlayer1 wins the war with most number of cards(" << suitSize * 4 << ")." << endl;


	delete Player1Deck;
	delete Player2Deck;
	return;
	
}



#endif