#include "CSkipClass.h"
using namespace std;
istream& operator>>(istream& inputStream, CSkipClass& skipClass)
{
	return inputStream;
}

CSkipClass::CSkipClass(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}