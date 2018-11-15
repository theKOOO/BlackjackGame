/**************************************************************************************
Implementation file Bank.cpp implements the member functions of Bank.h file.

					Casino Final Project

				 		   Bank.cpp
**************************************************************************************/
#include <iostream>

using namespace std;

#include "Bank.h"

//--- Definition of constructor
Bank::Bank(int money)
{
	total = money;
	startTotal=money;
}

//---Definition of checkAmount()
int Bank::checkAmount ()
{
	if (total < 2000)
	{
		cout<<"You have lost to much money to continue. You have less then the $2,000 in the bank"<<endl;
		cout<<"Your game is over! Thank you for playing at theKOOO Casino."<<endl;
		return -1;
	}
	return 1;
}

//---Definition of checkBet()
int Bank::checkBet(int s)
{
	if(s>=2000 && s<=total)//valid bet
	{
		bet=s;
		return 1;
	}
	
	if (s > total)//not enough $ in bank
	    cout<<"Sorry you do not have enough money."<<endl;
	if (s < 2000)
	    cout<<"Please bet higher than $2,000"<<endl;
	
	return -1;
}

//---Definition of losses()
void Bank::losses()
{
	total -= bet;
	cout<<"You lost: $" << bet <<endl;
	cout<<"Your total: $" << total  <<endl;
}

//---Definition of winnings()
void Bank::winnings()
{
	total += bet;
	cout<<"You won: $" << bet <<endl;
	cout<<"Your total: $" << total <<endl;
}

//---Definition of push()
void Bank::push() const
{
	cout<<"Your total: $" << total<<endl;
}

//---Definition of DoubleDown()
void Bank::DoubleDown()
{
	bet = (bet * 2);
	cout<<"Your new bet is $" << bet<<endl;
}

//---Definition of Surrender()
void Bank::Surrender()
{
	bet = (bet / 2);
}

void Bank::refreshments()
{
	total-=5;
	cout<<"Your total: $"<<total<<endl;
}

//---Definition of totalEarnings()
void Bank::totalEarnings ()
{
	cout<<"________________________________________"<<endl;
	cout<<"\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ "<<endl;
	cout<<"            BANK RECEIPT"<<endl;
	cout<<"        BlackJack Statement"<<endl;
	cout<<" \n  Overall you started with: $" << startTotal<<endl;
	cout<<"  After all the rounds you played, \n\n"<<endl;
	if (total < startTotal)
	{
	    int lose = startTotal - total;//calculate total losses
	    cout<<"\tTotal Losses: $" << lose<<endl;
	}
	else if (total > startTotal)
	{
	    int ganar = total - startTotal;//calculate total wins
	    cout<<"\tTotal Wins: $" << ganar<<endl;
	}
	else
	    cout<<"\tYou have neither won nor lost \n\tmoney and you still have $" << startTotal<<endl;
	
	cout<<"\tCurrent Total: $" <<total<<endl;
	startTotal = total;
	cout<<" \n  You leave my Casino with $" << total<<endl;
	cout<<"\n\n        Thank you for playing \n        at theKOOO Casino!"<<endl;
	cout<<"\t    Come Again"<<endl;
	cout<<" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ "<<endl;
	cout<<"________________________________________"<<endl;
}