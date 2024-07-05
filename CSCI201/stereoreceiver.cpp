/*
Author: Heritage Adigun
Date Written: 06/05/2024
Assignment: M01 Pt 2
Short Desc: Create a StereoReceiver class that allows the user to change any of the attributes created and display the StereoReceiver's settings and turn off the StereoReceiver.*/


#include <iostream>
#include <string>
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
    StereoReceiver(string manufacturer, string model, string serialNo, int wattage, int noOfChannels){
        manufacturer = manufacturer;
        model = model;
        serialNo = serialNo;
        wattage = wattage;
        noOfChannels = noOfChannels;
         }

    //Acessor Methods
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

    //Mutator Methods
    void setmanufacturer(string manufacturer) {manufacturer = manufacturer; }
    void setmodel(string model)  {model = model; }
    void setserialNo(string serialNo) {serialNo = serialNo; }
    void setwattage(int wattage) {wattage = wattage; }
    void setnoOfChannels(int noOfChannels) {noOfChannels = noOfChannels; }
    void setband(string band) {if (band == "AM" || band=="FM") band = band; }
    void setfrequency(int frequency) {frequency = frequency; } 
    void setvolume(int volume) { if (volume >= 0 && volume <= 10) volume = volume; }
    void setcolor(string color) {color = color; }
    void setyear(int year) {year = year; }
    //Power Methods
    void powerOn() { power = true; }
    void powerOff() {power = false;}
}; 

int main() {
    string manufacturer, model, serialNo;
    int wattage, noOfChannels;

    //Prompt user inputs

    cout << "Enter Manufacturer: " ;
    cin >> manufacturer;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Serial Number: ";
    cin >> serialNo;
    cout << "Enter Wattage: ";
    cin >> wattage;
    cout << "Enter Number of Channels: ";
    cin >> noOfChannels;

    //Create StereoReceiver object
    StereoReceiver myReceiver(manufacturer , model, serialNo, wattage, noOfChannels);

    //Display the StereoReciver's info
    cout << "\nStereoReceiver Information:\n";
    cout << "Manufacturer: " << myReceiver.getmanufacturer() << endl;
    cout << "Model: " << myReceiver.getmodel() << endl;
    cout << "Serial Number: " << myReceiver.getserialNo() << endl;
    cout << "Wattage: " << myReceiver.getwattage() << endl;
    cout << "Number of Channels: " << myReceiver.getnoOfChannels() << endl;

    //Turn on the StereoReceiver
    myReceiver.powerOn();

    //Allow the user to change/set the band, freq., and volume
    string band;
    int frequency , volume; 

    cout << "Set Band (AM/FM): ";
    cin >> band;
    myReceiver.setband(band);

    cout << "Set Frequency: ";
    cin >> frequency;
    myReceiver.setfrequency(frequency);

    cout << "Set Volume (0-10): ";
    cin >> volume; 
    myReceiver.setvolume(volume);

    //Allow user to changge color and year (Attribute of own choosing)
    string color;
    int year;  

    cout << "Set Color: ";
    cin >> color; 
    myReceiver.setcolor(color);

    cout << "Set Year: ";
    cin >> year;
    myReceiver.setyear(year);

//Display the StereoReceiver's settings
cout << "\nStereoReceiver Settings:\n";
cout << "Power: " << (myReceiver.isPoweredOn()? "On" : "Off") << endl;
cout << "Band: " << myReceiver.getband() << endl;
cout << "Station: " << myReceiver.getfrequency() << endl;
cout << "Volume: " << myReceiver.getvolume() << endl; 

//Turn off the StereoReceiver
myReceiver.powerOff();

return 0; 

}


