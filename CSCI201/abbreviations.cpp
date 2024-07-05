/* Program name: State  
Author: Heritage Adigun
Date last updated: 06/19/2024
Purpose: A program that reads states (abbreviations, long name), governor's name and state flower from a text file. */


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

struct StateInfo {
    std::string longName;
    std::string governor;
    std::string flower;
};

//Open file and handle file open error
void loadStates(std::map<std::string, StateInfo>& states, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return;
    }

//Create a stringstream to parse the line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string abbreviation, longName, governor, flower;


//Read data from the line seperated by commas
        std::getline(ss, abbreviation, ',');
        std::getline(ss, longName, ',');
        std::getline(ss, governor, ',');
        std::getline(ss, flower, ',');

        if (abbreviation.empty() || longName.empty() || governor.empty() || flower.empty()) {
            std::cerr << "Malformed line: " << line << std::endl;
            continue;
        }

        StateInfo info = { longName, governor, flower };
        states[abbreviation] = info;
    }

    file.close();
}
//Output state info
void printStateInfo(const std::string& abbreviation, const StateInfo& info) {
    std::cout << "State: " << info.longName << std::endl;
    std::cout << "Governor: " << info.governor << std::endl;
    std::cout << "State Flower: " << info.flower << std::endl;
}


int main() {

    //Map to store state info
    std::map<std::string, StateInfo> states;
    std::string filename = "/Users/heritageadigun/Downloads/CSCI 201/states.txt"; // File path 
    loadStates(states, filename);

    if (states.empty()) {
        std::cerr << "No state information loaded. Exiting program." << std::endl; 
        return 1;
    }

    // Debug: print loaded states
    for (const auto& state : states) {
        std::cout << "Loaded state: " << state.first << " - " << state.second.longName << std::endl;
    }

    std::string input;
    while (true) {
        std::cout << "Enter state abbreviation (or 'exit' to quit): ";
        std::cin >> input;

        if (input == "exit") {
            break;
        }

        auto it = states.find(input);
        if (it != states.end()) {
            printStateInfo(it->first, it->second);
        } else {
            std::cerr << "Invalid state abbreviation entered." << std::endl; //Invalid abbreviation
        }
    }

    return 0;
}
