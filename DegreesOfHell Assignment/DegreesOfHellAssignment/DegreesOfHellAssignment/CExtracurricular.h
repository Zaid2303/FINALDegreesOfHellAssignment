#pragma once
#include "CSpace.h"
class CExtracurricular :
    public CSpace
{
protected:
	int mMotivationalCost;

public:

	CExtracurricular(std::istream& degreeFile);
	friend std::istream& operator >> (std::istream& inputStream, CExtracurricular& extracurricular);

};

