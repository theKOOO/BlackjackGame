/**************************************************************************************
Implementation file BlackJack.cpp implements the member functions of BlackJack.h file.

					Casino Final Project

						BlackJack.cpp
**************************************************************************************/
#include <iostream>

using namespace std;

#include "Card.h"
#include "BlackJack.h"

//--- Definition of BlackJack constructor
BlackJack::BlackJack()
	:playerTotal(0), dealerTotal(0)
{
	myDeck.push_back(Card("Ace", 11, "Hearts"));
	myDeck.push_back(Card("Ace", 11, "Diamonds"));
	myDeck.push_back(Card("Ace", 11, "Spades"));
	myDeck.push_back(Card("Ace", 11, "Clubs"));
	myDeck.push_back(Card("King", 10, "Hearts"));
	myDeck.push_back(Card("King", 10, "Diamonds"));
	myDeck.push_back(Card("King", 10, "Spades"));
	myDeck.push_back(Card("King", 10, "Clubs"));
	myDeck.push_back(Card("Queen", 10, "Hearts"));
	myDeck.push_back(Card("Queen", 10, "Diamonds"));
	myDeck.push_back(Card("Queen", 10, "Spades"));
	myDeck.push_back(Card("Queen", 10, "Clubs"));
	myDeck.push_back(Card("Jack", 10, "Hearts"));
	myDeck.push_back(Card("Jack", 10, "Diamonds"));
	myDeck.push_back(Card("Jack", 10, "Spades"));
	myDeck.push_back(Card("Jack", 10, "Clubs"));
	myDeck.push_back(Card("Ten", 10, "Hearts"));
	myDeck.push_back(Card("Ten", 10, "Diamonds"));
	myDeck.push_back(Card("Ten", 10, "Spades"));
	myDeck.push_back(Card("Ten", 10, "Clubs"));
	myDeck.push_back(Card("Nine", 9, "Hearts"));
	myDeck.push_back(Card("Nine", 9, "Diamonds"));
	myDeck.push_back(Card("Nine", 9, "Spades"));
	myDeck.push_back(Card("Nine", 9, "Clubs"));
	myDeck.push_back(Card("Eight", 8, "Hearts"));
	myDeck.push_back(Card("Eight", 8, "Diamonds"));
	myDeck.push_back(Card("Eight", 8, "Spades"));
	myDeck.push_back(Card("Eight", 8, "Clubs"));
	myDeck.push_back(Card("Seven", 7, "Hearts"));
	myDeck.push_back(Card("Seven", 7, "Diamonds"));
	myDeck.push_back(Card("Seven", 7, "Spades"));
	myDeck.push_back(Card("Seven", 7, "Clubs"));
	myDeck.push_back(Card("Six", 6, "Hearts"));
	myDeck.push_back(Card("Six", 6, "Diamonds"));
	myDeck.push_back(Card("Six", 6, "Spades"));
	myDeck.push_back(Card("Six", 6, "Clubs"));
	myDeck.push_back(Card("Five", 5, "Hearts"));
	myDeck.push_back(Card("Five", 5, "Diamonds"));
	myDeck.push_back(Card("Five", 5, "Spades"));
	myDeck.push_back(Card("Five", 5, "Clubs"));
	myDeck.push_back(Card("Four", 4, "Hearts"));
	myDeck.push_back(Card("Four", 4, "Diamonds"));
	myDeck.push_back(Card("Four", 4, "Spades"));
	myDeck.push_back(Card("Four", 4, "Clubs"));
	myDeck.push_back(Card("Three", 3, "Hearts"));
	myDeck.push_back(Card("Three", 3, "Diamonds"));
	myDeck.push_back(Card("Three", 3, "Spades"));
	myDeck.push_back(Card("Three", 3, "Clubs"));
	myDeck.push_back(Card("Two", 2, "Hearts"));
	myDeck.push_back(Card("Two", 2, "Diamonds"));
	myDeck.push_back(Card("Two", 2, "Spades"));
	myDeck.push_back(Card("Two", 2, "Clubs"));

	origDeck=myDeck;//creates copy of myDeck that will be used to reassign
					// myDeck to its original values in reset method
}

//--- Definition of getPTotal()
void BlackJack::getPTotal() const
{
	cout<<"Player Total: "<< playerTotal<<endl;
}

