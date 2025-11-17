//Program Name: Non-Duplicate Words
//Author: Nathan Schoenike
//Date Last Updated: 11/17/2025
//Purpose: To read in a file and display the words in the file in ascending order

#include <fstream> //for file
#include <vector> //for assignment
#include <limits>
#include <string>
#include <iostream>
#include <map>

using namespace std;


int main()
{
    map<string, vector<string>> stateMap;

    string abbrev, name, govenor, flower;

    fstream wordFile("M3P2B.txt");

    if (!wordFile)
    {
        cout << "Could not open file. Try again" << endl;
        return 0;
    }

    else 
    {
        while (wordFile >> abbrev >> name >> govenor >> flower)
        {
            stateMap[abbrev].push_back(name);
            stateMap[abbrev].push_back(govenor);
            stateMap[abbrev].push_back(flower);
        }
    }

    for (auto state : stateMap)
    {
        cout << "State Abbreviation: " << state.first << endl;
        cout << "State Name: " << state.second[0] << endl;
        cout << "Governor: " << state.second[1] << endl;
        cout << "State Flower: " << state.second[2] << endl;
        cout << "-----------------------------" << endl;
    }
}