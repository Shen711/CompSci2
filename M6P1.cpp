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

//Sub class
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

int main()
{
    //Vector to hold created players
    vector<Player*> Players;

    //choice variable

    cout << "Football Team Roster Creator" << endl;
    cout << "----------------------------" << endl;

    //Loop for creating players

    while(true)
    {
        cout << "Enter QB details:\n\n";
        string name;
        int number;

        cout << "Player Name (): " << endl;
        getline(cin, name);
        cout << "Player Number (): " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* qb = new QB(name, number);
        Players.push_back(qb);

        //WR
        cout << "Enter QB details:\n\n";
        string name;
        int number;

        cout << "Player Name (): " << endl;
        getline(cin, name);
        cout << "Player Number (): " << endl;
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Create player object for each corresponding player
        Player* wr = new WR(name, number);
        Players.push_back(wr);


        for (Player* player : Players)
        {
            player -> toString();
        }



        

       


    }




}
