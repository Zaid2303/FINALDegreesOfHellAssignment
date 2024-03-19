#include <iostream>
#include <fstream>
#include <vector>
#include "CSpace.h"
#include "DegreeFactory.h"
#include "CPlayer.h"

using namespace std;

const int NoRounds = 50;

int random() {
    return rand() % 10 + 1;
}

int main() {
    // Display welcome message


    // Create players Vyvyan and Rick with initial values
    CPlayer Player1("Vyvyan", 1, 1000, 0, 1);
    CPlayer Player2("Rick", 1, 1000, 0, 1);

    // Add players to the game
    CPlayer::AddPlayer(Player1);
    CPlayer::AddPlayer(Player2);

    // Initialize round number
    int roundNumber = 1;

    // Read file and create degrees
    //STL Container
    vector<CSpace*> degreeList;

    ifstream degreeFile("degrees.txt");
    if (degreeFile.is_open()) {
        while (degreeFile) {
            int assessmentType = 0;
            degreeFile >> assessmentType;

            if (assessmentType != 0) {
                // Create degree object
                degreeList.push_back(NewDegree(EDegreeDetails(assessmentType), degreeFile));
            }
        }
    }
    else {
        cout << "file couldn't be opened!" << endl;
    }

    // Seed the random number generator with the current time
    srand(time(nullptr));

    cout << "Welcome to Scumbag College" << endl;
    cout << "" << endl;
    cout << Player1.GetName() << " Starts Uni on Welcome Week " << endl;
    cout << Player2.GetName() << " Starts Uni on Welcome Week " << endl;

    // Simulate 20 rounds of the game
    for (int round = 1; round <= NoRounds; ++round)
    {

        // Output current round number
        cout << "" << endl;
        cout << "_________" << endl;
        cout << "Round " << round << endl;
        cout << "_________" << endl;
        cout << "" << endl;
        // Generate a random number between 1 and 10 for each player's turn
        int spin1 = random();
        int spin2 = random();

        // Player1's turn
        cout << Player1.GetName() << " spins " << spin1 << endl;
        int oldPosition1 = Player1.GetPosition(); // Store the old position

        // Check if Player1 is about to land on Welcome Week space
        if (degreeList[Player1.GetPosition()]->IsWelcomeWeek()) {
            // Increase motivation and increment year
            Player1.SetMotivation(Player1.GetMotivation() + 250);
            Player1.SetYear(Player1.GetYear() + 1);
            cout << Player1.GetName() << " attends Welcome Week and starts year " << Player1.GetYear() << " more motivated!" << endl;
        }
        Player1.Move(spin1, degreeList); // Move Player1
        
        cout << "" << endl;

        // Player2's turn
        cout << Player2.GetName() << " spins " << spin2 << endl;
        int oldPosition2 = Player2.GetPosition(); // Store the old position

        // Check if Player2 is about to land on Welcome Week space
        if (degreeList[Player2.GetPosition()]->IsWelcomeWeek()) {
            // Increase motivation and increment year
            Player2.SetMotivation(Player2.GetMotivation() + 250);
            Player2.SetYear(Player2.GetYear() + 1);
            cout << Player2.GetName() << " attends Welcome Week and starts year " << Player2.GetYear() << " more motivated!" << endl;
        }
        Player2.Move(spin2, degreeList); // Move Player2
    }

    // Output final success for each player and determine the winner
    cout << "" << endl;
    cout << "==============================" << endl;
    cout << "Game Over" << std::endl;
    cout << Player1.GetName() << " has achieved Success:" << Player1.GetSuccess() << endl;
    cout << Player2.GetName() << " has achieved Success:" << Player2.GetSuccess() << endl;

    // Determine the winner
    string winner;
    if (Player1.GetSuccess() > Player2.GetSuccess()) {
        winner = Player1.GetName();
    }
    else if (Player2.GetSuccess() > Player1.GetSuccess()) {
        winner = Player2.GetName();
    }
    else {
        // If both players have the same success, it's a tie
        winner = "It's a tie";
    }

    cout << winner << " wins." << endl;
    // Cleanup: Delete dynamically allocated degrees
    for (auto degree : degreeList) {
        delete degree;
    }

    return 0;
}