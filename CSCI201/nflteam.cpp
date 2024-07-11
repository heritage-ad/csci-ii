/*Program Name: NFL Football Team 
Author: Heritage Adigun
Date Last Updated: 07/11/24
Purpose: A program that displays players on a NFL Team. 
*/

#include <iostream>
#include <vector>
#include <string>

// Base class for players
class Player {
protected:
    std::string name;
    int playerID;

public:
    Player(std::string name, int playerID) : name(name), playerID(playerID) {}

    // Abstract methods
    virtual std::string getPlayerPosition() const = 0;
    virtual void play() const = 0;
    virtual std::string toString() const = 0;

    std::string getName() const {
        return name;
    }

    int getPlayerID() const {
        return playerID;
    }
};

// Offensive player subclasses
class Quarterback : public Player {
public:
    Quarterback(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Quarterback";
    }

    void play() const override {
        std::cout << "Throws the ball" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Quarterback";
    }
};

class WideReceiver : public Player {
public:
    WideReceiver(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Wide Receiver";
    }

    void play() const override {
        std::cout << "Catches passes" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Wide Receiver";
    }
};

class TightEnd : public Player {
public:
    TightEnd(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Tight End";
    }

    void play() const override {
        std::cout << "Blocks and catches passes" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Tight End";
    }
};

class RunningBack : public Player {
public:
    RunningBack(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Running Back";
    }

    void play() const override {
        std::cout << "Runs with the ball" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Running Back";
    }
};

class OffensiveLineman : public Player {
public:
    OffensiveLineman(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Offensive Lineman";
    }

    void play() const override {
        std::cout << "Blocks for the offense" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Offensive Lineman";
    }
};

// Defensive player subclasses
class DefensiveLineman : public Player {
public:
    DefensiveLineman(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Defensive Lineman";
    }

    void play() const override {
        std::cout << "Rushes the quarterback and tackles runners" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Defensive Lineman";
    }
};

class Linebacker : public Player {
public:
    Linebacker(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Linebacker";
    }

    void play() const override {
        std::cout << "Tackles runners and covers receivers" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Linebacker";
    }
};

class DefensiveBack : public Player {
public:
    DefensiveBack(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Defensive Back";
    }

    void play() const override {
        std::cout << "Covers receivers and intercepts passes" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Defensive Back";
    }
};

// Special Teams player subclasses
class Kicker : public Player {
public:
    Kicker(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Kicker";
    }

    void play() const override {
        std::cout << "Kicks the ball" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Kicker";
    }
};

class Holder : public Player {
public:
    Holder(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Holder";
    }

    void play() const override {
        std::cout << "Holds the ball for kicks" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Holder";
    }
};

class Punter : public Player {
public:
    Punter(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Punter";
    }

    void play() const override {
        std::cout << "Punts the ball" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Punter";
    }
};

class Returner : public Player {
public:
    Returner(std::string name, int playerID) : Player(name, playerID) {}

    std::string getPlayerPosition() const override {
        return "Returner";
    }

    void play() const override {
        std::cout << "Returns kicks and punts" << std::endl;
    }

    std::string toString() const override {
        return name + " (#" + std::to_string(playerID) + ") - Returner";
    }
};

void addPlayer(std::vector<Player*>& team) {
    std::string name;
    int playerID;
    int choice;

    std::cout << "Enter player name: ";
    std::cin.ignore();  // Ignore any leftover newline characters in the input buffer
    std::getline(std::cin, name);  // Get the full name including spaces
    std::cout << "Enter player ID: ";
    std::cin >> playerID;

    std::cout << "Select player position:\n";
    std::cout << "1. Quarterback\n";
    std::cout << "2. Wide Receiver\n";
    std::cout << "3. Tight End\n";
    std::cout << "4. Running Back\n";
    std::cout << "5. Offensive Lineman\n";
    std::cout << "6. Defensive Lineman\n";
    std::cout << "7. Linebacker\n";
    std::cout << "8. Defensive Back\n";
    std::cout << "9. Kicker\n";
    std::cout << "10. Holder\n";
    std::cout << "11. Punter\n";
    std::cout << "12. Returner\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    Player* player = nullptr;

    switch (choice) {
        case 1: player = new Quarterback(name, playerID); break;
        case 2: player = new WideReceiver(name, playerID); break;
        case 3: player = new TightEnd(name, playerID); break;
        case 4: player = new RunningBack(name, playerID); break;
        case 5: player = new OffensiveLineman(name, playerID); break;
        case 6: player = new DefensiveLineman(name, playerID); break;
        case 7: player = new Linebacker(name, playerID); break;
        case 8: player = new DefensiveBack(name, playerID); break;
        case 9: player = new Kicker(name, playerID); break;
        case 10: player = new Holder(name, playerID); break;
        case 11: player = new Punter(name, playerID); break;
        case 12: player = new Returner(name, playerID); break;
        default: std::cout << "Invalid choice!" << std::endl; return;
    }

    team.push_back(player);
}

int main() {
    std::vector<Player*> team;  // Vector to hold players on the team
    int numPlayers;

    std::cout << "How many players do you want to add to the team? ";
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i) {
        addPlayer(team);
    }

    // Displaying the list of players on the team
    std::cout << "\nList of Players on the Team:\n";
    for (const Player* player : team) {
        std::cout << player->toString() << std::endl;
        player->play();
        std::cout << std::endl;
    }

    // Displaying the number of players on the team
    std::cout << "Number of Players on the Team: " << team.size() << std::endl;

    // Clean up memory
    for (Player* player : team) {
        delete player;
    }

    return 0;
}
