#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string trim(const string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

int main()
{
    // Determine variables
    ifstream teamsFile("teams.txt");
    ifstream winnersFile("WorldSeriesWinners.txt");
    string teamName;
    string winnerName;
    int count = 0;

    if (!teamsFile || !winnersFile)
    {
        cout << "Error opening input files." << endl;
        return 1;
    }

    // Display all teams from the file
    cout << "Teams that have won the World Series:\n";
    while (getline(teamsFile, teamName))
    {
        cout << trim(teamName) << endl;
    }
    
    // Ask user to enter a team name
    cout << "\nEnter the name of a team: ";
    getline(cin, teamName);
    teamName = trim(teamName);
    
    // Count how many times the team appears in the winners file
    while (getline(winnersFile, winnerName))
    {
        if (trim(winnerName) == teamName)
        {
            count++;
        }
    }
    
    // Display the result
    cout << "\n" << teamName << " has won the World Series " << count << " time(s).\n";
    
    return 0;
}
