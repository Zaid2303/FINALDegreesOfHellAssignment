#include "CAccusation.h"
using namespace std;

istream& operator>>(istream& inputStream, CAccusation& accusation)
{
	return inputStream;
}

CAccusation::CAccusation(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}
