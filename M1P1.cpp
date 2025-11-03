//Program Name: Cube Calculator
//Author: Nathan Schoenike
//Date Last Updated: 11/3/2025
//Purpose: Calculate the volume of a cube based on input
#include <iostream>
#include <string>
#include <climits>
#include <limits>



using namespace std;

class Cube
{
    int length;
    int width;
    int height;
    int volume;
    //added a default so my setter doesnt get stuck in infinite loop
    string color = "Red (Default)";

    public:
    //my getters
     int getWidth()
    {
        return width;
    }
    
    int getHeight()
    {
        return height;
    }
    
    int getLength()
    {
        return length;
    }

    int getVolume()
    {
        return volume;
    }

    string getColor()
    {
        return color;
    }

    //setHeight method with validation
    void setHeight()
    {
        int cubeHeight;
        cout << "What is the height of the cube in inches? " << endl;
        do
        {
            cin >> cubeHeight;
            if (!cin || cubeHeight <= 0)
            {
                cout << "Enter a valid positive integer. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while(cubeHeight <= 0);
        
        height = cubeHeight;
        
    }
    //simple setLength method with validation
    void setLength()
    {
        int cubeLength;
        cout << "What is the length of the cube in inches? " << endl;
        do
        {
            cin >> cubeLength;
            if (!cin || cubeLength <= 0)
            {
                cout << "Enter a valid positive number. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while(cubeLength <= 0);
        
        length = cubeLength;
        
    }

    //simple setWidth method
    void setWidth()
    {
        int cubeWidth;
        cout << "What is the width of the cube in inches? " << endl;
        do
        {
            cin >> cubeWidth;
            if (!cin || cubeWidth <= 0)
            {
                cout << "Enter a valid positive integer . " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while(cubeWidth <= 0);
        
        width = cubeWidth;
        
    }

    //My setColor method. It can take in numbers, something I would rather not have. I did want to give the user option to pick
    //their own unique color instead of a preset  though
    void setColor()
    {
        string cubeColor;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "What is the color of the cube? " << endl;
        do
        {
            
            getline(cin, cubeColor);
            if (cubeColor.empty())
            {
                cout << "Enter a valid color. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            
            
        } while (cubeColor.empty());

        color = cubeColor;

        
    }

    //volume is calculated at the end after all measurements are taken in
    void calculateVolume()
    {
        volume = length * width * height;
    }

    


};

int main() {
    
    Cube self;

  
    //call setters after creating object
    
    self.setHeight();
    self.setLength();
    self.setWidth();
    self.setColor();
    self.calculateVolume();

    //my display
    cout << "Cube Properties: " << endl;
    cout << "Height: " << self.getHeight() << " in." << endl;
    cout << "Length: " << self.getLength() << " in." << endl;
    cout << "Width: " << self.getWidth() << " in." << endl;
    cout << "Volume: " << self.getVolume() << " inches cubed." <<endl;
    cout << "Color: " << self.getColor() << endl;

    int changeOption;
    
    while (true)
    {
        cout << "Would you like to change anything? (1 for yes, 0 for no)" << endl;
        cin >> changeOption;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (changeOption == 1) 
        {
            int changeMenu;
            cout << "What would you like to change? (1) Height (2) Length (3) Width (4) Color. (Or 5 to exit)" << endl;

            //input validation
            do
            {
                cin >> changeMenu;
                if (!cin || changeMenu <= 0 || changeMenu > 5)
                {
                    cout << "Please enter a valid option (1-5)." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            } while (!cin || changeMenu <= 0 || changeMenu > 5);


            
            //switch for which item to change
            switch(changeMenu)
            {
                case 1: self.setHeight();
                break;
                case 2: self.setLength();
                break;
                case 3: self.setWidth();
                break;
                case 4: self.setColor();
                break;
                case 5: 
                
                break;


            }
            //call volume to update if anything is changed
            self.calculateVolume();
            cout << "Cube Properties: " << endl;
    cout << "Height: " << self.getHeight() << " in." << endl;
    cout << "Length: " << self.getLength() << " in." << endl;
    cout << "Width: " << self.getWidth() << " in." << endl;
    cout << "Volume: " << self.getVolume() << " inches cubed." <<endl;
    cout << "Color: " << self.getColor() << endl;
            continue;
        }  
        

        if (changeOption == 0)
        {
            cout << "Goodbye" << endl;
            break;
        }
    
    }
        return 0;
    }


    

    

