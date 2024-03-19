#include "CExtracurricular.h"
using namespace std;

istream& operator>>(istream& inputStream, CExtracurricular& extracurricular)
{
	inputStream >> extracurricular.mMotivationalCost;
	return inputStream;
}

CExtracurricular::CExtracurricular(istream& degreeFile) : CSpace(degreeFile)
{
	degreeFile >> *this;
}