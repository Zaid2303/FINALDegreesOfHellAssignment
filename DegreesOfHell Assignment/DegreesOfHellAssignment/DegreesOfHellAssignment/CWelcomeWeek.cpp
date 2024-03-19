#include "CWelcomeWeek.h"
using namespace std;
istream& operator>>(istream& inputStream, CWelcomeWeek& degree)
{
	return inputStream;
}

CWelcomeWeek::CWelcomeWeek(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}