//Program Name: Dark Souls Character creator
//Author: Nathan Schoenike
//Date Last Updated: 12/18/2025
//Purpose: To model the dark souls 1 display menu, and character creation
#include <iostream>
#include <vector> 
#include <limits>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
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
    int availablePts = 10;

    //v,a,e,s,d,r,i,f
    
    //calculates available points remaining for skill upgrade point capacity
    //Unused but decided to keep it in to kind of show you my though process when 
    //starting the project
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


//Base class, just holds name and class name, level is always set to 1 since this
//program only allows for creation and not actual playing(sadly)
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
    
    //the stats method is called in here so all subclasses have access to the stats, not overriden
    void printStats() const
    {
        stats.printStats();
    }
    

    //Constructor w default values for no class, although you have to have a subclass object. No base player allowed
    Character(string name = "Unknown Name", string charClass = "Stranger", vector<string> skills = {"No skills"})
    {
        this -> name = name;
        this -> charClass = charClass;
        this -> level = 1;
        
    }

    //virtual function but not an override
    virtual void toString() const
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "|" << fixed << left << setw(19) << setfill(' ') << name << "Class: "  << fixed << left << setw(25) << setfill(' ') << charClass << "|" << endl;
        cout << "|Level " << left << fixed << setfill(' ') << setw(45) << level << "|" << endl;
        cout << "|Skills: ";
        for (const string& skill : skills)
        {
            
            cout << "." << skill << " ";
            
        }
        cout << "\n";
    }
    
    
    //vectors to hold selected player skills, and class skills that pertain to their specific class
    vector<string> skills;
    vector<string> classSkills;

    //setters
    virtual void setVitality() = 0;
    virtual void setStrength() = 0;
    virtual void setAttunement() = 0;
    virtual void setEndurance() = 0;
    virtual void setDexterity() = 0;
    virtual void setResistance() = 0;
    virtual void setIntelligence() = 0;
    virtual void setFaith() = 0;

    //getters
    virtual string getCharacterClass() = 0;
    
    int getAvailablePts()
    {
        return stats.availablePts;
    }
    

    string getName()
    {
        return name;
    }

    int getLevel()
    {
        return level;
    }


    //This is skills chosen in relation to created player
    const vector<string>& getSkills() const
    {
        return skills;
    }
    //This is availble skills to choose from per class(3)
    const vector<string>& getClassSkills() const
    {
        return classSkills;
    }
    
    int getVitality()
    {
        return stats.vitality;
    }
    int getAttunement()
    {
        return stats.attunement;
    }
    int getStrength()
    {
        return stats.strength;
    }
    int getFaith()
    {
        return stats.faith;
    }
    int getIntelligence()
    {
        return stats.intelligence;
    }
    int getDexterity()
    {
        return stats.dexterity;
    }
    int getResistance()
    {
        return stats.resistance;
    }
    int getEndurance()
    {
        return stats.endurance;
    }



    
};

//Pyromancer subclass
class Pyromancer : public Character
{
    //Pyro Max Stats: v15, a40, s12, d26, r40, e25, i30, f50
    public: 
    Pyromancer(string name, vector<string> skills) : Character(name, "Pyromancer")
    {
        this -> name = name;
        this -> charClass = "Pyromancer";
        classSkills = {"Holy Blast", "Flame Whip", "Melting Motion"};
        stats = {10, 18, 8, 5, 10, 14, 17, 15};
        //Opted for this method^ as opposed to the one below so there are no unexpected errors
        // setVitality(10);
        // setStrength(8);
        // setAttunement(18);

    }


    string getCharacterClass() override
    {
        return "Pyromancer";
    }

    void setVitality() override
    {
        //This will be my format for all subclass setters for Stat attributes. placer is for the current value, pointChanhe is the
        //difference between current and old value. Some classes can not have stats over a certain level like pyromancer
        //having vitality cappped at 15. PointChange is used to modify the available points left for character customization
        //All in a while loop for validation

        
        int v;
        int placer = getVitality();
        int points = getAvailablePts();
        cout << "What would you like to change vitality to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> v;
            if (!cin || v > 15 || v < 0)
            {
                cout << "Max(15)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && v > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            //decreasing a stat adds points to pool
            else if (v < placer)
            {
                pointChange = placer - v;
                stats.availablePts += pointChange; 
                stats.vitality = v;
                break;
            }
            //validation for the increase based on how many points they have
            else if (v > placer)
            {
                pointChange = v - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.vitality = v;

                break;
            }
            
        }
    }

