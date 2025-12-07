//Program Name: Abstract Base NFL Player Class
//Author: Nathan Schoenike
//Date Last Updated: 12/1/2025
//Purpose: To have a beverage ordering system using inheritance
#include <iostream>
#include <fstream> //for file
#include <vector> //for assignment
#include <limits>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>

using namespace std;

//Abstract base class

class Player
{
    //Player general attributes
    protected: 
    string name;
    int number;

    public: 

    Player(string name, int number)
    {
        this -> name = name;
        this -> number = number;
    }

    virtual void toString() = 0; //pure virtual function
    virtual string getPlayerPosition() = 0;
    virtual string play() = 0;

    string getName()
    {
        return name;
    }

    int getNumber()
    {
        return number;
    }
};

//Sub classes for offense
class QB : public Player
{
    public: 
    QB(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;

    }

    void toString() override
    {
        cout << "Quarterback Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Quarterback";
    }

    string play() override
    {
        return "throws a pass";
    }

};

class WR : public Player
{
    public: 
    WR(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Wide Receiver Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Wide Receiver";
    }

    string play() override
    {
        return "Catches a pass";
    }

};

class TE : public Player
{
    public: 
    TE(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Tight End: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Tight End";
    }

    string play() override
    {
        return "Blocks and catches the ball";
    }

};

class RB : public Player
{
    public: 
    RB(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Running Back Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Running Back";
    }

    string play() override
    {
        return "Runs with the ball";
    }

};

class OL : public Player
{
    public: 
    OL(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Offensive Lineman Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Offensive Linemain";
    }

    string play() override
    {
        return "Protects the quarterback";
    }

};

//Defensive Teams

class DL : public Player
{
    public: 
DL(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Defensive Lineman Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Defensive Lineman";
    }

    string play() override
    {
        return "Tries to sack the quarterback";
    }

};

class LB : public Player
{
    public: 
LB(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Defensive Lineman Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Linebacker";
    }

    string play() override
    {
        return "Tries to sack the quarterback and stop the run/pass";
    }

};

class DB : public Player
{
    public: 
DB(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Defensive Back Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Defensive Back";
    }

    string play() override
    {
        return "Tries to stop the receivers from catching passes";
    }

};


//The special team player types
class K : public Player
{
    public: 
K(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Kicker Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Kicker";
    }

    string play() override
    {
        return "Kicks the football";
    }

};

class H : public Player
{
    public: 
H(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Holder Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Holder";
    }

    string play() override
    {
        return "Holds the football steady for the kicker";
    }

};


class P : public Player
{
    public: 
P(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Punter Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Punter";
    }

    string play() override
    {
        return "Punts the football";
    }

};

class R : public Player
{
    public: 
R(string name, int number) : Player(name, number)
    {
        this -> name = name;
        this -> number = number;
    }

    void toString() override
    {
        cout << "Returner Name: " << name << ", Number: " << number << endl;
    }

    string getPlayerPosition() override
    {
        return "Returner";
    }

    string play() override
    {
        return "Tries to return the football after a punt or kick";
    }

};





int main()
{
    //Vector to hold created players
    vector<Player*> Players;
    int playerCount = 0;
    //choice variable

    cout << "Football Team Roster Creator" << endl;
    cout << "----------------------------" << endl;

    //Loop for creating players

    while(true)
    {
        cout << "Enter QB details:\n\n";
        string name;
        int number;

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* qb = new QB(name, number);
        Players.push_back(qb);

        //WR
        cout << "Enter WR details:\n\n";
        

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* wr = new WR(name, number);
        Players.push_back(wr);

        //TE
        cout << "Enter TE details:\n\n";
        

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* te = new WR(name, number);
        Players.push_back(te);


        //RB

        cout << "Enter RB details:\n\n";
        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* rb = new RB(name, number);
        Players.push_back(rb);

        //OL
        while(true)
        {
            cout << "Enter OL details:\n\n";
            

            cout << "Player Name: " << endl;
            getline(cin, name);
            cout << "Player Number: " << endl;
            cin >> number;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Create player object for each corresponding player
            Player* ol = new OL(name, number);
            Players.push_back(ol);

            int choice;
            cout << "Add another offensive lineman? (1 for no, 2 for yes):" << endl;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!cin || choice < 1 || choice > 2)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter 1 or 2: ";

            }
            else if(choice == 1)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            //continues if they want to add another
            else if(choice == 2)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        //Offense display
        //Index for tracking how many offense players
        int offenseCount = 0;
        cout << "\nOffensive Team Roster:\n";
        for (Player* player : Players)
        {
            string position = player->getPlayerPosition();
            int number = player->getNumber();
            name = player->getName();

            cout <<position << "\n---------------------\n" << "Name: " << name << "\nNumber: " << number << "\nPurpose: " << player->play() << "\n\n";
            offenseCount++;


        

        


        }



        //choice to continue
        int continueChoice;
        cout << "Would you like to add another set of players? (1 for no, 2 for yes):" << endl;
        cin >> continueChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (continueChoice == 1)
        {
            break;
        }
        else if (continueChoice == 2)
        {
            continue;
        }

    }

    int offenseCount = size(Players);

    while(true)
    {
        //Defensive Team
        cout << "Enter DL details:\n\n";
        string name;
        int number;

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* dl = new DL(name, number);
        Players.push_back(dl);

        //LB
        cout << "Enter LB details:\n\n";
        

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* lb = new LB(name, number);
        Players.push_back(lb);

        //DB
        cout << "Enter DB details:\n\n";
        

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* db = new DB(name, number);
        Players.push_back(db);

        //Defense display
        //Takes the offernse count to know what players to not display
        cout << "\nDefensive Team Roster:\n";
        for (int i = offenseCount; i < size(Players); i++)
        {
            Player* player = Players[i];
            {
            string position = player->getPlayerPosition();
            int number = player->getNumber();
            name = player->getName();

            cout <<position << "\n---------------------\n" << "Name: " << name << "\nNumber: " << number << "\nPurpose: " << player->play() << "\n\n";
            }
        }
    
    

    }

    //Defense count to know how many players on defense
    int defenseCount = size(Players) - offenseCount;

    while(true)
    {
        //Special Teams
        cout << "Enter Kicker details:\n\n";
        string name;
        int number;

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* k = new K(name, number);
        Players.push_back(k);

        //Punter
        cout << "Enter Punter details:\n\n";
        

        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* p = new P(name, number);
        Players.push_back(p);

        cout << "Enter Holder details:\n\n";
        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* h = new H(name, number);;
        Players.push_back(h);

        cout << "Enter Returner details:\n\n";
        cout << "Player Name: " << endl;
        getline(cin, name);
        cout << "Player Number: " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* r = new R(name, number);
        Players.push_back(r);

        //Special Teams display
        //Takes the offense and defense count to know what players to not display
        cout << "\nSpecial Teams Roster:\n";
        for (int i = offenseCount + defenseCount; i < size(Players); i++)
        {
            Player* player = Players[i];
            {
            string position = player->getPlayerPosition();
            int number = player->getNumber();
            name = player->getName();

            cout <<position << "\n---------------------\n" << "Name: " << name << "\nNumber: " << number << "\nPurpose: " << player->play() << "\n\n";
            }
        }
    
    

    }

    cout <<"Number of Players on team: " << size(Players) << endl;
    cout << "Offense Players: " << offenseCount << endl;
    cout << "Defense Players: " << defenseCount << endl;
    cout << "Special Teams Players: " << size(Players) - (offenseCount + defenseCount) << endl;
    
    return 0;
}
