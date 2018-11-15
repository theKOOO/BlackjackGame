/********************************************************************************
Main implementation file that implements Card.h, BlackJack.h, Bank.h files and 
uses them all together to create a running BlackJack game.


					Casino Final Project

						CasinoMain.cpp
********************************************************************************/
#include <iostream>
#include <string>
#include "Bank.h"
#include "BlackJack.H"
#include "Card.h"

using namespace std;


int main()
{
	//BlackJack variables
	int round = 2, playAgain = 1;
	bool validBet=false;

	cout<<"******************************************************************************\n\n"
		<<"			Welcome to theKOOO Casino!\n\n"
		<<"******************************************************************************"<<endl;
	cout<<"  ~ The starting bets at each table are $2,000. \n  ~ ONLY USE WHOLE DOLLARS"<<endl;
	cout<<"\nBefore we begin how much will you be depositing in the bank?"<<endl;
	
	int money=0;
	do//makes sure more than 2000 was deposited
	{
		cin>> money;
		if(money<2000)
			cout<<"Please deposit a start value higher than $2000: ";
	}while(money<2000);

	Bank myBank(money);//bank object

	cout<<"\n-------RULES------------------------------------------------------------------" <<endl;
	cout<<" Here are the blackjack rules: "
		<<"\n You will be playing the dealer. Whoever gets the closest to 21 without going"
		<<"\n over will win the round, meaning you win the MONEY!!! Cards 2 through 10 are"
		<<"\n all worth their face values, cards Jack Queen and King are all worth 10 as"
		<<"\n well. An Ace is worth 11 but if you will bust then it is worth 1. If you and"
		<<"\n the dealer were to have the same values at the end of the round then neither"
		<<"\n player nor computer wins or loses the round.\n\n"<<endl;
	BlackJack myB;//blackJack object

	while (playAgain == 1)
	{
		while (validBet == false)//first makes user enter a valid bet >2000
		{
			cout<<"How much would you like to bet: ";
			int bet; 
			cin>>bet;
			if (myBank.checkBet(bet) == 1)//User entered a valid bet
				validBet=true;
		}
	
		cout<<"\n\nHere are your first two cards: "<<endl;
		myB.playerMove();
		myB.playerMove();
		myB.displayPlayerHand();
		myB.getPTotal();

		cout<<"\n\nHere is the dealer's first card: \n"<<endl;
		myB.dealerMove();//shows only first card of dealer

		while (round != 0)//round is still going
		{
			cout<<"\n--------------------------------------------------------------------------"<<endl;
			cout<<"What would you like to do: "
				<<"\n1.Hit  "
				<<"\n2.Stand "
				<<"\n3.Double Down (Double your bet and take exactly one more card) "
				<<"\n4.Surrender (Forfeit half your bet and give up your hand)"<<endl;
			int playerOption;
			cin>> playerOption;
			cout<<"\n--------------------------------------------------------------------------"<<endl;
			switch(playerOption)
			{
				case 1:
				{
					cout<<"\n~~~~~~~~~~~~~~~~ HIT ~~~~~~~~~~~~~~~~"<<endl;
					myB.playerMove();//deals a card
					myB.displayPlayerHand();
					myB.getPTotal();
					if (myB.checkPlayer() == false)//checks for bust
					{
						round=0;
						myBank.losses();
					}
					break;
				}
				case 2:
				{
					cout<<"\n~~~~~~~~~~ STAND ~~~~~~~~~~"<<endl;
					cout<<"Here is a look at my hand:"<<endl;
					myB.dealerDecision ();
					myB.displayDealerHand();
					int win = myB.results();//compares results of dealer to player
					if (win == 1)					
						myBank.winnings ();
					else if (win == 0)	
						myBank.losses ();
					else					
						myBank.push ();//tie
					round=0;
					break;
				}
				case 3:
				{
					cout<<"\n~~~~~~~~~~ DOUBLE DOWN ~~~~~~~~~~"<<endl;
						myBank.DoubleDown();
						myB.playerMove();//only one more card is dealt
						myB.displayPlayerHand();

					if (myB.checkPlayer() == false)
						myBank.losses ();
					else
					{
						cout<<"Here is a look at my hand:"<<endl;
						myB.dealerDecision();
						myB.displayDealerHand();
						int win = myB.results();
						if (win == 1)
							myBank.winnings ();
						else if (win == 0)
							myBank.losses ();
						else
							myBank.push ();
					}
					round=0;
					break;
				}			
				case 4://forfeit half your bet 
				{
					cout<<"~~~~~~~~~~ SURRENDER ~~~~~~~~~~"<<endl;
					myBank.Surrender();
					myBank.losses ();
					round=0;
					break;
				}
				default:
					cout<<"Please enter a valid choice" <<endl;
			}
		}

		myB.reset ();//reset vectors and points in BlackJack
		validBet=false;

		cout<<"\n\tWould you like to play again? (1)for yes (2) no "<<endl;
		cin>> playAgain;

		if ((playAgain == 1) && (myBank.checkAmount() == 1))//checks to see if you still have enough money to play
		{
			round = 2;
			/*cout<<"Would you like to purchase a refreshment? (1)yes (2) no"<<endl;
			int water;
			cin>>water;
			if(water==1)
			{
				cout<<"We have many types of $5 WATER: \n(1)Crystal Geyser\n(2)Arrowhead(3)Fiji."<<endl;
				cin>>water;
				if(water==1 || water==2 ||water==3)
					myBank.refreshments();
				else
					cout<<"Not a valid option";
			}*/

		}
		else
		{
			playAgain=0;
			myBank.totalEarnings ();
			break;
		}
		cout<<"\n";
	}

	char m;
	cin>>m;

	return 0;
}