    void setAttunement() override
    {
        
        int a;
        int placer = getAttunement();
        int points = getAvailablePts();
        cout << "What would you like to change attunement to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 40 || a < 0)
            {
                cout << "Max(40)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.attunement = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.attunement = a;
                break;
            }
        }
            
    }
        void setStrength() override
    {

        int a;
        int placer = getStrength();
        int points = getAvailablePts();
        cout << "What would you like to change strength to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 12 || a < 0)
            {
                cout << "Max(12)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.strength = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.strength = a;
                break;
            }
        }
            
    } 

            void setEndurance() override
    {
        
        int a;
        int placer = getEndurance();
        int points = getAvailablePts();
        cout << "What would you like to change endurance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 25 || a < 0)
            {
                cout << "Max(25)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.endurance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.endurance = a;
                break;
            }
        }
            
    }

    void setDexterity() override
    {
        
        int a;
        int placer = getDexterity();
        int points = getAvailablePts();
        cout << "What would you like to change dexterity to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 26 || a < 0)
            {
                cout << "Max(26)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.dexterity = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.dexterity = a;
                break;
            }
        }
            
    }

    void setResistance() override
    {
        
        int a;
        int placer = getResistance();
        int points = getAvailablePts();
        cout << "What would you like to change resistance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 40 || a < 0)
            {
                cout << "Max(40)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.resistance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.resistance = a;
                break;
            }
        }
            
    }

    void setIntelligence() override
    {
        
        int a;
        int placer = getIntelligence();
        int points = getAvailablePts();
        cout << "What would you like to change intelligence to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 30 || a < 0)
            {
                cout << "Max(30)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.intelligence = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.intelligence = a;
                break;
            }
        }
            
    }

    void setFaith() override
    {
        
        int a;
        int placer = getFaith();
        int points = getAvailablePts();
        cout << "What would you like to change faith to" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 50 || a < 0)
            {
                cout << "Max(50)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.faith = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.faith = a;
                break;
            }
        }
            
    }

    
        
};
    //Originally was going to use this for getting class skills but decided to just make them hardcoded in constructor body subclass
    // vector<string> getClassSkills() override
    // {
    //     //Every class has its own unique skills which override the default which is no skills
    //     return {"Holy Blast", "Flame Whip", "Melting Motion"};
    // }

    



class Priest : public Character
{
    //Priest max stats: v30, a45, e19, d26, s12, i30, f50, r27
    public: 
    Priest(string name, vector<string> skills) : Character(name, "Priest", skills)
    {
        this -> name = name;
        this -> charClass = "Priest";
        classSkills = {"God's Grace", "Burnin' Sermon", "Divine Light"};
        stats = {22, 15, 10, 9, 8, 7,10,11};
    }

    

    string getCharacterClass() override
    {
        return "Priest";
    }


    

    void setVitality() override
    {
        //This will be my format for all subclass setters for Stat attributes. placer is for the current value, pointChanhe is the
        //difference between current and old value. Some classes can not have stats over a certain level like pyromancer
        //having vitality cappped at 15. PointChange is used to modify the available points left for character customization
        //All in a while loop for validation
        int v;
        int placer = getVitality();
        int points = getAvailablePts();
        cout << "What would you like to change vitality to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> v;
            if (!cin || v > 30 || v < 0)
            {
                cout << "Max(30)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && v > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (v < placer)
            {
                pointChange = placer - v;
                stats.availablePts += pointChange; 
                stats.vitality = v;
                break;
            }
            else if (v > placer)
            {
                pointChange = v - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.vitality = v;
                break;
            }
            
        }
    }

