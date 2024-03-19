#include "CHearings.h"
using namespace std;

istream& operator>>(istream& inputStream, CHearings& hearing)
{
	
	return inputStream;
}

CHearings::CHearings(istream& degreeFile) : CSpace(degreeFile)
{
	//degreeFile >> *this;
}