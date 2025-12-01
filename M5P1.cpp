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
    protected:
    string name;
    string description;
    string servingSize;
    int calories;
    float price;

    public:


    Beverage(string name, string description, string servingSize, int calories, float price)  
    {
        this -> name = name;
        this -> description = description;
        this -> servingSize = servingSize;
        this -> calories = calories;
        this -> price = price;
    }

    void setSize()
    {
        int choice;
        cout << "Which size (1 for small, 2 for medium, 3 for large)?: " << endl;
        
        while (true)
        {
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3)
             {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter a number between 1 and 3: ";

            }
            else if(choice == 1)
            {
                servingSize = "Small";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else if(choice == 2)
            {
                servingSize = "Medium";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else if(choice == 3)
            {
                servingSize = "Large";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
    }

    


        }

void getDrinkDesc()
    {
                cout << "Name: " << name << endl;
                cout << "Size: " << servingSize << '\n' <<
                 "Price: $" << fixed << setprecision(2) << to_string(price) << '\n' <<
                 "Calories: " << to_string(calories) << " cal" << '\n' <<
                 "Description: " << endl;
                 cout <<"-----------------\n" <<  description << endl;
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
    
    Coffee(
        string description = "",
        string servingSize = "Medium",
        int calories = 100,
        float price = 2.50,
        string coffeeType = "Medium", 
        string temp = "Hot", 
        string caffeine = "Caffeinated", 
        string strength = "Regular", 
        string creamer = "0 Creams", 
        string sweetener = "0 Sweeteners"
        ) : 
        
        Beverage("Coffee", description, servingSize, calories, price)
    {
        this -> coffeeType = coffeeType;
        this -> temp = temp;
        this -> caffeine = caffeine;
        this -> strength = strength;
        this -> creamer = creamer;
        this -> sweetener = sweetener;

        //I wanted to find a way to do this without having a description setter, so I found how to use protected
        this -> description = getDetails();
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
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

       
        }
        
    }

         void setTemp()
         {
            int choice;
            cout << "Temperature (1 for cold, 2 for hot):" << endl;
            while (true)
            {
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter 1 or 2: ";

                }
                else if(choice == 1)
                {
                    temp = "Cold";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 2)
                {
                    temp = "Hot";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

         }
        }

        void setCaffeine()
         {
            int choice;
            cout << "Caffeine (1 for no, 2 for yes)?:" << endl;
            while (true)
            {
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter 1 or 2: ";

                }
                else if(choice == 1)
                {
                    caffeine = "Decaf";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 2)
                {
                    caffeine = "Caffeinated";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

         }
        }

        void setStrength()
         {
            int choice;
            cout << "Strength (1 for weak, 2 for average, 3 for strong)?:" << endl;
            while (true)
            {
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 3)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter a number between 1 and 3: ";

                }
                else if(choice == 1)
                {
                    strength = "Weak";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 2)
                {
                    strength = "Regular";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 3)
                {
                    strength = "Strong";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

         }
        }

        void setCreamer()
        {
            int cchoice;
            cout << "How many creamers? (Max 5):" << endl;

            while (true)
            {
                cin >> cchoice;

                if (cin.fail() || cchoice < 0 || cchoice > 5)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter a number between 0 and 5: ";

                }
                else
                {
                    creamer = to_string(cchoice) + " Creams";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            
        }
    }
    void setSweetener()
        {
            int schoice;
            cout << "How many sweeteners? (Max 5):" << endl;

            while (true)
            {
                cin >> schoice;

                if (cin.fail() || schoice < 0 || schoice > 5)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter a number between 0 and 5: ";

                }
                else
                {
                    sweetener = to_string(schoice) + " Sweeteners";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            
        }
    }
            void setDescription()
            {
                this -> description = getDetails();
            }

            string getDetails()
            {
                return 
                ( "Coffee Type: " + coffeeType + '\n' + 
                 "Temperature: " + temp + '\n' +
                 "Caffeine: " + caffeine + '\n' +
                 "Strength: " + strength + '\n'
                 + "Creamer: " + creamer + '\n' 
                 + "Sweetener: " + sweetener + '\n');
            }
        


    };

class Tea : public Beverage
{
    string teaType;
    string temp;
    string creamer;
    string sweetener;
    string lemon;

