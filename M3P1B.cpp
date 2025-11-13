//Program Name: Stereo Reciever
//Author: Nathan Schoenike
//Date Last Updated: 11/10/2025
//Purpose: To input data about a specific stereo receiver with try-catch blocks
#include <string>
#include <iostream>
#include <limits.h>
#include <limits>

using namespace std;

class Computer 
{
    string manufacturer;
    string formFactor;
    int serialNumber;
    string processor;
    int ram;
    string sType;
    int sSize;

    public:
    Computer(string mfr, string form, int serial, string pro, int RAM, string type, int size)
    {
        //used same constructor validation copied from M2P2.cpp for possible exceptions
        if (manufacturer.empty())
        {
            throw invalid_argument("Manufacturer cannot be empty. ");
        }
        if (form.empty())
        {
            throw invalid_argument("Form factor cannot be empty. ");
        }
        if (serialNumber < 0)
        {
            throw invalid_argument("Serial number must be a positive integer. ");
        }
        if (processor.empty())
        {
            throw invalid_argument("Processor cannot be empty. ");
        }
        if (ram <= 0)
        {
            throw invalid_argument("RAM must be a positive integer. ");
        }
        if (sType.empty())
        {
            throw invalid_argument("Storage type cannot be empty. ");
        }
        if (sSize <= 0)
        {
            throw invalid_argument("Storage size must be a positive integer. ");
        }

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
    int getStorageSize()
    {
        return sSize;
    }
};