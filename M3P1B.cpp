//Program Name: Stereo Reciever
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

    
    void setRAM()
    {
        
    }

    void setStorageSize()
    {

    }

    void setStorageType()
    {

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
    string pcchoice;

    Computer myPC("Dell", "Desktop", 123456, "I7", 16, "SSD", "64GB");

    cout << "Welcome to the PC Data Entry System." << endl;
    cout << "------------------------------" << endl;
    while (true)
    {
        
        cout << "Please enter information about your PC using our pre-set options: " << endl;
        cout << "Manufacturer (e.g. Dell, Gateway, etc.): " << endl;
        cin >> manufacturer;
        

        cout << "Form Factor (e.g. Desktop, Laptop): " << endl;
        cin >> formFactor;
        

        cout << "Serial Number: " << endl;
        cin >> serial;

        cout << "Processor ( I3, I5, I7, AMD Ryzen 3, AMD Ryzen 5, etc.): " << endl;
        cin >> processor;

        cout << "RAM (4, 6, 8, 16, 32, or 64GB): " << endl;
        cin >> ram;

        cout << "Storage Type (e.g. HDD, SSD, UFS): " << endl;
        cin >> storageType;

        cout << "Storage Size (128GB, 256GB, 512GB, 1TB, 2TB): " << endl;
        cin >> storageSize;
        
        try
        {
            myPC = Computer(manufacturer, formFactor, serial, processor, ram, storageType, storageSize);
            //Store in vecotr using pushback
            pcList.push_back(myPC);
            myPC.toString();
            break;
        
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';


        }
        

        
    } 

    cout << "Would you like to modify the PC? (Y/N): " << endl;
    
        

}