    void setAttunement() override
    {
        
        int a;
        int placer = getAttunement();
        int points = getAvailablePts();
        cout << "What would you like to change attunement to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 45 || a < 0)
            {
                cout << "Max(45)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.attunement = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.attunement = a;
                break;
            }
        }
            
    }
        void setStrength() override
    {

        int a;
        int placer = getStrength();
        int points = getAvailablePts();
        cout << "What would you like to change strength to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 12 || a < 0)
            {
                cout << "Max(12)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.strength = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.strength = a;
                break;
            }
        }
            
    } 

            void setEndurance() override
    {
        
        int a;
        int placer = getEndurance();
        int points = getAvailablePts();
        cout << "What would you like to change endurance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 19 || a < 0)
            {
                cout << "Max(19)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.endurance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.endurance = a;
                break;
            }
        }
            
    }

    void setDexterity() override
    {
        
        int a;
        int placer = getDexterity();
        int points = getAvailablePts();
        cout << "What would you like to change dexterity to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 26 || a < 0)
            {
                cout << "Max(26)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.dexterity = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.dexterity = a;
                break;
            }
        }
            
    }

    void setResistance() override
    {
        
        int a;
        int placer = getResistance();
        int points = getAvailablePts();
        cout << "What would you like to change resistance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 27 || a < 0)
            {
                cout << "Max(27)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.resistance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.resistance = a;
                break;
            }
        }
            
    }

    void setIntelligence() override
    {
        
        int a;
        int placer = getIntelligence();
        int points = getAvailablePts();
        cout << "What would you like to change intelligence to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 30 || a < 0)
            {
                cout << "Max(30)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.intelligence = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.intelligence = a;
                break;
            }
        }
            
    }

    void setFaith() override
    {
        
        int a;
        int placer = getFaith();
        int points = getAvailablePts();
        cout << "What would you like to change faith to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 50 || a < 0)
            {
                cout << "Max(50)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.faith = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.faith = a;
                break;
            }
        }
            
    }

};
    

    


class Thief : public Character
{
    //Thief max stats: v17, a15, e32, d45, s18, f11, r12, i10 
    public: 
    Thief(string name, vector<string> skills) : Character(name, "Thief", skills)
    {
        this -> name = name;
        this -> charClass = "Thief";
        classSkills = {"Coin Crash", "Deceivery", "Trickster's Pull"};
        stats = {13, 10, 10, 20, 8, 7,10,11};
    }


    string getCharacterClass() override
    {
        return "Thief";
    }


    void setVitality() override
    {
        
        int v;
        int placer = getVitality();
        int points = getAvailablePts();
        cout << "What would you like to change vitality to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> v;
            if (!cin || v > 17 || v < 0)
            {
                cout << "Max(17)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && v > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (v < placer)
            {
                pointChange = placer - v;
                stats.availablePts += pointChange; 
                stats.vitality = v;
                break;
            }
            else if (v > placer)
            {
                pointChange = v - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.vitality = v;
                break;
            }
            
        }
    }

    void setAttunement() override
    {
        
        int a;
        int placer = getAttunement();
        int points = getAvailablePts();
        cout << "What would you like to change attunement to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 15 || a < 0)
            {
                cout << "Max(15)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.attunement = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.attunement = a;
                break;
            }
        }
            
    }
        void setStrength() override
    {

        int a;
        int placer = getStrength();
        int points = getAvailablePts();
        cout << "What would you like to change strength to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 18 || a < 0)
            {
                cout << "Max(18)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.strength = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.strength = a;
                break;
            }
        }
            
    } 

            void setEndurance() override
    {
        
        int a;
        int placer = getEndurance();
        int points = getAvailablePts();
        cout << "What would you like to change endurance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 32 || a < 0)
            {
                cout << "Max(32)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.endurance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.endurance = a;
                break;
            }
        }
            
    }

    void setDexterity() override
    {
        
        int a;
        int placer = getDexterity();
        int points = getAvailablePts();
        cout << "What would you like to change the dexterity to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 45 || a < 0)
            {
                cout << "Max(45)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.dexterity = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.dexterity = a;
                break;
            }
        }
            
    }

    void setResistance() override
    {
        
        int a;
        int placer = getResistance();
        int points = getAvailablePts();
        cout << "What would you like to change resistance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 12 || a < 0)
            {
                cout << "Max(12)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.resistance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.resistance = a;
                break;
            }
        }
            
    }

    void setIntelligence() override
    {
        
        int a;
        int placer = getIntelligence();
        int points = getAvailablePts();
        cout << "What would you like to change the intelligence to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 10 || a < 0)
            {
                cout << "Max(10)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.intelligence = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.intelligence = a;
                break;
            }
        }
            
    }

    void setFaith() override
    {
        
        int a;
        int placer = getFaith();
        int points = getAvailablePts();
        cout << "What would you like to change faith to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 11 || a < 0)
            {
                cout << "Max(11)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.faith = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.faith = a;
                break;
            }
        }
            
    }


};

