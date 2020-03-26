#ifndef RUPEE_H
#define RUPEE_H
#include <iostream>

class Rupee
{
private:
	int note;
	int fract;
public:
	//*******************************************
	//* Default Constructor
	//*******************************************
	Rupee() : note(0), fract(0)
	{
	}

	//*******************************************
	//* Constructor
	//*******************************************
	Rupee(int nVal, int fVal) : note(nVal), fract(fVal)
	{
		simplify();
	}

	//*******************************************
	//* Function Name: setNote
	//* Pre - int n
	//* Pos - Nothing
	//* Purpose  - set note to n
	//*******************************************
	void setNote(int n) { note = n; }

	//*******************************************
	//* Function Name: setFract
	//* Pre - int f
	//* Pos - Nothing
	//* Purpose  - set fract to f
	//*******************************************
	void setFract(int f) { fract = f; }

	//*******************************************
	//* Function Name: getNote
	//* Pre - None
	//* Pos - note
	//* Purpose  - return note
	//*******************************************
	int getNote() { return note; }

	//*******************************************
	//* Function Name: getFract
	//* Pre - None
	//* Pos - fract
	//* Purpose  - return fract
	//*******************************************
	int getFract() { return fract; }

	//*******************************************
	//* Function Name: simplify
	//* Pre - None
	//* Pos - None
	//* Purpose - if the value of fract is 
	//*			  greater than or equal to 100
	//*			  then take divide by 100 to add
	//*			  to note and take the modulus
	//*			  of 100 for fract
	//*******************************************
	void simplify();

	friend std::istream& operator>>(std::istream& in, Rupee& c1);
	friend std::ostream& operator<<(std::ostream& out, Rupee& c1);
	bool operator>(const Rupee& c1);
	bool operator<(const Rupee& c1);
	bool operator==(const Rupee& c1);
	bool operator!=(const Rupee& c1);

};
#endif