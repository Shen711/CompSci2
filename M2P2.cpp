//Program Name: Stereo Reciever
//Author: Nathan Schoenike
//Date Last Updated: 11/3/2025
//Purpose: To input data about a specific stereo receiver
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
    //these two are the ones I chose.
    bool bassBoost;
    int currentTrack;

    public:
        


    //Constructor, first had it parameterized, and created my set methods. Then realized I needed a default because I couldn't call my setters in main without an object first, so those values are place holders.
    StereoReceiver(string mfr, string mod, int serial, int watt, int channels, string bandInput, int stationNumber, int volume, bool power, bool bassInput, int trackNumber)
    : 
    {
        if (!cin || mfr.empty())
        {
            throw invalid_argument("Manufacturer must be provided. ");
        }
        if (!cin || mod.empty())
        {
            throw invalid_argument("Model must be provided. "); 
            
    }
    
    
        
    


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
    void setManufacturer()
    {
        //clear buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string mfr;
        cout << "Manufacturer: " << endl;
    
            getline(cin, mfr);
            if (!cin || mfr.empty())
            {
                throw invalid_argument("Manufacturer must be provided. ");
            }

        
    
        manufacturer = mfr;
    
    }

    
    void setModel()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string mod;
        cout << "Model: " << endl;

        
            getline(cin, mod);
            if (!cin || mod.empty())
            {
                throw invalid_argument("Model must be provided. ");
        
        
        model = mod;
        
    }
}
    void setSerialNumber()
    {
        int serial;
        int serialLength;

        cout << "6 Digit Serial Number: " << endl;

        
            cin >> serial;
            serialLength = to_string(serial).length();
            if (!cin || serialLength != 6)
            {
                throw invalid_argument("Serial must be a 6 digit long integer.");
            }
            
        

        serialNumber = serial;
        
        
    }

    void setWattage()
    {
        int watt;

        cout << "Wattage (Max 1000): " << endl;

       
            cin >> watt;
            if (!cin || watt <= 0 || watt > 1000)
            {
                throw invalid_argument("Wattage must be an integer under 1000V. ");
            }
        

        wattage = watt;
        
        
    }
    void setNumberOfChannels()
    {
        int channels;

        
            cout << "How many channels? (Max: 9)" << endl;
            cin >> channels;
            if (!cin || channels <= 0 || channels > 9)
            {
                throw invalid_argument("Number of channels must be an integer no greater than 9. ");

            }
        

        numberOfChannels = channels;
        
    }

    
    void setPowerOn()
    {
        int powerStatus;
        cout << "Would you like to power on the receiver? (0 for No, 1 for Yes): " << endl;
        

        
            cin >> powerStatus;
            if (!cin || (powerStatus < 0 || powerStatus > 1 ))
            {
                throw invalid_argument("Please press 1 or 0 to turn reciever on or off. ");
            }
        
        powerOn = static_cast<bool>(powerStatus);
        
    }

    void setStation()
    {
        int stationNumber;

        cout << "Please enter desired station number: (1-9)" << endl;

        
            cin >> stationNumber;

            if (!cin || stationNumber < 1 || stationNumber > 9)
            {
                throw invalid_argument("Station number must be an integer between 1 and 9. ");
            }
        

        station = stationNumber;
        
        
    }

    void setVolume()
    {
        int vol;

        cout << "Set volume level (0-100): " << endl;

        
            cin >> vol;

            if (!cin || vol < 0 || vol > 100)
            {
                throw invalid_argument("Volume level must be an integer between 0 and 100. ");
            }
            
        

        volumeLevel = vol;
        
    }
    //returns a string AM or FM
    void setBand()
    {
        int bandInput;

        cout << "Set band (1 for AM, 2 for FM): " << endl;

        
            cin >> bandInput;

            if (!cin || bandInput > 2 || bandInput < 1)
            {
                throw invalid_argument("Band Error. Please enter a integer between 1 and 2.");
                
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


        
    }


    //bass boost which returns a boolean value, this is different from my others
    void setBassBoost()
    {
        int bassInput;
        cout << "Would you like to enable bass boost? (0 for No, 1 for Yes): " << endl;
        
            cin >> bassInput;
            if (!cin || bassInput < 0 || bassInput > 1)
            {
                throw invalid_argument("Bass boost option may be only 1 or 0.");
                
            }
        

        bassBoost = static_cast<bool>(bassInput);
        
        
    }

    void setCurrenTrack()
    {
        cout << "Which track do you want to play?" << endl;
        int trackNumber;

        
            cin >> trackNumber;
            if (!cin || trackNumber < 0)
            {
                throw invalid_argument("Track number must be an integer greater than 0.");
                
            }
        

        currentTrack = trackNumber;
         
        
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
        cout << "Power: " << (getPowerOn() ? "On" : "Off") << endl;
        cout << "Station: " << getStation() << endl;
        cout << "Volume Level: " << getVolumeLevel() << endl;
        cout << "Band: " << getBand() << endl;
        cout << "Bass Boost: " << (getBass() ? "Enabled" : "Disabled") << endl;
        cout << "Current Track: " << getCurrentTrack() << endl;
    }

    
};
   






int main()
{

    

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