class Fighter : public Character
{
    //Fighter max stats: v30, a13, e18, 24s, 19r, 10i ,8f, d32
    public: 
    Fighter(string name, vector<string> skills) : Character(name, "Fighter", skills)
    {
        this -> name = name;
        this -> charClass = "Fighter";
        classSkills = {"Fell Sweep", "Angry Charge", "Sword Slam"};
        stats = {27, 10, 15, 23, 18, 9, 7, 5};
        //v,a,e,s,d,r,i,f
    }

  

    string getCharacterClass() override
    {
        return "Fighter";
    }


    void setVitality() override
    {

        int v;
        int placer = getVitality();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> v;
            if (!cin || v > 30 || v < 0)
            {
                cout << "Max(30)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && v > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (v < placer)
            {
                pointChange = placer - v;
                stats.availablePts += pointChange; 
                stats.vitality = v;
                break;
            }
            else if (v > placer)
            {
                pointChange = v - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.vitality = v;
                break;
            }
            
        }
    }

    void setAttunement() override
    {
        
        int a;
        int placer = getAttunement();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 13 || a < 0)
            {
                cout << "Max(13)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.attunement = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.attunement = a;
                break;
            }
        }
            
    }
        void setStrength() override
    {

        int a;
        int placer = getStrength();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 24 || a < 0)
            {
                cout << "Max(24)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.strength = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.strength = a;
                break;
            }
        }
            
    } 

            void setEndurance() override
    {
        
        int a;
        int placer = getEndurance();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 18 || a < 0)
            {
                cout << "Max(18)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.endurance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.endurance = a;
                break;
            }
        }
            
    }

    void setDexterity() override
    {
        
        int a;
        int placer = getDexterity();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 32 || a < 0)
            {
                cout << "Max(32)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.dexterity = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.dexterity = a;
                break;
            }
        }
            
    }

    void setResistance() override
    {
        
        int a;
        int placer = getResistance();
        int points = getAvailablePts();
        cout << "What would you like to change the stat too?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 19 || a < 0)
            {
                cout << "Max(19)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.resistance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.resistance = a;
                break;
            }
        }
            
    }

    void setIntelligence() override
    {
        
        int a;
        int placer = getIntelligence();
        int points = getAvailablePts();
        cout << "What would you like to change the stat to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 10 || a < 0)
            {
                cout << "Max(10)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.intelligence = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.intelligence = a;
                break;
            }
        }
            
    }

    void setFaith() override
    {
        
        int a;
        int placer = getFaith();
        int points = getAvailablePts();
        cout << "What would you like to change the stat to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 8 || a < 0)
            {
                cout << "Max(8)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.faith = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.faith = a;
                break;
            }
        }
            
    }

    
};

//v,a,e,s,d,r,i,f
class Barbarian : public Character
{
    //Barbarian max stats: v52, a5, e15, s35, d6, r12, i3, f3 
    public: 
    Barbarian(string name, vector<string> skills) : Character(name, "Barbarian", skills)
    {
        this -> name = name;
        this -> charClass = "Barbarian";
        classSkills = {"Brolic Blast", "MeatHead Swing", "Hunky Hateness"};
        stats = {30, 3, 13, 26, 8, 6, 2, 1};
    }


    string getCharacterClass() override
    {
        return "Barbarian";
    }



