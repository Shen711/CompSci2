#include <stdio.h>
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
    string wattage;
    int numberOfChannels;

    public:
        string band;
        int station;
        int volumeLevel;
        bool powerOn;
        bool bassBoost;
        int currentTrack;


    //Constructor
    StereoReceiver(string mfr, string mod, int serial, string watt, int channels)
    {
        manufacturer = mfr;
        model = mod;
        serialNumber = serial;
        wattage = watt;
        numberOfChannels = channels;
        powerOn = false;
        volumeLevel = 0;
        bassBoost = false;
        currentTrack = 0;
    }


}