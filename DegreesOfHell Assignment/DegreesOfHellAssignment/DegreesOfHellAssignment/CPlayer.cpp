// CPlayer.cpp
using namespace std;
#include "CPlayer.h"
#include "CSpace.h"
#include "CAssessments.h"

// Define the static member players vector outside of the class
std::vector<CPlayer> CPlayer::players;

// Constructor implementation
CPlayer::CPlayer(const string& name, int year, int motivation, int success, int position) :
    mName(name), mYear(year), mMotivation(motivation), mSuccess(success), mPosition(position) {}

// Getters
std::string CPlayer::GetName() { return mName; }
int CPlayer::GetYear() { return mYear; }
int CPlayer::GetMotivation() { return mMotivation; }
int CPlayer::GetSuccess() { return mSuccess; }
int CPlayer::GetPosition() { return mPosition; }

// Setters
void CPlayer::SetName(const std::string& name) { mName = name; }
void CPlayer::SetYear(int year) { mYear = year; }
void CPlayer::SetMotivation(int motivation) { mMotivation = motivation; }
void CPlayer::SetSuccess(int success) { mSuccess = success; }
void CPlayer::SetPosition(int position) { mPosition = position; }


void CPlayer::Move(int steps, const std::vector<CSpace*>& degreeList) {
    // Calculate the new position
    int newPosition = (GetPosition() + steps) % degreeList.size();

    std::cout << GetName() << " lands on " << degreeList[newPosition]->GetName() << std::endl;
    // Check if the new position is an assessment space
    CAssessments* assessmentSpace = dynamic_cast<CAssessments*>(degreeList[newPosition]);
    if (assessmentSpace) {
        // If assessment is not completed by anyone
        if (!assessmentSpace->IsCompleted()) {
            // Check if the player has enough motivation to complete it
            if (GetMotivation() >= assessmentSpace->GetMotivationalCost()) {
                // Complete the assessment
                SetMotivation(GetMotivation() - assessmentSpace->GetMotivationalCost());
                SetSuccess(GetSuccess() + assessmentSpace->GetSuccessScore());
                assessmentSpace->CompleteAssessment(GetName()); // Mark the assessment as completed by the current 
                std::cout << "" << endl;
                std::cout << GetName() << " completes " << assessmentSpace->GetName() << " for Motivation: " << assessmentSpace->GetMotivationalCost() << " and Success: " << assessmentSpace->GetSuccessScore() << std::endl;
                std::cout << GetName() << "'s motivation is " << GetMotivation() << " and success is " << GetSuccess() << std::endl;
            }
            else {
                // If not, output a message indicating insufficient motivation
                std::cout << "Insufficient motivation to complete assessment!" << std::endl;
            }
        }
        else {
            // If assessment is already completed
            std::cout << "Assessment " << assessmentSpace->GetName() << " is already completed by " << assessmentSpace->GetCompletedByName() << "!" << std::endl;
            
            // Ask for help from the player who completed the assessment
            std::string help;
            while (true) {

                //check if completed by same player as landed on
                if (GetName() == assessmentSpace->GetCompletedByName()) { break; }

                std::cout << "" << endl;
                std::cout << "Do you want help from " << assessmentSpace->GetCompletedByName() << "? (Y/N): ";
                std::cin >> help;

                if (help == "Y" || help == "y") {
                    // Get the name of the player who completed the assessment
                    std::string helperName = assessmentSpace->GetCompletedByName();

                    // Find the player object corresponding to the helper
                    CPlayer* helper = nullptr;
                    for (auto& player : players) {
                        if (player.GetName() == helperName) {
                            helper = &player;
                            break;
                        }
                    }

                    if (helper) {
                        // Halve motivation cost and success score
                        int halfMotivationalCost = assessmentSpace->GetMotivationalCost() / 2;
                        int halfSuccessScore = assessmentSpace->GetSuccessScore() / 2;

                        // Subtract half of the motivation cost from the current player and the helper
                        SetMotivation(GetMotivation() - halfMotivationalCost);
                        helper->SetMotivation(helper->GetMotivation() - halfMotivationalCost);

                        // Add half of the success score to both players
                        SetSuccess(GetSuccess() + halfSuccessScore);
                        helper->SetSuccess(helper->GetSuccess() + halfSuccessScore);

                        std::cout << "" << endl;
                        std::cout << "You accepted help from " << helperName << ". Your motivation cost is halved and your success is increased by half." << std::endl;
                        std::cout << "" << endl;
                        std::cout << "You Both Complete " << assessmentSpace->GetName() << " for Motivation: " << assessmentSpace->GetMotivationalCost() << " and Success:" << assessmentSpace->GetSuccessScore() << std::endl;
                        std::cout << "" << endl;
                        std::cout << GetName() << "'s motivation is " << GetMotivation() << " and success is " << GetSuccess() << std::endl;
                        std::cout << helperName << "'s motivation is " << helper->GetMotivation() << " and success is " << helper->GetSuccess() << std::endl;
                    }
                    else {
                        std::cout << "Error: Player not found." << std::endl;
                    }
                    break; // Exit the loop after valid input
                }
                else if (help == "N" || help == "n") {
                    std::cout << "" << endl;
                    std::cout << "You declined help from " << assessmentSpace->GetCompletedByName() << ". Your game continues." << std::endl;
                    break; // Exit the loop after valid input
                }
                else {
                    std::cout << "Invalid input. Please enter 'Y' or 'N'." << std::endl;
                }
            }
        }
    }
    else {
        // If the new position is not an assessment space, simply move the player
        SetPosition(newPosition);
        std::cout << GetName() << "'s motivation is " << GetMotivation() << " and success is " << GetSuccess() << std::endl;
    }  
}


// Static function to add player to players vector
void CPlayer::AddPlayer(const CPlayer& player) {
    players.push_back(player);
}


