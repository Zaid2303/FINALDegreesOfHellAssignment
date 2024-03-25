#pragma once
#include "CSpace.h"

class CExtracurricular : 
    public CSpace {
protected:
    int mMotivationalCost;
    int mSuccessScore = 20;
    bool mIsCompleted;
    std::string mCompletedByName;

public:
    CExtracurricular(std::istream& degreeFile);

    int GetMotivationalCost() const;
    int GetSuccessScore() const;
    bool IsCompleted() const;
    void SetCompletedBy(const std::string& playerName);
    bool CompletedByPlayer(const std::string& playerName) const;
    std::string GetCompletedByName() const;
    void CompleteExtracurricular(const std::string& playerName);

    friend std::istream& operator>>(std::istream& inputStream, CExtracurricular& extracurricular);
};
