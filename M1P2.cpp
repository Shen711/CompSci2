
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
    string band;
    int station;
    int volumeLevel;
    bool powerOn;
    bool bassBoost;
    int currentTrack;

    public:
        


    //Constructor, first had it parameterized, and created my set methods. Then realized I needed a default because I couldn't call my setters in main without an object first, so those values are place holders.
    StereoReceiver()
    : manufacturer(""), model(""), serialNumber(0), wattage(0), numberOfChannels(0), 
      band("FM"), station(1), volumeLevel(5), powerOn(false), bassBoost(false), currentTrack(0)
    {}
    
    
        
    


    //getters that return values to display functions
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
    bool getBass()
    {
        return bassBoost;
    }
    bool getPowerOn()
    {
        return powerOn;
    }
    string getBand()
    {
        return band;
    }
    int getStation()
    {
        return station;
    }
    int getVolumeLevel()
    {
        return volumeLevel;
    }
    int getCurrentTrack()
    {
        return currentTrack;
    }

    //setters with input validation inside them
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

    
    bool setPowerOn()
    {
        int powerStatus;
        cout << "Would you like to power on the receiver? (0 for No, 1 for Yes): " << endl;
        

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
        return station;
        
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
        int bandInput;

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

        if (bandInput = 1)
        {
            band = "AM";
        }
        else if (bandInput = 2)
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

    bool setBassBoost()
    {
        int bassInput;
        cout << "Would you like to enable bass boost? (0 for No, 1 for Yes): " << endl;
        do
        {
            cin >> bassInput;
            if (!cin || bassInput < 0 || bassInput > 1)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Error. Please enter 0 for No or 1 for yes." << endl;
            }
        } while (!cin || bassInput < 0 || bassInput > 1);

        bassBoost = static_cast<bool>(bassInput);
        return bassBoost;
        
    }

    int setCurrenTrack()
    {
        cout << "Which track do you want to play?" << endl;
        int trackNumber;

        do
        {
            cin >> trackNumber;
            if (!cin || trackNumber < 0)
            {
                cout << "Error. Please enter a valid track number." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (!cin || trackNumber < 0);

        currentTrack = trackNumber;
         return currentTrack;
        
    }



//display for intial permanent settings
    void displayInfo()
    {
        cout << "Manufacturer: " << getManufacturer() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Serial Number: " << getSerialNumber() << endl;
        cout << "Wattage: " << getWattage() << "V " << endl;
        cout << "Number of Channels: " << getNumberOfChannels() << endl;
    }

    //display for the settings they can switch
    void displaySettings()
    {
        cout <<'\n' << endl;
        cout << "Power: " << (powerOn ? "On" : "Off") << endl;
        cout << "Station: " << station << endl;
        cout << "Volume Level: " << volumeLevel << endl;
        cout << "Band: " << band << endl;
        cout << "Bass Boost: " << (bassBoost ? "Enabled" : "Disabled") << endl;
        cout << "Current Track: " << currentTrack << endl;
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
        
        userReciever.setPowerOn();
        userReciever.setStation();
        userReciever.setVolume();
        userReciever.setBand();
        userReciever.setBassBoost();
        userReciever.setCurrenTrack();

        userReciever.displaySettings();
        
        //loop for updating settings, you need to update all settings if you are updating
        int updateChoice;

        while (true)
        {
            cout << "Do you want to update settings? (1 for yes, 0 for no):" << endl;
            cin >> updateChoice;
            if (!cin || (updateChoice != 0 && updateChoice != 1))
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Error. Please enter 0 for no or 1 for yes." << endl;
            }
            
            else if (updateChoice == 1)
            {
                cout << "Update your settings in the order they are prompted. " << endl;
                userReciever.setPowerOn();
                userReciever.setStation();
                userReciever.setVolume();
                userReciever.setBand();
                userReciever.setBassBoost();
                userReciever.setCurrenTrack();
                userReciever.displaySettings();
            }
            else  if (updateChoice == 0)
            {
                 break;
            }
            else {
                break;
            }
               
            

        }




        
        
    }




    return 0;
}