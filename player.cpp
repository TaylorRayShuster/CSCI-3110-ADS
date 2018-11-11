/*
Taylor Ray Shuster
CSCI 3110-001
Project #4
Due: 10/12/2018

*/
#include "player.h"

using std::cout;
using std::endl;

Player::Player(string name)
{
	this->name = name;
	this->score = 0;
	for (int i = 0; i < this->Max_Cards; i++)
	{
		this->hasPlayed[i] = true;
	}
}

Card Player::playCard()
{
	int indexHighestPoint = 0;
	int valueHighestPoint = 0;
	Card play;

	for (int i = 0; i < this->Max_Cards; i++)
	{
		if (this->hand[i].getPointValue() > valueHighestPoint)
		{
			valueHighestPoint = this->hand[i].getPointValue();
			indexHighestPoint = i;
		}
	}
	play = this->hand[indexHighestPoint];
	this->hand[indexHighestPoint] = Card();
	this->hasPlayed[indexHighestPoint] = true;
	return play;
}

void Player::drawCard(Deck& dk)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->hasPlayed[i])
		{
			this->hand[i] = dk.dealCard();
			this->hasPlayed[i] = false;
		}
	}
}

void Player::addScore(Card acard)
{
	this->score += acard.getPointValue();
}

int Player::getScore() const
{
	return this->score;
}

string Player::getName() const
{
	return this->name;
}

bool Player::emptyHand() const
{
	if (this->hasPlayed[0] == true && this->hasPlayed[1] == true && this->hasPlayed[2] == true)
		return true;
	else
		return false;
}

ostream& operator<< (std::ostream& os, const Player& plr)
{
	os << plr.name << "'s hand: ";
	for (int i = 0; i < 3; i++)
	{
		if (plr.hasPlayed[i] == true)
			os << "_____ ";
		else
			os << plr.hand[i] << " ";
	}
	os << "with score " << plr.score << endl;
	return os;
}