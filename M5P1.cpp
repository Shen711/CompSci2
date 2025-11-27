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

    public:
    Coffee(string name, 
        string description,
        int servingSize;
        string coffeeType, string temp, string caffeine, string strength, string creamer, string sweetener) : Beverage(name, description, servingSize, calories, price)
    {
        this -> coffeeType = coffeeType;
        this -> temp = temp;
        this -> caffeine = caffeine;
        this -> strength = strength;
        this -> creamer = creamer;
        this -> sweetener = sweetener;
    }

};
