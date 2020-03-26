#include <iostream>
#include "Rupee.h"
using namespace std;

istream& operator>>(std::istream& in, Rupee& c1)
{
	std::cout << "Rupee: ";
	in >> c1.note;

	std::cout << "Inches: ";
	in >> c1.fract;

	c1.simplify();
	return in;
}

ostream& operator<<(std::ostream& out, Rupee& c1)
{
	out << c1.note << " Rupees and " << c1.fract << " paise.";
	return out;
}

bool Rupee::operator>(const Rupee& c1)
{
	bool truth;
	if (note > c1.note)
	{
		truth = true;
	}
	else if (note == c1.note && fract > c1.fract)
	{
		truth = true;
	}

	else
	{
		truth = false;
	}
	return truth;
}

bool Rupee::operator<(const Rupee& c1)
{
	bool truth;
	if (note < c1.note)
	{
		truth = true;
	}
	else if (note == c1.note && fract < c1.fract)
	{
		truth = true;
	}
	else
	{
		truth = false;
	}
	return truth;
}
bool Rupee::operator==(const Rupee& c1)
{
	bool truth;

	if (note == c1.note && fract == c1.fract)
	{
		truth = true;
	}
	else
	{
		truth = false;
	}
	return truth;

}

bool Rupee::operator!=(const Rupee& c1)
{
	bool truth;
	if (note != c1.note && fract != c1.fract)
	{
		truth = true;
	}
	else
	{
		truth = false;
	}

	return truth;
}

void Rupee::simplify()
{
	if (fract >= 100)
	{
		note += (fract / 100);
		fract = (fract % 100);
	}
}