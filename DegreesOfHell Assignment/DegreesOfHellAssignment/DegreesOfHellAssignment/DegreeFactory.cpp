#include "DegreeFactory.h"
#include "CAssessments.h"
#include "CWelcomeWeek.h"
#include "CExtracurricular.h"
#include "CBonus.h"
#include "CBogus.h"
#include "CHearings.h"
#include "CAccusation.h"
#include "CSkipClass.h"
using namespace std;

CSpace* NewDegree(EDegreeDetails degree, istream& degreeFile)
{
    CSpace* spacePtr = nullptr;
    switch (degree)
    {
    case EDegreeDetails::Assessments:
    {
        spacePtr = new CAssessments(degreeFile);
        break;
    }
    case EDegreeDetails::WelcomeWeek:
    {
        spacePtr = new CWelcomeWeek(degreeFile);
        break;
    }
    case EDegreeDetails::Extracurricular:
    {
        spacePtr = new CExtracurricular(degreeFile);
        break;
    }
    case EDegreeDetails::Bonus:
    {
        spacePtr = new CBonus(degreeFile);
        break;
    }
    case EDegreeDetails::Bogus:
    {
        spacePtr = new CBogus(degreeFile);
        break;
    }
    case EDegreeDetails::Hearings:
    {
        spacePtr = new CHearings(degreeFile);
        break;
    }
    case EDegreeDetails::Accusation:
    {
        spacePtr = new CAccusation(degreeFile);
        break;
    }
    case EDegreeDetails::SkipClass:
    {
        spacePtr = new CSkipClass(degreeFile);
        break;
    }
    default:
    {
        cerr << "Unknown degree type encountered" << endl;
        break;
    }
    return spacePtr;
    }
}
