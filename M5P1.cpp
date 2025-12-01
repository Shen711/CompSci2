//Program Name: Beverage Class
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

    //Had this initially but I figured different drinks have different calorie and 
    //price changes based on size so I did it for subclasses seperately
    // void setSize()
    // {
    //     int choice;
    //     cout << "Which size (1 for small, 2 for medium, 3 for large)?: " << endl;
        
    //     while (true)
    //     {
    //         cin >> choice;

    //         if (cin.fail() || choice < 1 || choice > 3)
    //          {
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //             cout << "Error. Please enter a number between 1 and 3: ";

    //         }
    //         else if(choice == 1)
    //         {
    //             servingSize = "Small";
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //             break;
    //         }
    //         else if(choice == 2)
    //         {
    //             servingSize = "Medium";
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //             break;
    //         }
    //         else if(choice == 3)
    //         {
    //             servingSize = "Large";
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //             break;
    //         }
    // }

    


        

        //my toString method, will rename 
void toString()
    {
        
                cout << "Name: " << name << endl;
                cout << "Size: " << servingSize << '\n' <<
                 "Price: $" << fixed << setprecision(2) << price << '\n' <<
                 "Calories: " << to_string(calories) << " cal" << '\n' <<
                 "Description: " << endl;
                 cout <<"-----------------\n" <<  description << endl;
    }
    
};

//Sub-Class
class Coffee : public Beverage
{
    
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


