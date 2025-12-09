//Program Name: Dark Souls Character creator
//Author: Nathan Schoenike
//Date Last Updated: 12/7/2025
//Purpose: To create players to add to a football team
#include <iostream>
#include <fstream> 
#include <vector> 
#include <limits>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>

using namespace std;

class Character
{
    protected: 
    string name;
    string charClass;
    int level = 1;
    vector<string> skillArray;

    public: 

    //Constructor w default values for no class
    Character(string name = "Unknown", string charClass = "Stranger", vector<string> skills = {"No skills. (Default)"})
    {
        this -> name = name;
        this -> charClass = charClass;
        this -> level = level;
        this -> skillArray = skills;
    }

    virtual void toString() = 0; //virtual functions
    virtual string getCharacterClass() = 0;
    virtual vector<string> getSkills() = 0;

    //Display
    void thisClassSkills()
    {
        cout << "Skills for " << charClass << ": " << endl;
        for (const auto& skill : skillArray)
        {
            cout << "- " << skill << endl;
        }
    }

    

    string getName()
    {
        return name;
    }

    int getLevel()
    {
        return level;
    }
};

//Pyromancer subclass
class Pyromancer : public Character
{
    public: 
    Pyromancer(string name, vector<string> skills) : Character(name, "Pyromancer", skills)
    {
        this -> name = name;
        this -> charClass = "Pyromancer";
        this -> skillArray = skills;
    }

    void toString() override
    {
        cout << "Pyromancer Name: " << name << ", Level: " << level << endl;
    }

    string getCharacterClass() override
    {
        return "Pyromancer";
    }
    vector<string> getSkills() override
    {
        //Every class has its own unique skills which override the default which is no skills
        return {"Holy Blast", "Flame Whip", "Melting Motion"};
    }

    

};

class Priest : public Character
{
    public: 
    Priest(string name, vector<string> skills) : Character(name, "Priest", skills)
    {
        this -> name = name;
        this -> charClass = "Priest";
        this -> skillArray = skills;
    }

    void toString() override
    {
        cout << "Pyromancer Name: " << name << ", Level: " << level << endl;
    }

    string getCharacterClass() override
    {
        return "Priest";
    }
    vector<string> getSkills() override
    {
        
        return {"God's Grace", "Burnin' Sermon", "Divine Light"};
    }

    

};


//Main program
int main()
{
    vector<Character*> Characters;
    string name;    
    vector<string> skills;
    
    Character* characterPtr = nullptr;
    //Menu loop
    while(true)
    {
        cout << "         Dark Souls 1\n" << endl;
        cout << "        ------------------------\n";
        cout << "1. Start New Save\n"
             << "2. Load Save\n"
             << "3. Options\n"
             << "4. Exit Game\n";
        cout << "------------------------\n"; 

        while (true)
        {
            int choice;

            cin >> choice;

            if (!cin || choice < 1 || choice > 4)
            {
                cout << "Please enter a valid choice (1-4): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (choice == 4)
            {
            cout << "Exiting to desktop..." << endl;
            return 0;
            }
            else if (choice == 3)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Options menu is currently unavailable. Returning to main menu." << endl;
                break;
                
            }
            else if (choice == 2)
            {
                for(Character* character : Characters)
                {
                    string charClass = character->getCharacterClass();
                    name = character->getName();
                    skills = character->getSkills();
                
                }
            }
            else if (choice == 1)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
       
    }
}
}