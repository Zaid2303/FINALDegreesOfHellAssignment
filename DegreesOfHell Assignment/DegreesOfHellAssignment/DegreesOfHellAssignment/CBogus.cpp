#include "CBogus.h"
using namespace std;

istream& operator>>(istream& inputStream, CBogus& bogus)
{
	return inputStream;
}

CBogus::CBogus(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}