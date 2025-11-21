//Program Name: State Selector
//Author: Nathan Schoenike
//Date Last Updated: 11/17/2025
//Purpose: To read files from a txt and display information for state based on input

#include <fstream> //for file
#include <vector> //for assignment
#include <limits>
#include <string>
#include <iostream>
#include <cctype> //for convertingg to all uppercase
#include <algorithm> //for transform function
#include <iomanip>
#include <ctime>

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
    nerfGun(string model, int range, int capacity)
    {
        if (capacity > 144)
        {
            throw invalid_argument("The dart capacity cannot be greater than 144. ");
        }

        

        
        
        numDarts = capacity;
    }

    string getModel() const
    {
        return model;
    }

    int getRange()
    {
        return range;
    }

    int getCapacity() const
    {
        return capacity; 
    }

    int getDartCount()
    {
        return numDarts;
    }

    void reload(int quantity)
    {
        if ((numDarts + quantity) > capacity )
        {
            throw overflow_error("The capacity is not sufficient for that many darts!");
        }
        numDarts += quantity;
    }

    void fire()
    {
            if (numDarts <= 0)
            {
                throw underflow_error("You have no bullets to fire!");
                
                
            }
            else
            {
                numDarts--;
            }
    }

    // void setModel()
    // {
    //     //only validation for if its empty
    //     string mod;
    //     cout << "Nerf Model:" << endl;
        
    //     while(true)
    //     {
    //         getline(cin, mod);
            
    //         if (mod.empty())
    //         {
    //             cout << "Please enter a nerf model name. " << endl;
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     model = mod;
        
        
    // }

    
}