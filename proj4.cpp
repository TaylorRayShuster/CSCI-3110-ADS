/*
Taylor Ray Shuster
CSCI 3110-001
Project #4
Due: 10/12/2018
	
	Write a C++ program to simulate a simple card game between two players. The game should proceed as follows: The
52 cards in a deck of cards are shuffled and each player draws three cards from the top of the deck. The remaining cards
are placed in a pile face-down between the two players. Players then select one of the three cards in hand and
simultaneously place the chosen card face-up on the game table. The player who places the highest ranking card on the
table collects both cards and adds them to their pile (score). If both cards have the same value the hand is a draw and
no points are accumulated. Following the completion of a hand, each player draws the top card from the deck to add to
their hand. Play continues until all cards have been played. The winner is the player with the most points at game’s end.
You will use a standard deck of 52 cards where there are thirteen cards from each of four suits: hearts, spades,
diamonds, and clubs. The thirteen cards in point order are the 2-10 numbered cards, the face cards (Jack, Queen, King),
and the Ace card. Points are distributed as follows: Ace=15, face cards=10, all other cards count as their numeric value. 
*/
#include "player.h"

using std::cout;
using std::endl;

void simulateHand(Player&, Player&, Deck&);

int main()
{
	srand(1000);
	Player One = Player("Taylor");
	Player Two = Player("Erika");
	Deck Deck;

	cout << "The original deck has the following cards" << endl;
	cout << Deck << endl;
	Deck.Shuffle();
	cout << "The deck after shuffling (top of deck listed first)" << endl;
	cout << Deck;

	One.drawCard(Deck);
	Two.drawCard(Deck);
	One.drawCard(Deck);
	Two.drawCard(Deck);
	One.drawCard(Deck);
	Two.drawCard(Deck);

	int hand = 1;
	while (!(One.emptyHand() && Two.emptyHand()))
	{
		cout << "************** Hand " << hand << " **************" << endl;
		simulateHand(One, Two, Deck);
		hand++;
	}
	if (One.getScore() > Two.getScore())
		cout << One.getName() << " wins with a score of " << One.getScore() << endl;
	else if (Two.getScore() > One.getScore())
		cout << Two.getName() << " wins with a score of " << Two.getScore() << endl;
	else 
		cout << "The game has ended in a draw with a score of " << One.getScore() << endl;

	return 0;
}

void simulateHand(Player& One, Player& Two, Deck& Deck)
{
	Card onePlay;
	Card twoPlay;

	cout << One;
	cout << Two << endl;
	onePlay = One.playCard();
	twoPlay = Two.playCard();
	cout << One.getName() << " played card: " << onePlay << " --- " << Two.getName() << " played card: " << twoPlay << endl << endl; 
	if (onePlay > twoPlay)
	{
		cout << One.getName() << " wins this hand" << endl;
		One.addScore(onePlay);
		One.addScore(twoPlay);
	}
	else if (onePlay < twoPlay)
	{
		cout << Two.getName() << " wins this hand" << endl;
		Two.addScore(onePlay);
		Two.addScore(twoPlay);
	}
	else if(onePlay == twoPlay)
	{
		cout << "This hand is a draw - The cards are of equal value" << endl;
	}
	cout << One;
	cout << Two << endl;
	if (!Deck.isEmpty())
	{
		One.drawCard(Deck);
		Two.drawCard(Deck);
	}
	return;
}