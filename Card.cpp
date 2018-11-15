/********************************************************************************
Implementation file Card.cpp implements the member functions of Card.h file.

					Casino Final Project

					  	   Card.cpp
********************************************************************************/
#include "Card.h"
#include <string>

//---Definition of Card()
Card::Card(string type, int num, string face)
: name(type), cardValue(num), faceValue(face)
{
}

//---Definiton of setAceValue() function
void Card::setAceValue() 
{
	cardValue=1;
}

//---Definition of getCardValue() function
int Card::getCardValue()
{
	return cardValue;
}

//---Definition of display(ostream & out) function
void Card::display(ostream & out) const
{
	out<< name << " of " << faceValue<< endl;
}

//---Definition of overloaded operator<<()
ostream & operator<<(ostream & out, const Card & c)
{
	c.display(out);
	return out;
}