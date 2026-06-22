#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Dectermine variables
    ifstream teamsFile("teams.txt");
    ifstream winnersFile("WorldSeriesWinners.txt");
    string teamName;
    string winnerName;
    int count = 0;

    // Display all teams from the file
    cout << "Teams that have won the World Series:\n";
    while (getline(teamsFile, teamName))
    {
        cout << teamName << endl;
    }
    
    // Ask user to enter a team name
    cout << "\nEnter the name of a team: ";
    getline(cin, teamName);
    
    // Count how many times the team appears in the winners file
    while (getline(winnersFile, winnerName))
    {
        if (winnerName == teamName)
        {
            count++;
        }
    }
    
    // Display the result
    cout << "\n" << teamName << " has won the World Series " << count << " time(s).\n";
    
    return 0;
}
