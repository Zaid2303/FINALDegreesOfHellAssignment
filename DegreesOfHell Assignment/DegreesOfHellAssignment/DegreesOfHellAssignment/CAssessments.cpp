#include "CAssessments.h"
#include "CPlayer.h"
using namespace std;

CAssessments::CAssessments(istream& degreeFile) : CSpace(degreeFile)
{
	degreeFile >> *this;
}

// Getter functions
int CAssessments::GetMotivationalCost() const 
{
	return mMotivationalCost;
}

int CAssessments::GetSuccessScore() const 
{
	return mSuccessScore;
}

bool CAssessments::IsCompleted() const
{
	return mIsCompleted;
}

// Method to set the player who completed the assessment
void CAssessments::SetCompletedBy(const std::string& playerName) 
{
	mCompletedByName = playerName;
}

// Method to check if the assessment was completed by a specific player
bool CAssessments::CompletedByPlayer(const std::string& playerName) const
{
	return (mIsCompleted && mCompletedByName == playerName);
}

std::string CAssessments::GetCompletedByName() const
{
	return mCompletedByName;
}

// Method to complete the assessment
void CAssessments::CompleteAssessment(const std::string& playerName) 
{
    mIsCompleted = true;
    mCompletedByName = playerName;
    //std::cout << "Completed by: " << mCompletedByName << std::endl; // Debugging output
}


istream& operator>>(istream& inputStream, CAssessments& assessments)
{
	inputStream >> assessments.mMotivationalCost >> assessments.mSuccessScore >> assessments.mYear;

	return inputStream;
}
