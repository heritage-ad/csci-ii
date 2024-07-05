/* Program Name: Nerf Gun
Author: Heritage Adigun
Date last updated: 06/26/24
Purpose: A program that displays different guns and its info, compares the gun and fire and reloads them randomly while displaying their status/information.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class nerfGun {
    private:
    string model;
    int range;
    int capacity;
    int dartCount;


    public:
    nerfGun (const string & model, int range, int capacity) {
        if (capacity <= 144) {
            this ->model = model;
            this ->range = range;
            this->capacity = capacity;
            dartCount = capacity;
        } else {
            throw invalid_argument ("Capacity cannot exceed 144.");

        }
    }

    string getModel() const {
        return model;
    }
    int getCapacity() const {
        return capacity;
    }

    int getDartCount() const {
        return dartCount;
    }

    void fire() {
        if (dartCount > 0) {
            dartCount--;
            cout << "Fired! Remaining darts: " << dartCount << endl;
        } else {
            throw underflow_error ("Out of ammunition :()");
        }
    }

    void reload (int quantity) {
        if (dartCount + quantity <= capacity) {
            dartCount += quantity;
            cout << "Reloaded! Current darts: " << dartCount << endl;
        } else {
            throw overflow_error("Exceed capacity while reloading!");
        }
    }
 
    bool operator ==(const nerfGun & other) const {
        return dartCount == other.dartCount;
    }
    
    bool operator < (const nerfGun & other) const {
        return dartCount < other.dartCount;
    }
    
    nerfGun & operator--() {
        fire();
        return *this;
    }
    nerfGun operator--(int) {
        nerfGun temp = *this;
        fire();
        return temp;
    }
    nerfGun & operator +=(int quantity) {
        reload (quantity);
        return *this;
    }

    friend ostream & operator << (ostream & os, const nerfGun & gun) {
        os << "Model: " << gun.model << endl;
        os << "Range: " << gun.range << endl;
        os << "Capacity: " << gun.capacity << endl;
        os << "Dart Count: " << gun.dartCount << endl;
        return os;
    }

};


int main() {
    vector <nerfGun> guns;
    try{
        //Create 4 diff guns
        guns.emplace_back("Gun Alpha", 60, 35);
        guns.emplace_back("Gun Bravo", 50, 100);
        guns.emplace_back("Gun Charlie", 65, 120);
        guns.emplace_back("Gun Delta", 40, 75);

        //Display each gun's info
        for (const auto&gun: guns) {
            cout << gun << endl;
        }

        //Compare the guns using the overload operator and dsiplay which one has the most ammunition
        nerfGun maxAmmoGun = guns.front();
        for (const auto & gun : guns) {
            if (gun. getDartCount() > maxAmmoGun.getDartCount()) {
                maxAmmoGun = gun;
            }
        }
        cout << "Gun with the most ammunition: " << maxAmmoGun.getModel() << endl;

        //Use the overload operator to fire and reload the guns randomly, displaying their status and/or info
        cout << "Firing and replacing randomly: " << endl;
        for (auto & gun: guns) {
            try {
                gun--;
                gun+= 10;
            } catch (const exception&e) {
                cerr << "Exception: " << e.what() << endl;
            }
        }

        //Display the final status of each gun
        cout << "Final status of each gun: " << endl;
        for (const auto & gun: guns) {
            cout << gun << endl;
        }

    } catch (const exception & e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;


}