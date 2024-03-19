#include "CBonus.h"
using namespace std;

istream& operator>>(istream& inputStream, CBonus& bonus)
{
	return inputStream;
}

CBonus::CBonus(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}