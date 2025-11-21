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

class nerfGun
{
    //attributes
    string model;
    int range;
    int capacity;
    int numDarts;

    public:
    //constructor
    nerfGun(string mod, int ran, int cap, int darts)
    {
        if (cap > 144)
        {
            throw invalid_argument("The dart capacity cannot be greater than 144. ");
        }

        if (ran < 0)
        {
            throw invalid_argument("Range must be a positive integer. ");
        }

        if (darts > cap)
        {
            throw invalid_argument("You do not have enough space for darts in the nerf gun chamber. ");
        }
        model = mod;
        range = ran;
        capacity = cap;
        numDarts = darts;
    }

    void setModel()
    {
        //only validation for if its empty
        string mod;
        cout << "Nerf Model:" << endl;
        
        while(true)
        {
            getline(cin, mod);
            
            if (mod.empty())
            {
                cout << "Please enter a nerf model name. " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        
    }
}