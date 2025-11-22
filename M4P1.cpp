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
#include <stdexcept>

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

        //this lets the compiler know left hand side is the instance,
        //otherwise it sees it as the two same variables. Left is member
        this -> model = model;
        this -> range = range;
        this -> capacity = capacity;
    }

    string getModel() const
    {
        return model;
    }

    //Question: when this wasnt const program didnt work
    int getRange() const
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

    //overloads
    bool operator==(const nerfGun& gun2) const
    {
        return numDarts == gun2.numDarts;
    }

    // bool operator<(const nerfGun& gun2 ) const
    // {
        
    // }

    nerfGun& operator+=(int quantity)
    {
        //Question: Does it return the member variable of the object its referencing?
        reload(quantity);
        return *this;
    }

    nerfGun& operator --()
    {
        fire();
        return *this;
    }


    //had to copy this over from your example. I'm still  trying to wrap my head around
    //the overloading but this one has me a little lost
    friend ostream& operator<<(std::ostream& os, const nerfGun& gun) 
    {
    os << "Model: " << gun.getModel() << "\nRange: " << gun.getRange() << "\nCapacity: "
    << gun.getCapacity() << "\nDart Count: " << gun.numDarts << "\n";

    return os;
    }

    

    

    
};

int main()
{
    vector<nerfGun> guns;

    guns.emplace_back("Sharknado", 25, 100);
    guns.emplace_back("Bulldozer", 50, 75);
    guns.emplace_back("Destroyer", 30, 120);

    for (const auto& gun : guns)
    {
        cout  << gun;
    }

    //Ask to fire
    while(true)
    {
        int choice;
        cout << "Would you like to fire(1), reload(2) or exit(0)?: " << endl;
        cin >> choice;

        //shoot
        if (choice = 1)
        {
            //random seed 
            srand(time(0));
            //example
            //a = user
            //b = 10
            // c = a + b

            

            try
            {
                int numTimes = rand
                //pick a random valid index
                int gunIndex = rand() % guns.size();
                cout << "--------------------------\n";
                cout << "Firing the " << guns[gunIndex].getModel() << " with " 
                << guns[gunIndex].getDartCount() << "darts.";
                //fire it 
                --guns[gunIndex];

                cout << "The " << guns[gunIndex].getModel() << " has " << guns[gunIndex].getDartCount() << endl; 


            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            

        }

        //reload
        else if (choice = 2)
        {
            
            //pick a random valid index
            int gunIndex = rand() % guns.size();
            cout << "Will try to reload the " << guns[gunIndex].getModel() << ". Please hold..." << endl;
            cout << guns[gunIndex];
            while (true)
            {
                int amount;
                cout << "How many darts?" << endl;
                cin >> amount;
                if (!cin || amount < 1)
                {
                    cout << "Error. Please enter more than 1 dart. " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
                }
                else 
                {
                    break;
                }
            }

        }

        //exit
        else if (choice = 3)
        {

        }

        
    }

    


    


}