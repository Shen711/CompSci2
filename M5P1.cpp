//Program Name: Beverage Class
//Author: Nathan Schoenike
//Date Last Updated: 11/26/2025
//Purpose: To create nerf guns and fire and reload them randomly
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

//Parent Class

class Beverage
{
    string name;
    string description;
    int servingSize;
    int calories;
    float price;

    public:


    Beverage(string name, string description, int servingSize, int calories, float price)  
    {
        this -> name = name;
        this -> description = description;
        this -> servingSize = servingSize;
        this -> calories = calories;
        this -> price = price;
    }


};

//Sub-Class
class Coffee : public Beverage
{
    //has to be static if in class
    string coffeeType;
    string temp;
    string caffeine;
    string strength;
    string creamer;
    string sweetener;

    static string coffeeTypes[5];

    public:
    Coffee(string name, 
        string description,
        int servingSize,
        int calories,
        float price,
        string coffeeType, 
        string temp, 
        string caffeine, 
        string strength, 
        string creamer, 
        string sweetener) : 
        
        Beverage(name, description, servingSize, calories, price)
    {
        this -> coffeeType = coffeeType;
        this -> temp = temp;
        this -> caffeine = caffeine;
        this -> strength = strength;
        this -> creamer = creamer;
        this -> sweetener = sweetener;
    }


    void setCoffeeType()
    {
        int choice;
        cout << "Select a Roast Type: " << endl;
        cout << "1. Light" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Dark" << endl;
        cout << "4. French Roast" << endl;
        cout << "5. Espresso" << endl;
        while (true)
        {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5)
             {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter a number between 1 and 5: ";

            }

        this -> coffeeType = coffeeType;
    }
};

//array initizalization
string Coffee::coffeeTypes[5] = {"Light", "Medium", "Dark", "French Roast", "Espresso"};
