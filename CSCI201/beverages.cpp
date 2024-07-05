/*Program Name: Beverages
Author: Heritage Adigun
Date Last Updated: 07/03/24
Purpose: A program that creates several beverages using parameterized constructor and displays the set of beverages created.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class Beverage
class Beverage {
protected:
    string name;
    string description;
    string servingSize;
    int calories;
    double price;

public:
    Beverage(string name, string description, string servingSize, int calories, double price) :
        name(name), description(description), servingSize(servingSize), calories(calories), price(price) {}

    virtual ~Beverage() {}

    // Setters
    void setName(string name) { this->name = name; }
    void setDescription(string description) { this->description = description; }
    void setServingSize(string servingSize) { this->servingSize = servingSize; }
    void setCalories(int calories) { this->calories = calories; }
    void setPrice(double price) { this->price = price; }

    // Getters
    string getName() { return name; }
    string getDescription() { return description; }
    string getServingSize() { return servingSize; }
    int getCalories() { return calories; }
    double getPrice() { return price; }

    // Virtual toString method
    virtual string toString() {
        return "Beverage:\n" 
               "  Name: " + name + "\n" +
               "  Description: " + description + "\n" +
               "  Serving Size: " + servingSize + "\n" +
               "  Calories: " + to_string(calories) + "\n" +
               "  Price: $" + to_string(price);
    }
};

// Derived class Coffee
class Coffee : public Beverage {
private:
    string hotOrCold;
    bool caffeinated;
    string roastType;
    string strength;
    string creamer;
    string sweetener;

public:
    Coffee(string name, string description, string servingSize, int calories, double price, string hotOrCold, bool caffeinated,
           string roastType, string strength, string creamer, string sweetener) :
           Beverage(name, description, servingSize, calories, price), hotOrCold(hotOrCold), caffeinated(caffeinated),
           roastType(roastType), strength(strength), creamer(creamer), sweetener(sweetener) {}

    ~Coffee() {}

    // Overriding toString method
    string toString() override {
        return Beverage::toString() + "\n" +
               "  Hot/Cold: " + hotOrCold + "\n" +
               "  Caffeinated: " + (caffeinated ? "Yes" : "No") + "\n" +
               "  Roast Type: " + roastType + "\n" +
               "  Strength: " + strength + "\n" +
               "  Creamer: " + creamer + "\n" +
               "  Sweetener: " + sweetener;
    }
};

// Derived class Tea
class Tea : public Beverage {
private:
    string type;
    string hotOrCold;
    string creamer;
    string sweetener;
    bool lemon;

public:
    Tea(string name, string description, string servingSize, int calories, double price, string type, string hotOrCold,
        string creamer, string sweetener, bool lemon) :
        Beverage(name, description, servingSize, calories, price), type(type), hotOrCold(hotOrCold), creamer(creamer),
        sweetener(sweetener), lemon(lemon) {}

    ~Tea() {}

    // Overriding toString method
    string toString() override {
        return Beverage::toString() + "\n" +
               "  Type: " + type + "\n" +
               "  Hot/Cold: " + hotOrCold + "\n" +
               "  Creamer: " + creamer + "\n" +
               "  Sweetener: " + sweetener + "\n" +
               "  Lemon: " + (lemon ? "Yes" : "No");
    }
};

// Derived class Soda
class Soda : public Beverage {
private:
    string brand;
    string type;
    bool diet;

public:
    Soda(string name, string description, string servingSize, int calories, double price, string brand, string type, bool diet) :
         Beverage(name, description, servingSize, calories, price), brand(brand), type(type), diet(diet) {}

    ~Soda() {}

    // Overriding toString method
    string toString() override {
        return Beverage::toString() + "\n" +
               "  Brand: " + brand + "\n" +
               "  Type: " + type + "\n" +
               "  Diet: " + (diet ? "Yes" : "No");
    }
};

// Derived class EnergyDrink
class EnergyDrink : public Beverage {
private:
    string brand;
    string stimulant;
    string sweetener;

public:
    EnergyDrink(string name, string description, string servingSize, int calories, double price, string brand, string stimulant,
                string sweetener) :
                Beverage(name, description, servingSize, calories, price), brand(brand), stimulant(stimulant), sweetener(sweetener) {}

    ~EnergyDrink() {}

    // Overriding toString method
    string toString() override {
        return Beverage::toString() + "\n" +
               "  Brand: " + brand + "\n" +
               "  Stimulant: " + stimulant + "\n" +
               "  Sweetener: " + sweetener;
    }
};

int main() {
    //Creating instances of each beverage type
    Coffee coffee("Dreamer's Coffee", "A hot brewed coffee", "12oz", 120, 3.5, "Hot", true, "Espresso", "Strong", "Two Pumps", "Sugar" );
    Tea tea("Black Tea", "A refreshing black tea", "8oz", 50, 1.5, "Black", "Cold", "None", "Honey", false );
    Soda soda("Sprite", "Fizzy and refreshing", "12oz", 350, 4.0, "Coca-Cola", "Sprite", false);
    EnergyDrink energydrink("Red Bull", "It gives you wings", "16oz", 200, 3.5, "Red Bull Inc", "Caffeine", "Sugar");


    //Displaying the beverages
    cout << coffee.toString() << endl;
    cout << tea.toString() << endl;
    cout << soda.toString() << endl;
    cout << energydrink.toString() << endl;

    return 0;

}

