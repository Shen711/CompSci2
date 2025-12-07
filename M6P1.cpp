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
    virtual void play() = 0;

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

};