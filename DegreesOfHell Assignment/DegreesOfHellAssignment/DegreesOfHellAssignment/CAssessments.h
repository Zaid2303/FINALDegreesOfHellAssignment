#pragma once
#include "CSpace.h"
class CAssessments :
    public CSpace
{
protected:
	int mMotivationalCost;
	int mSuccessScore;
	int mYear;
    bool mIsCompleted = false;;
    std::string mCompletedByName;
	
public:
	CAssessments(std::istream& degreeFile);

    // Getter functions
    int GetMotivationalCost() const;
    int GetSuccessScore() const;
    bool IsCompleted() const;
    void SetCompletedBy(const std::string& playerName); // Modify to accept player name
    bool CompletedByPlayer(const std::string& playerName) const; // Modify to accept player name
    std::string GetCompletedByName() const;
    
    // Method to complete the assessment
    void CompleteAssessment(const std::string& playerName);


    // Friend function declaration for input operator
    friend std::istream& operator>>(std::istream& inputStream, CAssessments& assessment);
};



