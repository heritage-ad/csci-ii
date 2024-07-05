/* Program name: Personal Computer  
Author: Heritage Adigun
Date last updated: 06/25/2024
Purpose: A program that tracks company's personal computer inventory.*/


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class PersonalComputer {
private:
    string manufacturer;
    string formFactor;
    string serialNumber;
    string processor;
    int ram;
    string storageType;
    int storageSize;

public:
    PersonalComputer(string manufacturer, string formFactor, string serialNumber, string processor, int ram, string storageType, int storageSize) {
        if (ram != 4 && ram != 6 && ram != 8 && ram != 16 && ram != 32 && ram != 64) {
            throw invalid_argument("Invalid RAM size. Allowed values are 4, 6, 8, 16, 32, or 64 GB.");
        }

        if (storageType != "UFS" && storageType != "SDD" && storageType != "HDD") {
            throw invalid_argument("Invalid storage type. Allowed values are UFS, SDD, or HDD.");
        }

        if (storageSize != 128 && storageSize != 256 && storageSize != 512 && storageSize != 1024 && storageSize != 2048) {
            throw invalid_argument("Invalid storage size. Allowed values are 128GB, 256GB, 512GB, 1TB, or 2TB.");
        }

        this->manufacturer = manufacturer;
        this->formFactor = formFactor;
        this->serialNumber = serialNumber;
        this->processor = processor;
        this->ram = ram;
        this->storageType = storageType;
        this->storageSize = storageSize;
    }

    // Accessor methods
    string getManufacturer() const { return manufacturer; }
    string getFormFactor() const { return formFactor; }
    string getSerialNumber() const { return serialNumber; }
    string getProcessor() const { return processor; }
    int getRam() const { return ram; }
    string getStorageType() const { return storageType; }
    int getStorageSize() const { return storageSize; }

    // Mutator methods
    void setRam(int newRam) {
        if (newRam != 4 && newRam != 6 && newRam != 8 && newRam != 16 && newRam != 32 && newRam != 64) {
            throw invalid_argument("Invalid RAM size. Allowed values are 4, 6, 8, 16, 32, or 64 GB.");
        }
        ram = newRam;
    }

    void setStorage(string newStorageType, int newStorageSize) {
        if (newStorageType != "UFS" && newStorageType != "SDD" && newStorageType != "HDD") {
            throw invalid_argument("Invalid storage type. Allowed values are UFS, SDD, or HDD.");
        }
        if (newStorageSize != 128 && newStorageSize != 256 && newStorageSize != 512 && newStorageSize != 1024 && newStorageSize != 2048) {
            throw invalid_argument("Invalid storage size. Allowed values are 128GB, 256GB, 512GB, 1TB, or 2TB.");
        }
        storageType = newStorageType;
        storageSize = newStorageSize;
    }

    // toString method
    string toString() const {
        return "Manufacturer: " + manufacturer + ", Form Factor: " + formFactor + ", Serial Number: " + serialNumber + ", Processor: " + processor + ", RAM: " + to_string(ram) + "GB, Storage: " + storageType + " " + to_string(storageSize) + "GB";
    }
};

int main() {
    vector<PersonalComputer> inventory;
    char choice;

    do {
        string manufacturer, formFactor, serialNumber, processor, storageType;
        int ram, storageSize;

        cout << "Enter manufacturer: ";
        cin >> manufacturer;
        cout << "Enter form factor (laptop/desktop): ";
        cin >> formFactor;
        cout << "Enter serial number: ";
        cin >> serialNumber;
        cout << "Enter processor: ";
        cin >> processor;
        cout << "Enter RAM size (4, 6, 8, 16, 32, 64): ";
        cin >> ram;
        cout << "Enter storage type (UFS, SDD, HDD): ";
        cin >> storageType;
        cout << "Enter storage size (128, 256, 512, 1024, 2048): ";
        cin >> storageSize;

        try {
            PersonalComputer pc(manufacturer, formFactor, serialNumber, processor, ram, storageType, storageSize);
            inventory.push_back(pc);
            cout << "Personal Computer added: " << pc.toString() << endl;
            cout << "Total number of personal computers in the inventory: " << inventory.size() << endl;
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Do you want to add another personal computer? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nComplete Inventory List:" << endl;
    for (const auto& pc : inventory) {
        cout << pc.toString() << endl;
    }

    return 0;
}
