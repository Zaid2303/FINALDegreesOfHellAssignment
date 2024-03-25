#include "CExtracurricular.h"

CExtracurricular::CExtracurricular(std::istream& degreeFile) : CSpace(degreeFile) {
    // Initialize member variables based on degreeFile
    degreeFile >> mMotivationalCost;
    mIsCompleted = false;
}

int CExtracurricular::GetMotivationalCost() const {
    return mMotivationalCost;
}

int CExtracurricular::GetSuccessScore() const {
    return mSuccessScore;
}

bool CExtracurricular::IsCompleted() const {
    return mIsCompleted;
}

void CExtracurricular::SetCompletedBy(const std::string& playerName) {
    mIsCompleted = true;
    mCompletedByName = playerName;
}

bool CExtracurricular::CompletedByPlayer(const std::string& playerName) const {
    return (mIsCompleted && mCompletedByName == playerName);
}

std::string CExtracurricular::GetCompletedByName() const {
    return mCompletedByName;
}

void CExtracurricular::CompleteExtracurricular(const std::string& playerName) {
    SetCompletedBy(playerName);
}

std::istream& operator>>(std::istream& inputStream, CExtracurricular& extracurricular) {
    // Read data from inputStream and initialize extracurricular object
    return inputStream;
}