    void setVitality() override
    {

        int v;
        int placer = getVitality();
        int points = getAvailablePts();
        cout << "What would you like to change vitality to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> v;
            if (!cin || v > 52 || v < 0)
            {
                cout << "Max(52)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && v > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (v < placer)
            {
                pointChange = placer - v;
                stats.availablePts += pointChange; 
                stats.vitality = v;
                break;
            }
            else if (v > placer)
            {
                pointChange = v - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.vitality = v;
                break;
            }
            
        }
    }

    void setAttunement() override
    {
        
        int a;
        int placer = getAttunement();
        int points = getAvailablePts();
        cout << "What would you like to change attunement to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 5 || a < 0)
            {
                cout << "Max(5)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.attunement = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.attunement = a;
                break;
            }
        }
            
    }
        void setStrength() override
    {

        int a;
        int placer = getStrength();
        int points = getAvailablePts();
        cout << "What would you like to change strength to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 35 || a < 0)
            {
                cout << "Max(35)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.strength = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.strength = a;
                break;
            }
        }
            
    } 

            void setEndurance() override
    {
        
        int a;
        int placer = getEndurance();
        int points = getAvailablePts();
        cout << "What would you like to change endurance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 15 || a < 0)
            {
                cout << "Max(15)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.endurance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.endurance = a;
                break;
            }
        }
            
    }

    void setDexterity() override
    {
        
        int a;
        int placer = getDexterity();
        int points = getAvailablePts();
        cout << "What would you like to change dexterity to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 6 || a < 0)
            {
                cout << "Max(6)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.dexterity = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.dexterity = a;
                break;
            }
        }
            
    }

    void setResistance() override
    {
        
        int a;
        int placer = getResistance();
        int points = getAvailablePts();
        cout << "What would you like to change resistance to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 12 || a < 0)
            {
                cout << "Max(12)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.resistance = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.resistance = a;
                break;
            }
        }
            
    }

    void setIntelligence() override
    {
        
        int a;
        int placer = getIntelligence();
        int points = getAvailablePts();
        cout << "What would you like to change intelligence to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 3 || a < 0)
            {
                cout << "Max(3)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.intelligence = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.intelligence = a;
                break;
            }
        }
            
    }

    void setFaith() override
    {
        
        int a;
        int placer = getFaith();
        int points = getAvailablePts();
        cout << "What would you like to change faith to?" << endl;
        int pointChange;
        while(true)
        {
            cin >> a;
            if (!cin || a > 3 || a < 0)
            {
                cout << "Max(3)" << endl;
                cout <<"Invalid input. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
            }
            else if(stats.availablePts <= 0 && a > placer)
            {
                cout << "No available attribute points to distibrute." << endl;
                cout <<  "Finish creating or lower some attribute points..." << endl;
                break;
            }
            else if (a < placer)
            {
                pointChange = placer - a;
                stats.availablePts += pointChange; 
                stats.faith = a;
                break;
            }
            else if (a > placer)
            {
                pointChange = a - placer;
                if (pointChange > stats.availablePts)
                {
                    cout << "You do not have enough points to increase by " << pointChange << "!" << endl;
                    continue;
                }
                stats.availablePts -= pointChange;
                stats.faith = a;
                break;
            }
        }
            
    }

    
};


