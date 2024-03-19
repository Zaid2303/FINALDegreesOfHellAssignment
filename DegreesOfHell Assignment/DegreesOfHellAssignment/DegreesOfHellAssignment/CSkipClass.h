#pragma once
#include "CSpace.h"
class CSkipClass :
    public CSpace
{
protected:

public:
    CSkipClass(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CSkipClass& skipClass);
};