    //setters, struggled with coffeeType but now that its done I will use about the same 
    //structure for other subclasses and methods
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
                //Price stays same for small
                break;
            }
            else if(choice == 2)
            {
                servingSize = "Medium";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 0.50;
                calories += 30;
                
                break;
            }
            else if(choice == 3)
            {
                servingSize = "Large";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 1.05;
                calories += 70;
                break;
            }
    }
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

        coffeeType = coffeeTypes[choice - 1];
        
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
                     //decaf costs less
                    break;
                }
                else if(choice == 2)
                {
                    caffeine = "Caffeinated";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    price += 0.25;
                    calories += 10;
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
                    price += 0.25;
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
                    calories = calories + (cchoice * 10); //each creamer is 10 calories
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
                    calories = calories + (schoice * 15); //each sweetener is 15 calories
                    break;
                }
            
        }
    }

        //Need to get details from each specific subclass so I will have the subclass
        //attributes represented as the description, each subclass specific getDetails will
        //be slightly different in what it represents. Its one big string though
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
                //Price stays same for small
                break;
            }
            else if(choice == 2)
            {
                servingSize = "Medium";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 0.50;
                calories += 30;
                break;
            }
            else if(choice == 3)
            {
                servingSize = "Large";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 1.05;
                calories += 60;
                break;
            }
    }
}

    void setTeaType()
    {
        int choice;
        cout << "Select a Roast Type: " << endl;
        cout << "1. Black" << endl;
        cout << "2. Green" << endl;
        cout << "3. Oolong" << endl;
        cout << "4. Chamomille" << endl;
        cout << "5. Special" << endl;
        
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
        
        teaType = teaTypes[choice - 1];
        
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
                    calories = calories + (cchoice * 10); //each creamer is 10 calories
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
                    calories = calories + (schoice * 15); //each sweetener is 15 calories
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
                    price += 0.05;
                    calories += 5;
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

//Energy Drink class
class EnergyDrink : public Beverage
{
    string brand;
    string stimulant;
    string sweetener;
    

    public: 

    static string energyBrands[5];
    EnergyDrink(
        string description = "",
        string servingSize = "Medium",
        int calories = 250,
        float price = 3.00,
        string stimulant = "Caffeine", 
        string brand = "Monster", 
        string sweetener = "No Sweeteners"
    ) : 
        
        Beverage("Energy Drink", description, servingSize, calories, price)
    {
        this ->  stimulant = stimulant;
        this -> brand = brand;
        this -> sweetener = sweetener;
        

        this -> description = getDetails();
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
                //Price stays same for small
                break;
            }
            else if(choice == 2)
            {
                servingSize = "Medium";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 1.00;
                calories += 140;
                break;
            }
            else if(choice == 3)
            {
                servingSize = "Large";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 2.00;
                calories += 300;
                break;
            }
    }
}

    void setEnergyBrand()
    {
        int choice;
        cout << "Select a Soda Brand: " << endl;
        cout << "1. Monster" << endl;
        cout << "2. Red Bull" << endl;
        cout << "3. Rockstar" << endl;
        cout << "4. Bang" << endl;
        cout << "5. 5 Hour Energy" << endl;
        
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
        
        brand = energyBrands[choice - 1];
        
    }

        void setStimulantType()
    {
        int choice;
        cout << "Select a Stimulant Type: " << endl;
        cout << "1. Caffeine" << endl;
        cout << "2. Taurine" << endl;
        cout << "3. Caffeine and Taurine" << endl;
        cout << "4. No Stimulant" << endl;
        
        
        
        while (true)
        {

            //Just did it all manually instead of making an array, less options than the 
            //other subclasses
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5)
             {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please enter a number between 1 and 5: ";

            }
            else if (choice == 1)
            {
                stimulant = "Caffeine";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else if (choice == 2)
            {
                stimulant = "Taurine";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else if (choice == 3)
            {
                stimulant = "Caffeine and Taurine";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 1.00;
                break;
            }
            else if (choice == 4)
            {
                stimulant = "No Stimulant";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price -= 0.50;
                break;
            }
            else
            {
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
                    calories = calories + (schoice * 15); //each sweetener is 15 calories
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
                //returns a string that is more of a sentence 
                return 
                ( stimulant + " " + brand + 
                 " energy drink with  " + sweetener + '\n'
                 );
            }
};

//Soda class
class Soda : public Beverage
{
    string brand;
    string flavorType;
    string dietStatus;
    

    public: 

    static string flavorTypes[5];
    static string sodaBrands[5];
    Soda(
        string description = "",
        string servingSize = "Medium",
        int calories = 200,
        float price = 3.00,
        string flavorType = "Normal", 
        string brand = "Coke", 
        string dietStatus = "Non-diet"
    ) : 
        
        Beverage("Soda", description, servingSize, calories, price)
    {
        this ->  flavorType = flavorType;
        this -> brand = brand;
        this -> dietStatus = dietStatus;
        

        this -> description = getDetails();
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
                //Price stays same for small
                break;
            }
            else if(choice == 2)
            {
                servingSize = "Medium";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 0.50;
                calories += 120;
                break;
            }
            else if(choice == 3)
            {
                servingSize = "Large";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price += 1.00;
                calories += 240;
                break;
            }
    }
}

    void setSodaBrand()
    {
        int choice;
        cout << "Select a Soda Brand: " << endl;
        cout << "1. Coke" << endl;
        cout << "2. Sprite" << endl;
        cout << "3. Dr. Pepper" << endl;
        cout << "4. Root Beer" << endl;
        cout << "5. RC" << endl;
        
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
        
        brand = sodaBrands[choice - 1];
        
    }

        void setFlavorType()
    {
        int choice;
        cout << "Select a soda flavor: " << endl;
        cout << "1. Original" << endl;
        cout << "2. Cherry" << endl;
        cout << "3. Vanilla" << endl;
        cout << "4. Lemon" << endl;
        cout << "5. Grape" << endl;
        
        
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
        
        flavorType = flavorTypes[choice - 1];
        
    }

    //was able to repurpose setLemon into setDietStatus
            void setDietStatus()
        {
            int choice;
            cout << "Diet (1 for no, 2 for yes)?:" << endl;
            while (true)
            {
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2)
                 {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please enter 1 or 2: ";

                }
                //Prices are same for non diet and diet
                else if(choice == 1)
                {
                    dietStatus = "Non-diet";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if(choice == 2)
                {
                    dietStatus = "Diet";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    calories -= 100;
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
                //returns a string that is more of a sentence 
                return 
                ( dietStatus + " " + flavorType + 
                 " " + brand + " soda" + '\n'
                 );
            }
};



//array initizalization
string Coffee::coffeeTypes[5] = {"Light", "Medium", "Dark", "French Roast", "Espresso"};
string Tea::teaTypes[5] = {"Black", "Green", "Oolong", "Chamomille", "Special"};
string Soda::sodaBrands[5] = {"Coke", "Sprite", "Dr. Pepper", "Root Beer", "RC"};
string Soda::flavorTypes[5] = {"Original", "Cherry", "Vanilla", "Lemon", "Grape"};
string EnergyDrink::energyBrands[5] = {"Monster", "Red Bull", "Rockstar", "Bang", "5 Hour Energy"};


int main()
{

    // Vector which holds pointers to Beverage objects
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
        cout << "3. Soda" << endl;
        cout << "4. Energy Drink" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5)
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Please enter 1 or 2: ";

        }
        //Coffee
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
            myCoffee.toString();
            drinkOrders.push_back(new Coffee(myCoffee));
            continue;
            
        }
        //Tea
        else if(choice == 2)
        {
            Tea myTea;

            myTea.setSize();
            myTea.setTeaType();
            myTea.setTemp();
            myTea.setCreamer();
            myTea.setSweetener();
            myTea.setLemon();

            //After I get all subclass specific attributes set, I set the description so
            //it updates with the new data
            myTea.setDescription();
            cout << "Your Tea Details:" << endl;
            myTea.toString();
            drinkOrders.push_back(new Tea(myTea));
            continue;
        }
        //Soda
        else if (choice == 3)
        {
            Soda mySoda;

            mySoda.setSize();
            mySoda.setSodaBrand();
            mySoda.setFlavorType();
            mySoda.setDietStatus();

            mySoda.setDescription();

            cout << "Your Soda Details:" << endl;
            mySoda.toString();
            drinkOrders.push_back(new Soda(mySoda));
            continue;
        }
        //Energy drink
        else if (choice == 4)
        {
            EnergyDrink myEnergyDrink;

            myEnergyDrink.setSize();
            myEnergyDrink.setEnergyBrand();
            myEnergyDrink.setStimulantType();
            myEnergyDrink.setSweetener();

            myEnergyDrink.setDescription();

            cout << "Your Energy Drink Details:" << endl;
            myEnergyDrink.toString();
            drinkOrders.push_back(new EnergyDrink(myEnergyDrink));
            continue;
        }
        //End program and show summary of orders
        else if (choice == 5)
        {

            cout << "Order Summary:" << endl;
            cout << "--------------------------" << endl;
            for (int i = 0; i < drinkOrders.size(); i++)
            {
                
                cout << "\nOrder " << (i + 1) << " Details:" << endl;
                drinkOrders[i] -> toString();
                
            
            }
            cout << "\nHave a good day!" << endl;

            return 0;
        }
    }
};