//Main program
int main()
{
    //vector to hold characters
    vector<Character*> Characters;
    string name;    
    vector<string> skills;
    
    //allocate memory for the soon to be character
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
            //exit game
            else if (choice == 4)
            {
            cout << "Exiting to desktop..." << endl;
            return 0;
            }
            //options menu, wont incorporate
            else if (choice == 3)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Options menu is unmodifiable. Returning to main menu...\n" << endl;
                break;
                
            }
            //load save
            else if (choice == 2)
            {
                int menu2Choice;
                int openSaves = 3 - Characters.size();
                int savedGames = Characters.size();

                cout << "----------Saved Characters---------" << endl;
                for(Character* character : Characters)
                {

                    character->toString();
   
                }
                //display to show availble save slots
                for (int i = 0; i < openSaves; i++)
                {
                    cout << "-----------------------------------------------------" << endl;
                    cout << fixed << left << setw(52) << setfill(' ') << "|No Save Found"  << "|" << endl;
                    cout << "-----------------------------------------------------" << endl;
                }   
                cout << "Select which save to load in(9 to exit): " << endl;
                while(true)
                {
                    
                    cin >> menu2Choice;

                    if (!cin || menu2Choice < 0 || menu2Choice > 3 && menu2Choice != 9)
                    {
                        cout <<"Invalid option. Try again(1-3): " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;

                    }
                    else if (menu2Choice == 9)
                    {
                        cout << "Exiting to main menu...." << endl;
                        break;
                    }
                    else if (menu2Choice > savedGames && menu2Choice < 4)
                    {
                        cout << "You have an open save slot " << menu2Choice << endl;
                        cout << "Create one using the main menu!\n" << endl;
                        //then directs to main menu
                        break;
                    }
                    else
                    {
                        Character* chosenC = Characters[menu2Choice - 1];
                        string n = chosenC->getName();
                        string c = chosenC->getCharacterClass();
                        cout << "Loading in to game as: " << n << " the " << c << endl;
                        cout << "Have a grand time!" << endl;
                        return 0;
                    }


                }
                //goes back to main menu
                break;
            }
            
            //actual player creation
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
                        case 4:
                            characterPtr = new Fighter(name, skills);
                            break;
                        case 5:
                            characterPtr = new Barbarian(name, skills);
                            break;
                    }
                    Characters.push_back(characterPtr);
                    cout << "--------------------------------\n";
                    cout << "Name: " << characterPtr->getName() << endl;
                    cout << "Class: " << characterPtr->getCharacterClass() << endl;
                    characterPtr->printStats();
                    //initial object character creation finished, then stats
                    cout << "--------------------------------\n";
                    
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
                        else if (input == 9)
                        {
                            break;
                        }
                        
                        switch(input)
                        {
                           
                            case 1:
                            
                                characterPtr->setVitality();
                                break;
                            case 2:
                                characterPtr->setAttunement();
                                break;
                            case 3:
                                characterPtr->setEndurance();
                                break;
                            case 4:
                                characterPtr->setStrength();
                                break;
                            case 5:
                                characterPtr->setDexterity();
                                break;
                            case 6:
                                characterPtr->setResistance();
                                break;
                            case 7:
                                characterPtr->setIntelligence();
                                break;
                            case 8:
                                characterPtr->setFaith();
                            default:
                                break;

                        }

                        cout << "-------------------------------" << endl;
                        characterPtr->printStats();
                    }

                    cout << "--------------------------------\n";
                    int skillChoice;

                    const auto& classSkills = characterPtr->getClassSkills();
                    
                    cout << "Add from the selection of " << characterPtr->getCharacterClass() << " skills (Only 2!): " << endl;
                    characterPtr->getClassSkills();
                    
                    for (int i = 0; i < classSkills.size(); i++)
                    {
                        cout << i + 1 << ". " << classSkills[i] << endl;

                    }
                    //vector for holding skills in this instance for counting
                    vector<string> mySkills;

                    while(mySkills.size() < 2)
                    {
                        cin >> skillChoice;
                        if (skillChoice > 3 || skillChoice < 1)
                        {
                            cout << "Invalid selection. Try again." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        
                        
                        string skill = classSkills[skillChoice - 1];
                        

                        if (find(mySkills.begin(), mySkills.end(), skill) != mySkills.end()) 
                        {
                        cout << "You already selected that skill. Pick a different one." << endl;
                        continue;
                        }
                        mySkills.push_back(skill);
                    }

                    characterPtr->skills = mySkills;
                    const auto& playerSkills = characterPtr->skills;

                    cout << "------------------------------------------\n";
                    cout << characterPtr->getName() << " the " << characterPtr->getCharacterClass() << endl;
                    //All starting characters are level 1
                    cout << "Level 1" << endl;
                    cout << "Skills: " ;
                    for (int i = 0; i < characterPtr->skills.size(); i++)
                    {
                        cout << characterPtr->skills[i] << ", ";
                    }
                    cout << "Stats: " << endl;
                    characterPtr->printStats();
                    cout << "\n-----------------------------------\n";
                    cout << "Character Successfully Created..." << endl;
                    cout << "Exiting to main menu....." << endl;
                    
                    cout << "\n---------------------------------\n";

                    break;  
                }
            }
        }
    }
    return 0;
}