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

    if (degree.name == "Welcome Week")
    {
        degree.isWelcomeWeek = true;
    }
    else if (degree.name == "Plagiarism Hearing")
    {
        degree.isPlagiarismHearing = true;
    }
    else if (degree.name == "Accused of Plagiarism") 
    {
        degree.isAccusedOfPlagiarism = true;
    }
    else if (degree.name == "Skip Classes") 
    {
        degree.isSkipClasses = true;
    }
    else
    {
        degree.isSomethingElse = true;
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

bool CSpace::IsWelcomeWeek() const
{
    return isWelcomeWeek;
}

bool CSpace::IsPlagiarismHearing() const
{
    return isPlagiarismHearing;
}

bool CSpace::IsAccusedOfPlagiarism() const
{
    return isAccusedOfPlagiarism;
}

bool CSpace::IsSkipClasses() const
{
    return isSkipClasses;
}

bool CSpace::IsSomethingElse() const
{
    return isSomethingElse;
}


void CSpace::ResetIsWelcomeWeek()
{
    isWelcomeWeek = false;
}

void CSpace::ResetIsPlagiarismHearing()
{
    isPlagiarismHearing = false;
}

void CSpace::ResetIsAccusedOfPlagiarism()
{
    isAccusedOfPlagiarism = false;
}

void CSpace::ResetIsSkipClasses()
{
    isSkipClasses = false;
}

void CSpace::ResetIsSomethingElse()
{
    isSomethingElse = false;
}




