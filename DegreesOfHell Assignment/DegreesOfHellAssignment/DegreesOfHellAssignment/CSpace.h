#pragma once
#include <iostream>


class CSpace
{
protected:
	std::string name;
	bool isWelcomeWeek = false;
	bool isPlagiarismHearing = false;
	bool isAccusedOfPlagiarism = false;
	bool isSkipClasses = false;
	bool isSomethingElse = false;


public:
	CSpace(std::istream& degreeFile);

	friend std::istream& operator >> (std::istream& inputStream, CSpace& degree);
	friend std::ostream& operator << (std::ostream& outputStream, CSpace& degree);

	std::string GetName() const;

	// Check if it's a Welcome Week space
	bool IsWelcomeWeek() const;
	bool IsPlagiarismHearing() const;
	bool IsAccusedOfPlagiarism() const;
	bool IsSkipClasses() const;
	bool IsSomethingElse() const;

	void ResetIsWelcomeWeek();
	void ResetIsPlagiarismHearing();
	void ResetIsAccusedOfPlagiarism();
	void ResetIsSkipClasses();
	void ResetIsSomethingElse();

	// Declare a virtual destructor
	virtual ~CSpace() {};

};

