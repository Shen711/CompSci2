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

//Made a stats struct so instead of keeping track of each sub class objects stat individually
//I bundle it up in a sort of package so its easily accessible
struct Stats
{
    //stats
    int vitality = 0;
    int attunement = 0;
    int endurance = 0;
    int strength = 0;
    int dexterity = 0;
    int resistance = 0;
    int intelligence = 0;
    int faith = 0;
    int availablePts = 97;
    //sum
    
    //calculates available points remaining for skill upgrade point capacity
    int getSum()
    {
        
        int sum = vitality + attunement + endurance + strength + dexterity + resistance + intelligence + faith;
        return availablePts - sum;
    }




    void printStats() const
    {
        cout << "Vitality: " << vitality<< endl;
        cout << "Attunement: " << attunement << endl;
        cout << "Endurance: " << endurance << endl;
        cout << "Strength: "  << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Resistance: " << resistance << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Faith: " << faith << endl;
        cout << "Points Available: " << availablePts << endl;

    }
};

enum class CharacterClass
{
    Pyromancer = 1,
    Priest = 2,
    Thief = 3,
    Knight = 4,
    Barbarian = 5
};

class Character
{
    protected: 
    string name;
    string charClass;
    //every character starts at level 1
    int level = 1;
    //Stats struct object with all smaller stats
    Stats stats;

    public: 
    
    void printStats() const
    {
        stats.printStats();
    }
    

    //Constructor w default values for no class
    Character(string name = "Unknown Name", string charClass = "Stranger", vector<string> skills = {"No skills"})
    {
        this -> name = name;
        this -> charClass = charClass;
        this -> level = 1;
        
    }

    virtual void toString() = 0; //virtual functions
    virtual string getCharacterClass() = 0;
    
    //vectors to hold selected player skills, and class skills that pertain to their specific class
    vector<string> skills;
    vector<string> classSkills;

    //setters
    virtual void setVitality(int v) = 0;
    // void setVitality(int v)
    // {
        
    //     stats.vitality = v;
    // }
    void setStrength(int s)
    {
        stats.strength = s;
    }
    void setAttunement(int a)
    {
        stats.attunement = a;
    }
    void setEndurance(int e)
    {
        stats.endurance = e;
    }
    void setDexterity(int d)
    {
        stats.dexterity = d;
    }
    void setResistance(int r)
    {
        stats.resistance = r;
    }
    void setIntelligence(int i)
    {
        stats.intelligence = i;
    }
    void setFaith(int f)
    {
        stats.faith = f;
    }


    //Display
    const vector<string>& getSkills() const
    {
        return skills;
    }
    const vector<string>& getClassSkills() const
    {
        return classSkills;
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
    Pyromancer(string name, vector<string> skills) : Character(name, "Pyromancer")
    {
        this -> name = name;
        this -> charClass = "Pyromancer";
        classSkills = {"Holy Blast", "Flame Whip", "Melting Motion"};
        stats = {10, 18, 8, 5, 10, 14, 17, 15};
        // setVitality(10);
        // setStrength(8);
        // setAttunement(18);

    }

    void toString() override
    {
        cout << "Pyromancer Name: " << name << ", Level: " << level << endl;
    }

    string getCharacterClass() override
    {
        return "Pyromancer";
    }

    void setVitality(int v) override
    {
        if (v > 15 || v < 0)
        {
            cout << "Too high, try again. Class max strength: 15" << endl;
        }
        else
        {
            stats.vitality = v;
        }
    }
    //Originally was going to use this for getting class skills but decided to just make them hardcoded in constructor body subclass
    // vector<string> getClassSkills() override
    // {
    //     //Every class has its own unique skills which override the default which is no skills
    //     return {"Holy Blast", "Flame Whip", "Melting Motion"};
    // }

    

};

class Priest : public Character
{
    public: 
    Priest(string name, vector<string> skills) : Character(name, "Priest", skills)
    {
        this -> name = name;
        this -> charClass = "Priest";
        classSkills = {"God's Grace", "Burnin' Sermon", "Divine Light"};
        stats = {22, 15, 10, 9, 8, 7,10,11};
    }

