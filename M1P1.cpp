
#include <stdio.h>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Cube
{
    int length;
    int width;
    int height;
    int volume;
    string color;

    public:
    
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

    void setLength()
    {
        int cubeLength;
        cout << "What is the length of the cube in inches? " << endl;
        do
        {
            cin >> cubeLength;
            if (!cin || cubeLength <= 0)
            {
                cout << "Enter a valid positive integer. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while(cubeLength <= 0);
        
        length = cubeLength;
        
    }

    void setWidth()
    {
        int cubeWidth;
        cout << "What is the width of the cube in inches? " << endl;
        do
        {
            cin >> cubeWidth;
            if (!cin || cubeWidth <= 0)
            {
                cout << "Enter a valid positive integer. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while(cubeWidth <= 0);
        
        width = cubeWidth;
        
    }

    void calculateVolume()
    {
        volume = length * width * height;
    }


};

int main() {
    
    Cube self;

    cout << "Hello." << endl;

    
    self.setHeight();
    self.setLength();
    self.setWidth();
    self.calculateVolume();

    cout << "Cube Properties: " << endl;
    cout << "Height: " << self.getHeight() << " in." << endl;
    cout << "Length: " << self.getLength() << " in." << endl;
    cout << "Width: " << self.getWidth() << " in." << endl;
    cout << "Volume: " << self.getVolume() << " inches cubed." <<endl;

    
    
    

    return 0;
}
