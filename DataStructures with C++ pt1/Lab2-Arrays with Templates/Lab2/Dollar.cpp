/*#include <iostream>
#include <fstream>

class Dollar
{
private:
	int noteVal;
	int centVal;

public:
	// Default Constructor
	Dollar() { noteVal = 0; centVal = 0; }

	// Constructor
	Dollar(int nVal, int cVal) { noteVal = nVal; centVal = cVal; }

	// Setter 
	void setNoteVal(int nVal) { noteVal = nVal; }
	void setCentVal(int cVal) { centVal = cVal; }

	// Getter
	int getNoteVal() { return noteVal; }
	int getCentVal() { return centVal; }

	//Operator Overload <
	bool operator<(Dollar &dol);

	friend std::istream& operator>>(std::istream &in, Dollar &d1);
	//friend std::ostream& operator<<(std::ostream &out, Dollar &d1);
	
};


bool Dollar::operator<(Dollar &dol)
{
	bool cmp;

	if (noteVal > dol.noteVal)
	{
		cmp = true;
	}
	else if (noteVal == dol.noteVal)
	{
		if (centVal > dol.centVal)
		{
			cmp = true;
		}
	}
	else {
		cmp = false;
	}
	return cmp;
}


std::istream& operator>>(std::istream &in, Dollar &d1) 
{

	
	std::cout << "Enter dollar: ";
	in >> d1.noteVal;

	std::cout << "Enter cents: ";
	in >> d1.centVal;

	return in;
}
*/