
#include <string>
#include <iostream>
#include <limits.h>
#include <limits>


using namespace std;

class StereoReceiver
{
    
    string manufacturer;
    string model;
    int serialNumber;
    int wattage;
    int numberOfChannels;

    public:
        string band;
        int station;
        int volumeLevel;
        bool powerOn;
        bool bassBoost;
        int currentTrack;


    //Constructor, first had it parameterized, and created my set methods. Then realized I needed a default because I couldn't call my setters in main without an object first, so those values are place holders.
    StereoReceiver()
    : manufacturer(""), model(""), serialNumber(0), wattage(0), numberOfChannels(0), 
      band("FM"), station(1), volumeLevel(5), powerOn(false), bassBoost(false), currentTrack(0)
    {}
    
    
        
    


    //getters
    string getManufacturer()
    {
        return manufacturer;
    }
    string getModel()
    {
        return model;
    }
    int getSerialNumber()
    {
        return serialNumber;
    }
    int getWattage()
    {
        return wattage;
    }
    int getNumberOfChannels()
    {
        return numberOfChannels;
    }

    //setters 
    string setManufacturer()
    {
        //clear buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string mfr;
        cout << "Manufacturer: " << endl;
        do 
        {
            getline(cin, mfr);
            if (!cin || mfr.empty())
            {
                cout << "Error. Enter a valid manufacturer name. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

        }while (!cin || mfr.empty());
    
        manufacturer = mfr;
        return manufacturer;
    }

    
    string setModel()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string mod;
        cout << "Model: " << endl;

        do
        {
            getline(cin, mod);
            if (!cin || mod.empty())
            {
                cout << "Error. Enter a valid model name. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }while (!cin || mod.empty());
        
        model = mod;
        return model;
    }
    int setSerialNumber()
    {
        int serial;
        int serialLength;

        cout << "6 Digit Serial Number: " << endl;

        do
        {
            cin >> serial;
            serialLength = to_string(serial).length();
            if (!cin || serialLength != 6)
            {
                cout << "Error. Enter a valid integer that is 6 digits. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            
        } while (!cin || serialLength != 6);

        serialNumber = serial;
        return serialNumber;
        
    }

    int setWattage()
    {
        int watt;

        cout << "Wattage: " << endl;

        do
        {
            cin >> watt;
            if (!cin || watt <= 0)
            {
                cout << "Error. Enter a valid integer greater than 0. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (!cin || watt <= 0);

        wattage = watt;
        return wattage;
        
    }
    int setNumberOfChannels()
    {
        int channels;

        do
        {
            cout << "How many channels? (Max: 9)" << endl;
            cin >> channels;
            if (!cin || channels <= 0 || channels > 9)
            {
                cout << "Error. Please enter a positive integer or 9 or less channels" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');

            }
        }while (!cin || channels <= 0 || channels > 9);

        numberOfChannels = channels;
        return numberOfChannels;
    }

    //public variables
    bool powerOn()
    {
        int powerStatus;
        cout << "Would you like to power on the receiver? (0 for No, 1 for Yes): " << endl;
        cout <<"Enter -1 at any time to exit." << endl;

        do 
        {
            cin >> powerStatus;
            if (!cin || (powerStatus < 0 || powerStatus > 1 ))
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Error. Please enter valid input." << endl;
            }
        }while(powerStatus < 0 || powerStatus > 1);
        powerOn = static_cast<bool>(powerStatus);
        return powerOn;
    }

    int setStation()
    {
        int stationNumber;

        cout << "Please enter desired station number: (1-9)" << endl;

        do
        {
            cin >> stationNumber;

            if (!cin || stationNumber < 1 || stationNumber > 9)
            {
                cout << "Error. Please enter a valid station number between 1 and 9." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (!cin || stationNumber < 1 || stationNumber > 9);

        station = stationNumber;
        
    }

    int setVolume()
    {
        int vol;

        cout << "Set volume level (0-100): " << endl;

        while(true)
        {
            cin >> vol;

            if (!cin || vol < 0 || vol > 100)
            {
                cout << "Error. Please enter a volume between 0 and 100." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else
            {
                break;
            }
        }

        volumeLevel = vol;
        return volumeLevel;
    }

    string setBand()
    {
        string bandInput;

        cout << "Set band (1 for AM, 2 for FM): " << endl;

        while(true)
        {
            cin >> bandInput;

            if (!cin || bandInput > 2 || bandInput < 1)
            {
                cout << "Error. Please enter 1 for AM or 2 for FM." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else
            {
                break;
            }
        }

        if (bandInput == "1")
        {
            band = "AM";
        }
        else if (bandInput == "2")
        {
            band = "FM";
        }
        //default
        else
        {
            band = "AM";
        }

        return band;
    }




    void displayInfo()
    {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Serial Number: " << serialNumber << endl;
        cout << "Wattage: " << wattage << "V " << endl;
        cout << "Number of Channels: " << numberOfChannels << endl;
    }

    
};
   






int main()
{

    string mfr;
    int model;
    int serial;
    int watt;
    int channels;
    StereoReceiver userReciever;

    int menuChoice;

    cout << "Stereo Receiver Controller Menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "To enter receiver information, please press 1: " << endl;

    cin >> menuChoice;
    if (menuChoice == 1)
    {

        userReciever.setManufacturer();
        userReciever.setModel();
        userReciever.setSerialNumber();
        userReciever.setWattage();
        userReciever.setNumberOfChannels();

        cout << "Receiver Information:" << endl;
        userReciever.displayInfo();
        
        userReciever.powerOn();


        
        
    }




    return 0;
}