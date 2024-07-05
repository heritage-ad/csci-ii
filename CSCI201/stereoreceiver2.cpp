/* Program name: StereoReceiver Modified
Author: Heritage Adigun
Date last updated: 06/09/2024
Purpose: Create a StereoReceiver class that allows the user to change any of the attributes created and display the StereoReceiver's settings and turn off the StereoReceiver and utilize try-catch blocks to validate the user input.*/





#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class StereoReceiver {
private:
    string manufacturer;
    string model;
    string serialNo;
    int wattage;
    int noOfChannels;
    string band;
    int frequency;
    int volume;
    bool power;
    string color; //Attribute of own choosing
    int year; //Attribute of own choosing

public:
    StereoReceiver(string manufacturer, string model, string serialNo, int wattage, int noOfChannels, int volume, int frequency, string band) {
        if (manufacturer.empty() || model.empty() || serialNo.empty()) {
            throw invalid_argument("Manufacturer, Model, or Serial Number not provided.");
        }
        if (wattage <= 0 || noOfChannels <= 0 || volume < 0 || volume > 10 || frequency < 88 || frequency > 108) {
            throw invalid_argument("Inappropriate values for Wattage, Number of Channels, Volume, or Frequency.");
        }
        if (band != "AM" && band != "FM") {
            throw invalid_argument("Invalid Band.");
        }

        this->manufacturer = manufacturer;
        this->model = model;
        this->serialNo = serialNo;
        this->wattage = wattage;
        this->noOfChannels = noOfChannels;
        this->volume = volume;
        this->frequency = frequency;
        this->band = band;
        this->power = false;
    }

    // Accessor methods
    string getmanufacturer() {return manufacturer; }
    string getmodel() {return model; }
    string getserialNo() {return serialNo; }
    int getwattage() {return wattage; }
    int getnoOfChannels() {return noOfChannels; }
    string getband() {return band; }
    int getfrequency() {return frequency; }
    int getvolume() {return volume; }
    bool isPoweredOn() {return power; }
    string getcolor() {return color; }
    int getyear() {return year; }


    // Mutator methods with exception handling
    void setWattage(int wattage) {
        if (wattage <= 0) {
            throw invalid_argument("Invalid Wattage.");
        }
        this->wattage = wattage;
    }

    void setNoOfChannels(int noOfChannels) {
        if (noOfChannels <= 0) {
            throw invalid_argument("Invalid Number of Channels.");
        }
        this->noOfChannels = noOfChannels;
    }

    void setVolume(int volume) {
        if (volume < 0 || volume > 10) {
            throw invalid_argument("Invalid Volume - Volume cannot exceed 10.");
        }
        this->volume = volume;
    }

    void setFrequency(int frequency) {
        if (frequency < 88 || frequency > 108) {
            throw invalid_argument("Invalid Frequency.");
        }
        this->frequency = frequency;
    }

    void setBand(string band) {
        if (band != "AM" && band != "FM") {
            throw invalid_argument("Invalid Band.");
        }
        this->band = band;
    }

    // Power methods
    void powerOn() {
        power = true;
    }

    void powerOff() {
        power = false;
    }

    // Display method
    void displayInfo() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Serial Number: " << serialNo << endl;
        cout << "Wattage: " << wattage << endl;
        cout << "Number of Channels: " << noOfChannels << endl;
        cout << "Volume: " << volume << endl;
        cout << "Frequency: " << frequency << endl;
        cout << "Band: " << band << endl;
        cout << "Power: " << (power ? "On" : "Off") << endl;
    }
};

int main() {
    string manufacturer, model, serialNo, band;
    int wattage, noOfChannels, volume, frequency;

    try {
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Serial Number: ";
        cin >> serialNo;
        cout << "Enter Wattage: ";
        cin >> wattage;
        cout << "Enter Number of Channels: ";
        cin >> noOfChannels;
        cout << "Enter Volume (0-10): ";
        cin >> volume;
        cout << "Enter Frequency (88-108): ";
        cin >> frequency;
        cout << "Enter Band (AM/FM): ";
        cin >> band;

        // Create StereoReceiver object
        StereoReceiver myReceiver(manufacturer, model, serialNo, wattage, noOfChannels, volume, frequency, band);

        // Display initial info
        cout << "\nInitial StereoReceiver Information:\n";
        myReceiver.displayInfo();

        // Change values
        int newVolume, newFrequency;
        string newBand;
        cout << "\nEnter New Band (AM/FM): ";
        cin >> newBand;
        myReceiver.setBand(newBand);
        cout << "Enter New Frequency (88-108): ";
        cin >> newFrequency;
        myReceiver.setFrequency(newFrequency);
        cout << "Enter New Volume (0-10): ";
        cin >> newVolume;
        myReceiver.setVolume(newVolume);

        // Display updated info
        cout << "\nUpdated StereoReceiver Information:\n";
        myReceiver.displayInfo();
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 0;
}
