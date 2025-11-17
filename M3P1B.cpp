//Program Name: Computer Data
//Author: Nathan Schoenike
//Date Last Updated: 11/16/2025
//Purpose: To input data about PCs and store them in a vector
#include <string>
#include <iostream>
#include <limits.h>
#include <limits>
#include <vector>

using namespace std;

class Computer 
{
    string manufacturer;
    string formFactor;
    int serialNumber;
    string processor;
    int ram;
    string sType;
    string sSize;

    

    public:
    Computer(string mfr, string form, int serial, string pro, int RAM, string type, string size)
    {
        //used same constructor validation copied from M2P2.cpp for possible exceptions
        if (mfr.empty())
        {
            throw invalid_argument("Manufacturer cannot be empty. ");
        }
        if (form.empty())
        {
            throw invalid_argument("Form factor cannot be empty. ");
        }
        if (serial < 0)
        {
            throw invalid_argument("Serial number must be a positive integer. ");
        }
        if (pro.empty())
        {
            throw invalid_argument("Processor cannot be empty. ");
        }
        if (RAM <= 0)
        {
            throw invalid_argument("RAM must be a positive integer. ");
        }
        if (type.empty())
        {
            throw invalid_argument("Storage type cannot be empty. ");
        }
        if (size.empty())
        {
            throw invalid_argument("Storage size must be 4, 8 or 16GB. ");
        }
       
        manufacturer = mfr;
        formFactor = form;
        serialNumber = serial;
        processor = pro;
        ram = RAM;
        sType = type;
        sSize = size;

    }

    //getters
    string getManufacturer()
    {
        return manufacturer;
    }
    string getFormFactor()
    {
        return formFactor;
    }
    int getSerialNumber()
    {
        return serialNumber;
    }
    string getProcessor()
    {
        return processor;
    }
    int getRAM()
    {
        return ram;
    }
    string getStorageType()
    {
        return sType;
    }
    string getStorageSize()
    {
        return sSize;
    }

    //setters
    //They will throw exceptions to the catch used in the main individually for each variable
 
    //Only have setters for the variables that are mentioned in the assignment description.
    void setRAM()
    {
        int RAM;
        cout << "RAM (4, 6, 8, 16, 32, or 64GB): " << endl;
        cin >> RAM;
        if (!cin || RAM <= 0 || (RAM != 4 && RAM != 6 && RAM != 8 && RAM != 16 && RAM != 32 && RAM != 64))
        {
            throw invalid_argument("RAM must be one of the following sizes: 4, 6, 8, 16, 32, or 64GB. ");
        }
        ram = RAM;

    }

    void setStorageSize()
    {
        string size;
        cout << "Storage Size (128GB, 256GB, 512GB, 1TB, 2TB): " << endl;
        cin >> size;
        if (sSize.empty())
        {
            throw invalid_argument("Storage size must be 128GB, 256GB, 512 GB, 1TB, or 2TB. ");
        }
        sSize = size;
                
    }

    void setStorageType()
    {
        string type;
        cout << "Storage Type (e.g. HDD, SSD, UFS): " << endl;
        cin >> type;
        if (sType.empty())
        {
            throw invalid_argument("Storage type cannot be empty. ");
        }
        sType = type;
        
    }

    void toString()
    {
        cout << "Manufacturer: " << getManufacturer() << endl;
        cout << "Form Factor: " << getFormFactor() << endl;
        cout << "Serial Number: " << getSerialNumber() << endl;
        cout << "Processor: " << getProcessor() << endl;
        cout << "RAM: " << getRAM() << "GB" << endl;
        cout << "Storage Type: " << getStorageType() << endl;
        cout << "Storage Size: " << getStorageSize() << endl;
    }

    
};  


int main()
{
    //This is my vector that will hold all the PC's built

    vector<Computer> pcList;
    int serial;
    string manufacturer;
    string formFactor;
    string processor;
    int ram;
    string storageType;
    string storageSize;
    

    Computer myPC("Dell", "Desktop", 123456, "I7", 16, "SSD", "64GB");

    //In this loop it asks for variables from user then inserts into the constructor. If error occurs you will have to input all variables again. 

    cout << "Welcome to the PC Data Entry System." << endl;
    cout << "------------------------------" << endl;
    while (true)
    {
        
        cout << "Please enter information about your PC using our pre-set options: " << endl;
        cout << "Manufacturer (e.g. Dell, Gateway, etc.): " << endl;
        
        getline(cin, manufacturer);
        

        cout << "Form Factor (e.g. Desktop, Laptop): " << endl;
        
        getline(cin, formFactor);
        
        
        

        cout << "Serial Number: " << endl;
        cin >> serial;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Processor ( I3, I5, I7, AMD Ryzen 3, AMD Ryzen 5, etc.): " << endl;
        
        getline(cin, processor);

        cout << "RAM (4, 6, 8, 16, 32, or 64GB): " << endl;
        cin >> ram;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Storage Type (e.g. HDD, SSD, UFS): " << endl;
        
        cin >> storageType;

        cout << "Storage Size (128GB, 256GB, 512GB, 1TB, 2TB): " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> storageSize;
        
        try
        {
            //Have this in a try block to catch possible exceptions. 
            myPC = Computer(manufacturer, formFactor, serial, processor, ram, storageType, storageSize);
            //Displays it, only stores it after it confirms they dont want to change
            
            myPC.toString();
            
        
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';


        }

            int editchoice;
    cout << "Would you like to modify the PC? (0 for no, 1 for yes): " << endl;
    cin >> editchoice;
    if (editchoice == 1)
    {
        //This logic below is the same I used in my previous assignment. It loops through each setting and if error, it will catch and retry with the while loop. 
        //I wasn't sure about the catches so I just made it catch all exceptions.
        while (true)
        {
            try
            {
                myPC.setRAM();
                break;
                
            }
            catch(exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Please try again. " << endl;
            }

        }
        while (true)
        {
            try
            {
                myPC.setStorageType();
                break;
                
            }
            catch(exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Please try again. " << endl;
            }

        }
        while(true)
        {
            try
            {
                myPC.setStorageSize();
                break;
                
            }
            catch(exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Please try again. " << endl;
            }

        }
        cout << "Updated PC Info: " << endl;
        cout << "----------------" << endl;
        myPC.toString();
        pcList.push_back(myPC);
        
        }
    if (editchoice == 0)
    //if no edit is required, PC is added to vector and program starts again
        {
        pcList.push_back(myPC);
        
        }
        //If user doesnt want to add another, it ends and displays all 
        int addPC;
        cout << "Would you like to add another PC? (0 for no, 1 for yes): " << endl;
        while(true)
        {
            cin >> addPC; 
            if (!cin || addPC < 0 || addPC > 1)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Error. Please enter 0 for no or 1 for yes." << endl;
            }
            else if (addPC == 1)
            {
                //added this so when it goes back into program it can get manufacturer with input cleared
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 break;

            }
            else if (addPC == 0)
            {
                cout << "All PCs entered: " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < pcList.size(); i++)
                {
                    cout << "PC " << i + 1 << ":" << endl;
                    pcList[i].toString();
                    cout << "----------------" << endl;
                }
                return 0;
            }
        }
        continue;

    
        

    }

        

        
    } 

