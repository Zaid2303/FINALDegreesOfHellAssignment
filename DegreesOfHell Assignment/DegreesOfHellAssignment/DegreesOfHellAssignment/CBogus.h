#pragma once
#include "CSpace.h"
class CBogus :
    public CSpace
{
protected:

public:
    CBogus(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CBogus& bogus);
};

