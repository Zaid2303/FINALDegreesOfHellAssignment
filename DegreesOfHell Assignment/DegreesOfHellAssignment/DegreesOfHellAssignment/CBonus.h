#pragma once
#include "CSpace.h"
class CBonus :
    public CSpace
{
protected:


public:
    CBonus(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CBonus& bonus);
};

