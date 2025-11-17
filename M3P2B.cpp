//Program Name: State Selector
//Author: Nathan Schoenike
//Date Last Updated: 11/17/2025
//Purpose: To read files from a txt and display information for state based on input

#include <fstream> //for file
#include <vector> //for assignment
#include <limits>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <cctype> //for convertingg to all uppercase
#include <algorithm> //for transform function
#include <iomanip>

using namespace std;

//struct object for info for one state
struct StateInfo
{
    string name;
    string gov;
    string flower;
};

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
            //string stream object which represents 1 whole line, inside this line it will look at 4 items below and ignore the unnecessaries
            stringstream ss(line);
            if (getline(ss, abbrev, ',') && getline(ss, name, ',') && getline(ss, govenor, ',') && getline(ss, flower, ' '))
        {
                //abbrev is key value so I assign this value correspondingg to every one that comes after that
                stateMap[abbrev] = {name, govenor, flower};
        }
            
            
        }
        //creates the map then file closed, information that is needed we have now

        wordFile.close();


}

    while (true)
    {
        string input;
        
        
        cout << "Enter a state abbreviation to get info about the state (-1 to quit): " << endl;
        do
        {
            cin >> input;
            
            if (!cin || input.empty())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter a valid state abbreviation. " << endl;
            }
        } while (!cin || input.empty());

        //handles exiting program for -1
        if (input == "-1")
        {
            cout << "Have a good day!" << endl;
            break;
        }

        //I had to find an example online for this but I swear I used it before just like toupper(input), may be thinking of python though
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        cout << "State Info: " << endl;
        if (stateMap.find(input) != stateMap.end())
        {
         cout << "State Name: " << stateMap[input][0] << endl;
            cout << "Governor: " << stateMap[input][1] << endl;
             cout << "State Flower: " << stateMap[input][2] << endl;

        
    }
        else 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Please try again. " << endl;
        }
}
}