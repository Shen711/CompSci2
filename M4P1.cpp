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
            throw invalid_argument("The dart capacity cannot be greater than 144. \n");
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
            throw overflow_error("The capacity is not sufficient for that many darts! \n");
        }
        numDarts += quantity;
    }

    void fire()
    {
            if (numDarts <= 0)
            {
                throw underflow_error("You have no bullets to fire! \n");
                
                
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

    string model;
    int range, capacity;

    vector<nerfGun> guns;

    cout << "Create Nerf Guns: " << endl;
    while(true)
    {
        cout << "Model: " << endl;
        getline(cin, model);
        
        cout << "Range: " << endl;
        cin >> range;
        

        cout << "Capacity (144 Max):"<< endl;
        cin >> capacity;
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');

        guns.emplace_back(model, range, capacity);



    }

    // guns.emplace_back("Sharknado", 25, 100);
    // guns.emplace_back("Bulldozer", 50, 75);
    // guns.emplace_back("Destroyer", 30, 120);
    // guns.emplace_back("Honey-moon", 40, 120);
    // guns.emplace_back("Berzerker", 10, 144);
    // guns.emplace_back("Kettle", 5, 45);

    cout << "Nerf Guns Available: \n";
    cout << "---------------------------" << endl;

//initial display
    for (const auto& gun : guns)
    {
        cout  << gun;
        cout << "----------------------------" << endl;
    }

    //Ask to fire
    while(true)
    {

        int fireNum;
        int dartsFired;
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
                
                //pick a random valid index and how many times it shoots the gun between max ammo cap and 1
                int gunIndex = rand() % guns.size();
                int numTimes = rand() % 144 + 1;
                int dartCount = guns[gunIndex].getDartCount();
                
                fireNum = numTimes;
                cout << "--------------------------\n";
                cout << "Firing the " << guns[gunIndex].getModel() << " with " 
                << guns[gunIndex].getDartCount() << " current darts." << endl;
                cout << "-----------------------" << endl;
                //fire it a random amount of times
                for (int i = 0; i < numTimes; ++i)
                {
                    --guns[gunIndex];
                    dartsFired++;
                    

                }

                

                cout << "The " << guns[gunIndex].getModel() << " has " << guns[gunIndex].getDartCount() 
                << " darts after firing " << numTimes << endl; 


            }
            catch(const std::exception& e)
            {
                cout << "------------------------" << endl;
                cerr << e.what() << '\n' << "Tried to fire " << fireNum << " darts! Only fired " << 
                dartsFired << " darts. \n";
                dartsFired = 0;
                
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
            //inpot validation
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
            //use += overload
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
            
                return gun1 < gun2;
            
            
        });

        //get dart count of that  instance and hold it as the maximum number, later used to check with == operand for equal ammo sizes
        int maxNum = maxDarts->getDartCount();

            
            
            
            cout << "Statistics" << endl;
            cout << "------------------" << endl;
            for (const auto& gun : guns)
            {
                cout  << gun;
                cout << "------------------" << endl;
            }

            cout << "Gun with the most ammo: " << endl;
            cout << "------------------" << endl;
            
            
            

            for ( auto& gun : guns )
            {
                if (gun.getDartCount() == maxNum)
                {
                    cout << gun;
                    cout << "-------------------" << endl;
                }
            }
            

        }

        
    }

    


    


}