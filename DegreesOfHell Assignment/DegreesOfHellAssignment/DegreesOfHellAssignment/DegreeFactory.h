#pragma once
#include "CPlayer.h"
#include "CSpace.h"
#include <istream>

enum class EDegreeDetails : int
{
	 Assessments = 1,
	 WelcomeWeek = 2,
	 Extracurricular = 3,
	 Bonus = 4,
	 Bogus = 5,
	 Hearings = 6,
	 Accusation = 7,
	 SkipClass = 8

};

CSpace* NewDegree(EDegreeDetails degree, std::istream& degreeFile);