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

    bool operator <(const nerfGun& othergun) const
    {
            return numDarts < othergun.numDarts;
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
    guns.emplace_back("Honey-moon", 40, 120);

    for (const auto& gun : guns)
    {
        cout  << gun;
    }

    //Ask to fire
    while(true)
    {

        int fireNum;
        int choice;
        cout << "Would you like to fire(1), reload(2) or exit(0)?: " << endl;
        cin >> choice;

        //shoot
        if (choice == 1)
        {
            //random seed 
            srand(time(0));
            //example
            //a = user
            //b = 10
            // c = a + b

            

            //I wanted to try something different from your example but still follow instructions.
            //Yours helped me out with the structure and understanding overloading
            //but I wanted to add some more to demonstrate I know how to do it
            try
            {
                
                //pick a random valid index and how many times it shoots the gun
                int gunIndex = rand() % guns.size();
                int numTimes = rand() % 144 + 1;
                fireNum = numTimes;
                cout << "--------------------------\n";
                cout << "Firing the " << guns[gunIndex].getModel() << " with " 
                << guns[gunIndex].getDartCount() << " current darts." << endl;
                cout << "-----------------------" << endl;
                //fire it a random amount of times
                for (int i = 0; i < numTimes; ++i)
                {
                    --guns[gunIndex];
                }

                

                cout << "The " << guns[gunIndex].getModel() << " has " << guns[gunIndex].getDartCount() 
                << " darts after firing " << numTimes << endl; 


            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n' << "Tried to fire " << fireNum << " darts!";
                
            }
            

        }

        //reload
        else if (choice == 2)
        {
            try
            {
                int amount;
            //pick a random valid index
            int gunIndex = rand() % guns.size();
            cout << "Will try to reload the " << guns[gunIndex].getModel() << ". Please hold..." << endl;
            cout << guns[gunIndex];
            while (true)
            {
                
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

            guns[gunIndex] += amount;
            cout << "--------------------------" << endl;
            cout << "The " << guns[gunIndex].getModel() << " has " << guns[gunIndex].getDartCount() << " darts now. " << endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            

        }

        

        

        //exit
        else if (choice = 3)

        {
            //This is what I started with, I dont know if it follows the instructions because I dont use the < operand but maybe it does because of max?
            //Either way I just went with one like in the example because it explicity compares with a < b
            // auto maxDarts = max_element(guns.begin(), guns.end());

            auto maxDarts = max_element(guns.begin(), guns.end(), [](const nerfGun& gun1, const nerfGun& gun2) 
        {
            if (gun1 < gun2)
            {
                return gun1 < gun2;
            }
            else if (gun1 == gun2)
            {
                return gun1 == gun2;
            }
        });
            
            
            cout << "Statistics" << endl;
            cout << "------------------" << endl;
            for (const auto& gun : guns)
            {
                cout  << gun;
                cout << "------------------" << endl;
            }

            cout << "Gun with the most ammo: " << endl;
            cout << "------------------" << endl;
            cout << *maxDarts;
            cout << "------------------" << endl;
            

        }

        
    }

    


    


}