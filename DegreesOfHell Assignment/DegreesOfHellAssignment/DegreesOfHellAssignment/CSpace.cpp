#include "CSpace.h"
#include "CPlayer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
CSpace::CSpace(istream& degreeFile)
{
	degreeFile >> *this;
}

istream& operator>>(istream& inputStream, CSpace& degree)
{
    // checks each letter untill its a number
    bool notANumber;
    int nextChar;
    do
    {
        string word;

        inputStream >> word;
        degree.name += word;
        inputStream >> ws;
        nextChar = inputStream.peek();
        notANumber = !isdigit(nextChar);

        if (notANumber)
        {
            degree.name += " ";
        }

    } while (notANumber);

    if (degree.name == "Welcome Week") {
        degree.isWelcomeWeek = true;
    }
    return inputStream;
}

ostream& operator<<(ostream& outputStream, CSpace& degree)
{
	outputStream << degree.name;
	return outputStream;
}

string CSpace::GetName() const {
    return name;
}


