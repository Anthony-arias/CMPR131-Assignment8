#ifndef DECK_LOCK
#define DECK_LOCK

#include <algorithm>
#include <deque>
#include <iterator>
#include "Card.h"

using namespace std;

class Deck 
{
private: 
    deque<Card> cards;
    int thisSuitSize = 13;

public:

    // Precondition: suitSize cannot be less than 1 or greater than 13
    // Postcondition: Initializes a deck with the highest card being the suitSize provided
    Deck(int suitSize = 13) 
    {
        if (suitSize < 1 || suitSize > 13)
            return;

        for (int i = 1; i <= suitSize; i++) {
            Card c1(i), c2(i), c3(i), c4(i);
            cards.push_back(c1);
            cards.push_back(c2);
            cards.push_back(c3);
            cards.push_back(c4);
        }

        thisSuitSize = suitSize;
    }


    // Precondition: N/A
    // Postcondition: returns a card from the back of the deck
    Card draw() 
    {
        if (isEmpty()) 
        {
            Card temp(1);
            return temp;
        }

        Card temp(cards.back());
        cards.pop_back();
        return temp;
    }

    // Precondition: N/A
    // Postcondition: returns a card into the front of the deck
    void insert(Card card) 
    {
        cards.push_front(card);
    }

    // Precondition: N/A
    // Postcondition: shuffles the deck
    void shuffle() 
    {
        random_shuffle(cards.begin(), cards.end());
    }


    // Precondition: N/A
    // Postcondition: Returns false if the deck is not empty, true if empty
    bool isEmpty() {
        return cards.empty();
    }

    // Precondition: N/A
    // Postcondition: Returns sise of cards
    int getSize() {
        return cards.size();
    }

    // Precondition: input two decks
    // Postcondition: Split the original deck into two decks
    void splitInto(Deck* deck1, Deck* deck2) 
    {
        deck1->clearDeck();
        deck2->clearDeck();

        int halfpoint = (getSize() / 2);
        for (int i = 0; i < halfpoint; i++) {
            deck1->insert(draw());
        }

        while (!isEmpty())
            deck2->insert(draw());
    }
    // Precondition: N/A
    // Postcondition: Clear the deck
    void clearDeck() {
        cards.clear();
    }
};

#endif