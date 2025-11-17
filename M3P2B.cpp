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
#include <sstream>

using namespace std;

struct StateInfo
{
    string name;
    string gov;
    string flower;
}

int main()
{
    map<string, vector<string>> stateMap;

    string abbrev, name, govenor, flower;

    //had to do some research and find how to ignore the commas and included certain whitespaces. using ss I can read each line and divide it up using the seperator with getline
    string line;

    fstream wordFile("M3P2B.txt");

    if (!wordFile)
    {
        cout << "Could not open file. Try again" << endl;
        return 0;
    }

    else 
    {
        while (getline(wordFile, line))
        {
            //string stream object which represents 1 whole line
            stringstream ss(line);
            string ab = getline (ss, abbrev, ",");
            string n = getline (ss, name, ",");
            string gov = getline (ss, govenor, ",");
            string fl = getline (ss, flower, ",");
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