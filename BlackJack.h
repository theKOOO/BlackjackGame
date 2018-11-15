/********************************************************************************
Header file BlackJack.h creates the BlackJack object containing all the functions
and variables needed to keep track of the BlackJack game between a player and 
dealer. The BlackJack class creates the deck, player and dealer Hands, keeps totals
of both player and dealer, checks for busts, deals a card, returns results of game, 
and resets the data variables so the game can be played again.

						Casino Final Project

							BlackJack.h
********************************************************************************/
#include <iostream>
#include <vector>

#ifndef BLACKJACK
#define BLACKJACK 

#include "Card.h"
class BlackJack
{
	public:
		BlackJack();
		/*----BlackJack()----------------------------------------------------
		  BlackJack constructor creates the 52 card objects of a deck and 
		  adds each to the vector myDeck and sets playerTotal and dealerTotal
		  to 0.

		  Pre-condition: none.
		  Post-condition: myDeck stores 52 card objects.
		-------------------------------------------------------------------*/

		void getPTotal() const;
		/*----getPTotal()----------------------------------------------------
		  Prints the playerTotal of all the cards in players hand. 

		  Pre-condition: none.
		  Post-condition: Players total was correctly printed to screen.
		-------------------------------------------------------------------*/

		void playerMove();
		/*----playerMove()----------------------------------------------------
		  Void method that calls on Distribute function passing in the vector  
		  playersHand and correctly adds the number value of the card dealt 
		  to playersTotal.

		  Pre-condition: Assumes it is the players turn.
		  Post-condition: Players total was correctly updated.
		--------------------------------------------------------------------*/

		void dealerMove();
		/*----dealerMove()----------------------------------------------------
		  Void method that calls on Distribute function passing in the vector 
		  dealersHand and correctly adds the number value of the card dealt 
		  to dealersTotal. 

		  Pre-condition: Assumes it is the dealers turn.
		  Post-condition: Dealers total was correctly updated.
		--------------------------------------------------------------------*/

		void displayPlayerHand();
		/*----displayPlayerHand()--------------------------------------------
		 Method that displays the card Value of players hand. A better more 
		 organized visualization of their hand.

		  Pre-condition: Assumes there are cards in players hand.
		  Post-condition: correctly outputs values in dealers hand.
		--------------------------------------------------------------------*/

		void displayDealerHand();
		/*----displayDealerHand()--------------------------------------------
		 Method that displays the card Value of players hand. A better more 
		 organized visualization of their hand.

		  Pre-condition: Assumes there are cards in players hand.
		  Post-condition: correctly outputs values in dealers hand.
		--------------------------------------------------------------------*/

		int Distribute(vector<Card> & hand);
		/*----Distribute(vector<Card> & hand)---------------------------------
		  Int method that finds a random card in the vector, myDeck, assigns 
		  it to a temporary card object, removes the card from myDeck, and
		  pushes the card on the vector passed in.

		  Pre-condition: valid vector was passed in.
		  Post-condition: Card was erased from my deck, added to the vector
			  passed in, and correct number value of card was returned.
		--------------------------------------------------------------------*/

		bool checkPlayer();
		/*----checkPlayer()---------------------------------------------------
		  Bool method used that checks and returns bool value of whether 
		  the player has busted. 

		  Pre-condition: none.
		  Post-condition: returns true if player has bust, false otherwise.
		--------------------------------------------------------------------*/

		bool checkDealer();
		/*----checkDealer()---------------------------------------------------
		  Bool method used that checks and returns bool value of whether 
		  the dealer has busted.

		  Pre-condition: none.
		  Post-condition: returns true if dealer has bust, false otherwise.
		--------------------------------------------------------------------*/

		bool checkAce(vector<Card> & hand, int & handTotal);
		/*----checkAce()------------------------------------------------------
		  Bool method used to loop through hand vector checking for ace  
		  returning true or false, and if found reassigns ace value to 1.

		  Pre-condition: valid vector containing cards was passed in.
		  Post-condition: returns true if ace was found, false otherwise.
		--------------------------------------------------------------------*/

		void dealerDecision();
		/*----dealerDecision()--------------------------------------------------
		  Method used to make the decision for dealer to stand or hit depending
		  on dealerScore and cards.

		  Pre-condition: none.
		  Post-condition: dealer has hit, and added more cards, stand, or busted.
		----------------------------------------------------------------------*/

		int results();
		/*----results()------------------------------------------------------
		  Prints scores of game, who won and return int values for player win,
		  loss, or tie.

		  Pre-condition: valid vector containing cards was passed in.
		  Post-condition: returns true if ace was found, false otherwise.
		--------------------------------------------------------------------*/
		
		void reset();
		/*----reset()------------------------------------------------------
		  Method that resets player and dealer Total to 0, myDeck back to 52
		  cards, and both player and dealer Hands to empty.

		  Pre-condition: game is over.
		  Post-condition: variables have been reset, so the game can be played
			  again.
		--------------------------------------------------------------------*/

	private://data variables
		Card chosenCard;
		vector<Card> myDeck, origDeck;
		vector<Card> playersHand, dealersHand;
		int playerTotal, dealerTotal;
};
#endif

