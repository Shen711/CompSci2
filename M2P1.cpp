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
    string monthNames[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    public:

    //
    Date(int d, int m, int y)
    
    {
        if (y > 2020 || y < 1900)
        {
            throw invalid_argument("The year must be an integer between 1900 and 2000. ");
        }

        if (m > 12 || m < 1)
        {
            throw invalid_argument("There are only twelve months in a year. Enter a valid integer month number. ");
        }

        //logic to correspond day input with month input and check for days
        if (d > 1 || day > monthDays[m-1])
        {
            throw invalid_argument("You must have at least one day and no more than the amount in the selected month.");

        }
        day = d;
        month = m;
        year = y;

    }

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
        cin >> d;

        day = d;
        

    }

    void setMonth()
    {
        int m;
        cout << "Which month is the date? " << endl;
        cin >> m;
        
        
        

        month = m;

    }
        
        
        



    

    void setYear()
    {
        int y;
        cout << "Which month is the date? " << endl;
        cin >> y;
        
        year = y;

        

        
    }


};

int main()
{
    int d, m, y;

    cout << "Year: " << endl;
        cin >> y;
        cout << "Month: " << endl;
        cin >> m;
        cout << "Day: " << endl;
        cin >> d;
    try
    {
        

        Date UserDate(d, m, y);
        cout << d << m << y;
    }
    catch(invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}