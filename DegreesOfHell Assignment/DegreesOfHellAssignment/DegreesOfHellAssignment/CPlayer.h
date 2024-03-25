// CPlayer.h

#pragma once
#include <string>
#include <vector>

class CSpace;

class CPlayer {
private:
    std::string mName;
    int mYear;
    int mMotivation;
    int mSuccess;
    int mPosition;
    int mAssignmentCount;

public:

    static std::vector<CPlayer> players;
    // Constructor with default parameter values
    CPlayer(const std::string& name, int year, int motivation, int success, int position, int assignmentCount);

    // Getters
    std::string GetName();
    int GetYear();
    int GetMotivation();
    int GetSuccess();
    int GetPosition();
    int GetAssignmentCount();

    // Setters
    void SetName(const std::string& name);
    void SetYear(int year);
    void SetMotivation(int motivation);
    void SetSuccess(int success);
    void SetPosition(int position);

    // Move function
    void Move(int steps, const std::vector<CSpace*>& degreeList);

    // Static function to add player to players vector
    static void AddPlayer(const CPlayer& player);

    void ResetAssignmentCount();
    void IncrementAssignmentCount();
};