//--- Definition of playerMove()
void BlackJack::playerMove()
{	   	
	playerTotal+=Distribute(playersHand);
}

//--- Definition of dealerMove()
void BlackJack::dealerMove()
{	   	
	dealerTotal+=Distribute(dealersHand);
}

//--- Definition of displayPlayerHand()
void BlackJack::displayPlayerHand()
{
	Card cc;
	cout<<"   ______________________________________\n"
		<<"               Your Hand \n\t";
	for(int i =0; i<  playersHand.size(); i++)
	{
		cc=playersHand[i];
		cout<< cc.getCardValue() << "\t";
	}
	cout<<"\n   ______________________________________\n"<<endl;
}

//---Definition of displayDealerHand()
void BlackJack::displayDealerHand()
{
	Card cc;
	cout<<"   ______________________________________\n"
		<<"               Dealer Hand \n\t";
	for(int i =0; i<  dealersHand.size(); i++)
	{
		cc=dealersHand[i];
		cout<<cc.getCardValue() << "\t";
	}
	cout<<"\n   ______________________________________\n"<<endl;
}

//--- Definition of Distribute()
int BlackJack::Distribute(vector<Card> & hand)
{
	int index = rand() % myDeck.size(); //gets random number
	chosenCard=myDeck[index];
	myDeck.erase(myDeck.begin()+(index+1));//removes from myDeck

	cout<< "  > "<<chosenCard;
	
	hand.push_back(chosenCard);
	int value=chosenCard.getCardValue();
	return value;
}

//--- Definition of checkPlayer()
bool BlackJack::checkPlayer()
{	
	if (playerTotal <= 21)
		return true;
	if(playerTotal>21 && playerTotal<33)//checks if player has ace
	{
		if(checkAce(playersHand, playerTotal))
		{
			cout<<"Although you have busted, your hand had an ace. \nNew total score: "<< playerTotal<<endl;
			return true;
		}
	}
	
	cout<<"You have busted! "<<endl;
	return false;
}

//--- Definition of checkDealer()
bool BlackJack::checkDealer()
{	
	if (dealerTotal <=21)
		return true;

	if(dealerTotal>21 && dealerTotal<33)
	{
		if(checkAce(dealersHand, dealerTotal))
		{
			//cout<<"Although dealer has busted, their hand had an ace. which puts dealer total score at: "<< dealerTotal<<endl;
			return true;
		}
	}
	
	cout<< "Dealer has busted!";
	return false;
}

//--- Definition of checkAce()
bool BlackJack::checkAce(vector<Card> & hand, int & handTotal)
{
	for(int i=0; i< hand.size(); i++)//searching vector for an ace of value 11
	{
		if(hand[i].getCardValue() ==11)
		{
			hand[i].setAceValue();
			handTotal-=10;//updates their total
			return true;
		}
	}
	return false;
}

//--- Definition of dealerDecision()
void BlackJack::dealerDecision()
{
	cout<<"  > "<< dealersHand[0];
	while (dealerTotal < 17)
	{
		dealerMove();//dealer gets another card
	}
	if ((dealerTotal==17) && (checkAce(dealersHand,dealerTotal)==true))
		dealerDecision();//recursive call to same method 

}

//--- Definition of results()
int BlackJack::results()
{
	cout<<"Your score was: " << playerTotal<<endl;
	cout<<"Dealer score was: " << dealerTotal <<"\n"<<endl;
	
	if (playerTotal <= 21)
	{
		if (dealerTotal > 21 || playerTotal > dealerTotal)
		{
			if(playerTotal==21)
				cout<<"*****BLACKJACK*****"<<endl;
			cout<<"Congratulations you have beat me!!"<<endl;
			return 1;
		}
	}
	if (dealerTotal <= 21)
	{
		if (playerTotal > 21 || dealerTotal > playerTotal)
		{
			cout<<"I am sorry!! You lose and I winnnnnnnnnnn!!!!"<<endl;
			return 0;
		}
	}
	
	cout<<"Since we have both the same scores it is a PUSH. Neither of us wins or loses.\n"<<endl;
	return 2;
}

//--- Definition of reset()
void BlackJack::reset()
{
	myDeck=origDeck;
	playersHand.clear();//resets both vector of both hands 
	dealersHand.clear();

	playerTotal=0;
	dealerTotal=0;
}
