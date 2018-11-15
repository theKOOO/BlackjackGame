/********************************************************************************
Header file Bank.h creates a bank object simulating a bank in a casino that stores
and updates your total deposit depending on how much you bet and how you do 
in the BlackJack game. 
						Casino Final Project

								Bank.h
********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

#ifndef BANK
#define BANK
class Bank
{
	public:
		Bank(int money);
		/*----Bank()-----------------------------------------------------------
		  Bank constructor stores your starting Total deposit.

		  Pre-condition: money parameter is > 2000.
		  Post-condition: variables total and startTotal were set.
		---------------------------------------------------------------------*/

		int checkAmount();
		/*----checkAmount()----------------------------------------------------
		  Checks if the current total is <2000 and returns -1 or 1 indicating 
		  if you have enough to continue to play .

		  Pre-condition: none.
		  Post-condition: returns 1 if you have enough (>2000) to play, -1 
			  otherwise.
		---------------------------------------------------------------------*/

		int checkBet (int s);
		/*----checkBet(int s)--------------------------------------------------
		  Checks if your bet is valid by looking at your current total in bank, 
		  and returns 1 or -1 depending if your bet is valid.

		  Pre-condition: none.
		  Post-condition: returns 1 and sets bet if your bet is valid, -1
			  otherwise.
		---------------------------------------------------------------------*/

		void losses();
		/*----losses()---------------------------------------------------------
		  Updates your total money, subtracting your bet from your total and 
		  outputs your current total and $(bet) lost.

		  Pre-condition: player lost the blackJack round.
		  Post-condition: subtracts bet from current total.
		---------------------------------------------------------------------*/

		void winnings();
		/*----winnings()-------------------------------------------------------
		  Updates your total money, adding your bet to your total and 
		  outputs your current total and $(bet) won.

		  Pre-condition: player won the blackJack round.
		  Post-condition: adds bet to current total.
		---------------------------------------------------------------------*/

		void push() const;
		/*----push()-----------------------------------------------------------
		  Method called when player and dealer have tied, outputs player total.

		  Pre-condition: player has tied with dealer.
		  Post-condition: Current total (unchanged) was outputted.
		---------------------------------------------------------------------*/

		void DoubleDown();
		/*----DoubleUp()-------------------------------------------------------
		  Increases your bet by double.

		  Pre-condition: Player has enough money in bank to Double up bet.
		  Post-condition: bet was increased by bet*2.
		---------------------------------------------------------------------*/    

		void Surrender();
		/*----Surrender()-----------------------------------------------------
		  Decreases your bet by half.

		  Pre-condition: none.
		  Post-condition: bet was lowered by half (bet/2).
		---------------------------------------------------------------------*/

		void totalEarnings();
		/*----totalEarning()---------------------------------------------------
		  Prints the results of your starting Total in bank, current total, 
		  total losses or wins.

		  Pre-condition: game is over.
		  Post-condition: correct results were printed to screen.
		---------------------------------------------------------------------*/

		void refreshments();
		/*---refreshments()---------------------------------------------------
		Method that subtracts 5 dollars from your total for cost of refreshment

		pre-condition: none.
		post-condition: 5 was subtracted to total.
		-----------------------------------------------------------------------*/

	private:
		int total, startTotal, bet;
};
#endif

