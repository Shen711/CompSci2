//Program Name: Calendar Date
//Author: Nathan Schoenike
//Date Last Updated: 11/9/2025
//Purpose: To input data, convert it to a date, and display the date

#include <string>
#include <iostream>
#include <limits.h>
#include <limits>
#include <iomanip>
#include <map>
//included map to have a corrsepondance between month n

using namespace std;

class Date 
{
    int day;
    int month;
    int year;

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public:

    //
    Date(int d, int m, int y)
    : day(d), month(m), year(y)
    {}

    //getters
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    void setDay()
    {
        int d;
        cout << "Which day is the date? " << endl;
        
        

    }

    void setMonth()
    {
        int m;
        cout << "Which month is the date? " << endl;


    }

    void setYear()
    {
        //max and min years
        int minY = 1900;
        int maxY = 2020;
        int y;

        do 
        {
            cout << "What is the year of the date? " << endl;
            cin >> y;

            
        }
    }


}