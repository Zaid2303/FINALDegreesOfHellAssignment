#pragma once
#include "CSpace.h"
class CWelcomeWeek :
    public CSpace
{
protected:


public:
    CWelcomeWeek(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CWelcomeWeek& welcomeWeek);
};

