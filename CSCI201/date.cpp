/* Program name: Date
Author: Heritage Adigun
Date last updated: 06/09/2024
Purpose: A class called Date that allows date to be created by specifying the numerical month, day, and year.
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;

//Creating a Date Class
class Date {
private:
    int month, day, year;

public:
    Date(int m, int d, int y): month(m), day(d), year(y) {
        if (m < 1 || m > 12) { // If month is not in range
            throw invalid_argument("Invalid value - There are only 12 months in the year.");
        }

        if (y < 1900 || y > 2020) { // If year is not within 1900 and 2020
            throw invalid_argument("Invalid value - The year must be between 1900 and 2020.");
        }

        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Created a vector of days in month
        if (d < 1 || d > daysInMonth[m - 1]) {
            throw invalid_argument("Invalid day for the given month.");
        }

        // Set m, d, & y
        month = m;
        day = d;
        year = y;
    }

    // Set the month
    void setMonth(int m) {
        if (m < 1 || m > 12) // Setting months to 1-12
            throw invalid_argument("Invalid value - There are only 12 months in the year.");
        month = m;
    }

    // Set the day
    void setDay(int d) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Created a vector of days in month
        if (d < 1 || d > daysInMonth[month - 1])
            throw invalid_argument("Invalid day for the given month.");
        day = d;
    }

    // Set the year
    void setYear(int y) {
        if (y < 1900 || y > 2020)
            throw invalid_argument("Invalid value - The year must be between 1900 and 2020.");
        year = y;
    }

    string toString() {
        // Create Vector month names
        vector<string> monthNames = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return monthNames[month - 1] + " " + to_string(day) + ", " + to_string(year); // returning the string representation of data
    }
};

// Main
int main() {
    int month, day, year;

    // Prompt date from user
    cout << "Enter a date (MM DD YYYY): ";
    cin >> month >> day >> year;

    // Try to set the date
    try {
        // Create an object for Date Class
        Date date(month, day, year);

        // Print the date
        cout << "You've entered: " << date.toString() << endl;

        // Prompting the user for new inputs
        int newMonth;
        cout << "Enter a new month: ";
        cin >> newMonth;
        date.setMonth(newMonth);
        cout << "Updated Date (new month): " << date.toString() << endl;

        int newDay;
        cout << "Enter a new day: ";
        cin >> newDay;
        date.setDay(newDay);
        cout << "Updated Date (new day): " << date.toString() << endl;

        int newYear;
        cout << "Enter a new year: ";
        cin >> newYear;
        date.setYear(newYear);
        cout << "Updated Date (new year): " << date.toString() << endl;
    }
    // If it's invalid
    catch (const exception &ex) {
        // Print error
        cerr << "Invalid: " << ex.what() << endl;
    }

    return 0;
}
