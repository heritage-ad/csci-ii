/*
Author: Heritage Adigun
Date Written: 06/04/2024
Assignment: M01 Pt 1
Short Desc: Creating a cube object and display its volume*/

#include <iostream>
#include <string>
using namespace std;


class Cube {
private: 
    int length;
    int width;
    int height;
    string color;

public:
    //Creating the constrcutor
    Cube (int len, int wid, int hgt, string clr) {
        length = len;
        width = wid;
        height = hgt;
        color = clr;
    }

    //Accesor Methods
    int getLength() {return length; }
    int getWidth() {return width; }
    int getHeight() {return height; }
    string getColor() {return color; }


    //Mutator methods
    void setLength(int len) {length = len; }
    void setWidth(int wid) {width = wid;}
    void setHeight(int hgt) {height = hgt; }
    void setColor(string clr) {color = clr; }

    //Calculate Volume
    int calculateVolume() { 
        return length * width * height; }
};

int main() {
    int len, wid, hgt;
    string clr;
    
    //Prompt user inputs

    cout << "Enter the length of the cube: ";
    cin >> len;
    cout << "Enter the width of the cube:  ";
    cin >> wid;
    cout << "Enter the height of the cube: ";
    cin >> hgt;
    cout << "Enter the color of the cube: "; 
    cin.ignore(); //Clear newline character from previous input
    getline(cin, clr);

    //Validate input if needed
    
    Cube cube (len, wid, hgt, clr);

    cout << "\nCube Information:\n";
    cout << "Length: " << cube.getLength() << endl;
    cout << "Width: " << cube.getWidth() << endl;
    cout << "Height: " << cube.getHeight() << endl;
    cout << "Color: " << cube.getColor() << endl;
    cout << "Volume: " << cube.calculateVolume() << endl; 

    //Change attributes
    
    int newLen, newWid, newHgt;
    string newClr;

    cout << "\nEnter new length: ";
    cin >> newLen;
    cout << "Enter new width: ";
    cin >> newWid;
    cout << "Enter new heigth: ";
    cin >> newHgt;
    cout << "Enter new color: ";
    cin.ignore();
    getline(cin, newClr);

    //Validate input if needed

    cube.setLength(newLen);
    cube.setWidth(newWid);
    cube.setHeight(newHgt);
    cube.setColor(newClr);


    cout << "\nUpdated Cube Information:\n";
    cout << "Length: " << cube.getLength() << endl;
    cout << "Width: " << cube.getWidth() << endl;
    cout << "Height: " << cube.getHeight() << endl;
    cout << "Color: " << cube.getColor() << endl;
    cout << "Volume: " << cube.calculateVolume() << endl;

    return 0; 

}