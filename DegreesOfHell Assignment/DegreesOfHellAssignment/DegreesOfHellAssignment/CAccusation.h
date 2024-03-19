#pragma once
#include "CSpace.h"
class CAccusation :
    public CSpace
{
protected:

public:
    CAccusation(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CAccusation& accusation);
};

