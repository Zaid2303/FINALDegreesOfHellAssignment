#pragma once
#include "CSpace.h"
class CHearings :
    public CSpace
{
protected:

public:
    CHearings(std::istream& degreeFile);
    friend std::istream& operator>>(std::istream& inputStream, CHearings& hearing);
};

