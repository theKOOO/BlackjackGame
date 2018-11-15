/********************************************************************************
Header file Card.h creates a card object simulating individual cards in a 
deck. Creates private variables for a cards name, number value, and face value.

						Casino Final Project

						 		Card.h
********************************************************************************/
#include <iostream>
#ifndef CARD
#define CARD

#include <string>

using namespace std;

class Card
{
	public:
		Card(string type="", int num=0, string face="");
		/*----Card()--------------------------------------------------------
		  Card constructor that accepts values for the card type and sets 
		  each value to the private variables.

		  Pre-condition: none.
		  Post-condition: assigns user input or pre-defined value to 
			  private variables name, faceValue, and carValue.
		------------------------------------------------------------------*/

		void setAceValue();
		/*----setAceValue()-------------------------------------------------
		  Mutator function that is called when the user has an ace and wants 
		  to set its cardValue to 1 instead of 11 so the user will not bust. 

		  Pre-condition: The user wants to the ace value to be one.
		  Post-condition: assigns the cards cardValue to 1.
		------------------------------------------------------------------*/

		int getCardValue();
		/*----getCardValue()------------------------------------------------
		  Accessor method that returns the cardValue of a specific card. 

		  Pre-condition: a valid card was used to call this method.
		  Post-condition: returns correct number value of the card.
		------------------------------------------------------------------*/

		void display(ostream & out) const;
		/*----display(ostream & out)----------------------------------------
		  Display function that accepts ostream & out and outputs the name
		  and faceValue variables of a given card. 

		  Pre-condition: the display function is called by overloaded 
			  operator<<.
		  Post-condition: the cards name and faceValue were correctly 
			  outputted.
		------------------------------------------------------------------*/

	private://member variables
		int cardValue;
		string name, faceValue;
};

ostream & operator<<(ostream & out, const Card & c);
/*----operator<<()------------------------------------------------------
  Overloaded output<< operator that accepts a Card object and calls on 
  its display function. Mainly used when a vector of Card objects loops
  through to display its objects contents.

  Pre-condition: A valid Card object is passed in.
  Post-condition: the Cards variables were correctly diplayed.
----------------------------------------------------------------------*/
#endif