    public: 

    static string teaTypes[5];
    Tea(
        string description = "",
        string servingSize = "Medium",
        int calories = 50,
        float price = 2.00,
        string teaType = "Black", 
        string temp = "Hot", 
        string creamer = "0 Creams", 
        string sweetener = "0 Sweeteners",
        string lemon = "No Lemon"
        ) : 
        
        Beverage("Tea", description, servingSize, calories, price)
    {
        this -> teaType = teaType;
        this -> temp = temp;
        this -> creamer = creamer;
        this -> sweetener = sweetener;
        this -> lemon = lemon;

        this -> description = getDetails();
    }

    void setTeaType()
    {
        int choice;
        cout << "Select a Roast Type: " << endl;
        cout << "1. Black" << endl;
        cout << "2. Oolong" << endl;
        cout << "3. Herbal" << endl;
        cout << "4. Chamomille" << endl;
        
        while (true)
        {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 4)
             {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter a number between 1 and 5: ";

            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

       
        }
        
        teaType = teaTypes[choice - 1];
        
    }

    void setCreamer()
        {
            int cchoice;
            cout << "How many creamers? (Max 5):" << endl;

            while (true)
            {
                cin >> cchoice;

                if (cin.fail() || cchoice < 0 || cchoice > 5)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter a number between 0 and 5: ";

                }
                else
                {
                    creamer = to_string(cchoice) + " Creams";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            
            }
        }
        void setSweetener()
        {
            int schoice;
            cout << "How many sweeteners? (Max 5):" << endl;

            while (true)
            {
                cin >> schoice;

                if (cin.fail() || schoice < 0 || schoice > 5)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter a number between 0 and 5: ";

                }
                else
                {
                    sweetener = to_string(schoice) + " Sweeteners";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            
            }
        }

        void setLemon()
        {
            int choice;
            cout << "Lemon (1 for no, 2 for yes)?:" << endl;
            while (true)
            {
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter 1 or 2: ";

                }
                else if(choice == 1)
                {
                    lemon = "No Lemon";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 2)
                {
                    lemon = "With Lemon";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

            }
        }
            void setDescription()
            {
                this -> description = getDetails();
            }

            string getDetails()
            {
                return 
                ( "Type: " + teaType + '\n' + 
                 "Temperature: " + temp + '\n' +
                 + "Creamer: " + creamer + '\n' 
                 + "Sweetener: " + sweetener + '\n' +
                 + "Lemon: " + lemon + '\n');
            }
};




//array initizalization
string Coffee::coffeeTypes[5] = {"Light", "Medium", "Dark", "French Roast", "Espresso"};
string Tea::teaTypes[5] = {"Black", "Green", "Oolong", "White", "Herbal"};


int main()
{
    vector <Beverage*> drinkOrders;
    int choice;
    cout << "Drink Order System" << endl;
    cout << "---------------------------------" << endl;
    cout << "Pick a drink with corresponding number." << endl;

    while (true)
    {
        
        cout << "Drink Menu:" <<endl;
        cout << "1. Coffee" << endl;
        cout << "2. Tea" << endl;
        cout << "3. Tea" << endl;
        cout << "4. Energy Drink" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5)
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Please enter 1 or 2: ";

        }
        else if(choice == 1)
        {
            Coffee myCoffee;
            myCoffee.setSize();
            myCoffee.setCoffeeType();
            myCoffee.setTemp();
            myCoffee.setCaffeine();
            myCoffee.setStrength();
            myCoffee.setCreamer();
            myCoffee.setSweetener();

            myCoffee.setDescription();

            cout << "Your Coffee Details:" << endl;
            myCoffee.getDrinkDesc();
            drinkOrders.push_back(new Coffee(myCoffee));
            continue;
            
        }
        else if(choice == 2)
        {
            Tea myTea;

            myTea.setSize();
            myTea.setCreamer();
            myTea.setSweetener();
            myTea.setDescription();
            cout << "Your Tea Details:" << endl;
            myTea.getDrinkDesc();
            drinkOrders.push_back(new Tea(myTea));
            continue;
        }
        else if (choice == 5)
        {
            for (int i = 0; i < drinkOrders.size(); i++)
            {
                drinkOrders[i] -> getDrinkDesc();
                
            
            }
        }
    }
};