    void toString() override
    {
        cout << "Name: " << name << ", Level: " << level << endl;
    }

    string getCharacterClass() override
    {
        return "Priest";
    }

    void setVitality(int v) override
    {
        if (v > 15 || v < 0)
        {
            cout << "Pyromancer max strength: 15" << endl;
        }
        else
        {
            stats.vitality = v;
        }
    }
    

    

};
class Thief : public Character
{
    public: 
    Thief(string name, vector<string> skills) : Character(name, "Thief", skills)
    {
        this -> name = name;
        this -> charClass = "Thief";
        classSkills = {"Coin Crash", "Deceivery", "Trickster's Pull"};
    }

    void toString() override
    {
        cout << "Name: " << name << ", Level: " << level << endl;
    }

    string getCharacterClass() override
    {
        return "Thief";
    }

    void setVitality(int v) override
    {
        if (v > 15 || v < 0)
        {
            cout << "Pyromancer max strength: 15" << endl;
        }
        else
        {
            stats.vitality = v;
        }
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
        cout << "      Dark Souls 1\n" << endl;
        cout << "------------------------\n";
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

                //if there are maxed out saves then it will show(max of 3)
                if(Characters.size() == 3)
                {
                    cout << "Max saves reached. Please delete a save to create a new one." << endl;
                    break;
                }
                else
                {
                    string name;
                    int classChoice;

                    cout << "------------------------\n";
                    cout << "Enter your character's name: ";
                    while(true)
                    {
                        getline(cin, name);
                        if(name.empty())
                        {
                            cout << "Name cannot be empty. Please enter a valid name: ";
                        }
                        else
                        {
                            break;
                        }
                    }

                    cout << "------------------------\n";
                    cout << "Choose your character class:\n";
                    cout << "1. Pyromancer\n"
                         << "2. Priest\n"
                         << "3. Thief\n"
                         << "4. Knight\n"
                         << "5. Barbarian\n";
                    cout << "------------------------\n";
                    //input validation for choice 1 -5(classes)
                    while(true)
                    {
                        cin >> classChoice;

                        if (!cin || classChoice < 1 || classChoice > 5)
                        {
                            cout << "Please enter a valid choice (1-5): ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else
                        {
                            break;
                        }
                    }
                    switch(classChoice)
                    {
                        case 1:
                            characterPtr = new Pyromancer(name, skills);
                            break;
                        case 2:
                            characterPtr = new Priest(name, skills);
                            break;
                        case 3:
                            characterPtr = new Thief(name, skills);
                            break;
                        // case 4:
                        //     characterPtr = new Knight(name, skills);
                        //     break;
                        // case 5:
                        //     characterPtr = new Barbarian(name, skills);
                        //     break;
                    }
                    Characters.push_back(characterPtr);
                    characterPtr->toString();
                    characterPtr->printStats();
                    //initial object character creation finished, then stats
                    cout << "-------------------\n";
                    
                    while(true)
                    {
                        int input;
                        int inputStat;
                        cout << "(To edit click a corresponding number of the stats, vitality = 1 or 9 to exit and finish character creation.)" << endl;
                        cin >> input;

                        if (!cin || input > 9 || input < 1)
                        {
                            cout << "Invalid selection. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;

                        }
                        cout << "Now enter the value you want that stat to be: " << endl;
                        cin >> inputStat;
                        switch(input)
                        {
                            
                            case 1:
                                cout << "New vitality: " << endl;
                                cin >> inputStat;
                                characterPtr->setVitality(inputStat);
                                break;
                        }
                        characterPtr->printStats();
                    }
                    
                    
                }
            }
    
        }
    }
    return 0;
}