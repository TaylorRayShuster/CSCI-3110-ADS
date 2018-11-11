/*
Taylor Ray Shuster
CSCI 3110-001
Project #4
Due: 10/12/2018

*/
#include "deck.h"

using std::cout;
using std::endl;
using std::swap;

Deck::Deck()
{
	for (int i = 0; i <= 12; i++)
	{
		this->theDeck[i] = Card(i, diamonds);
	}
	for (int i = 13; i <= 25; i++)
	{
		this->theDeck[i] = Card((i - 13), spades);
	}
	for (int i = 26; i <= 38; i++)
	{
		this->theDeck[i] = Card((i - 26), hearts);
	}
	for (int i = 39; i <= 51; i++)
	{
		this->theDeck[i] = Card((i - 39), clubs);
	}
	this->topCard = 51;
}

Card Deck::dealCard()
{
		this->topCard--;
		return this->theDeck[this->topCard + 1];
}

void Deck::Shuffle()
{
	for (int i = 0; i < this->numCards; i++)
	{
		int r = i + (rand() % (this->numCards - i));
		swap(this->theDeck[i], this->theDeck[r]);
	}
}

bool Deck::isEmpty()
{
	if (this->topCard == -1)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Deck& dk)
{
	for (int i = 51; i >= 0; i--)
	{
		if (i == 39 || i == 26 || i == 13 || i == 0)
			os << dk.theDeck[i] << endl;
		else
			os << dk.theDeck[i] << " ";
	}
	return os;
}