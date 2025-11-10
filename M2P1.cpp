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
//arrays to hold month days and month names. Indexes corresponds to each other.
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNames[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    public:

    //constructor with parameters
    Date(int d, int m, int y)
    
    {
        //throw conditions for parameters when first modifying or constructing the object. Will not be true when update is selected.
        if (y > 2020 || y < 1900)
        {
            throw invalid_argument("The year must be an integer between 1900 and 2000. ");
        }
        if (m > 12 || m < 1)
        {
            throw invalid_argument("There are only twelve months in a year. Enter a valid integer month number. ");
        }
        
        //logic to correspond day input with month input and check for days
        if (d < 1 || d > monthDays[m-1])
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

    //setters with conditional throws. No validation because that is done when values are assigned to the object in main. This is to follow the instructions
    void setDay()
    {
        
        int d;
        cout << "Which day is the date? " << endl;
        cin >> d;
        //logic to correspond day input with month input and check for days in the month
        if (d < 1 || d > monthDays[month-1])
        {
            throw invalid_argument("You must have at least one day and no more than the amount in the selected month.");

        }

        
        
        day = d;
        

    }

    void setMonth()
    {
        int m;
        cout << "Which month is the date? " << endl;
        cin >> m;
        if (m > 12 || m < 1)
        {
            throw invalid_argument("There are only twelve months in a year. Enter a valid integer month number. ");
        }
        
        

        month = m;

    }
        
        
        



    

    void setYear()
    {
        int y;
        cout << "Which year is the date? " << endl;
        
        cin >> y;
        if (!cin || y > 2020 || y < 1900)
        {
            throw invalid_argument("The year must be an integer between 1900 and 2000. ");
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        

        
        
        year = y;
        
    }

    //toString method to display the date formatted per instructions
    void toString()
    {
        int d = getDay();
        int m = getMonth();
        int y = getYear();
        
        
        string d1 = to_string(d);
        string m1 = (monthNames[m - 1]);
        string y1 = to_string(y);

        cout <<"Date entered: " << m1 << " " << setw(2) << setfill('0') << d1 << ", " << y1 << endl;






    }


};

int main()
{
    int d, m, y;
    //needed to initialize 
    Date UserDate(1, 1, 2000);

    //while loops to keep asking until valid input
    while(true)
    {
    try
    {
        

    cout << "Year: " << endl;
        cin >> y;
        cout << "Month: " << endl;
        cin >> m;
        cout << "Day: " << endl;
        cin >> d;
        UserDate = Date(d, m, y);
        UserDate.toString();

        break;
        //if there are no exceptions thrown the code wont even make it to this point

        
    }
    catch(invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
        cout <<"Try again. " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //clear old data in input
        
    }
    

    
    }

    //modifying menu
    int choice;
    
    while(true)
    {
        cout << "Would you like to modify the date (1 for yes, 0 for no)? " << endl;
        cin >> choice;

        if (!cin || choice < 0 || choice > 1)
        {
            cout << "Error. Input 1 or 0. " << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');

        }
        else if (choice == 0)
        {
            return 0;
        }
        else 
        {
            //while loop to keep asking while throwing potential exceptions for all three setters
            while(true)
            {
                try 
                {
                UserDate.setYear();
                break;
                }
                catch(invalid_argument& e)
                {
                cout << "Error occured: " << e.what() << endl;
                cout << "Try again. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                }
            }
            while(true)
            {
                try 
                {
                UserDate.setMonth();
                break;
                }
                catch(invalid_argument& e)
                {
                cout << "Error occured: " << e.what() << endl;
                cout << "Try again. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                }
            }
            while(true)
            {
                try 
                {
                UserDate.setDay();
                break;
                }
                catch(invalid_argument& e)
                {
                cout << "Error occured: " << e.what() << endl;
                cout << "Try again. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                }
            }
            UserDate.toString();
            


        }
    }

    
}