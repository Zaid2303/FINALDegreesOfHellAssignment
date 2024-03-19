#pragma once
#include <iostream>


class CSpace
{
protected:
	std::string name;
	bool isWelcomeWeek = false;

public:
	CSpace(std::istream& degreeFile);

	friend std::istream& operator >> (std::istream& inputStream, CSpace& degree);
	friend std::ostream& operator << (std::ostream& outputStream, CSpace& degree);

	std::string GetName() const;

	// Check if it's a Welcome Week space
	bool IsWelcomeWeek() const { return isWelcomeWeek; }

	// Declare a virtual destructor
	virtual ~CSpace() {}

};

