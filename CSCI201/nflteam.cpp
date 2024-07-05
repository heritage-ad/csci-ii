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
        return name + " (#" + std::to_string(playerID) + ") - WideReceiver";
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

int main() {
    std::vector<Player*> team; // Vector to hold players on the team

    // Adding players to the team
    team.push_back(new Quarterback("Tom Brady", 12));
    team.push_back(new WideReceiver("Julio Jones", 11));
    team.push_back(new TightEnd("Travis Kelce", 87));
    team.push_back(new RunningBack("Derrick Henry", 22));
    team.push_back(new OffensiveLineman("Joe Thomas", 73));

    team.push_back(new DefensiveLineman("Aaron Donald", 99));
    team.push_back(new Linebacker("Luke Kuechly", 59));
    team.push_back(new DefensiveBack("Jalen Ramsey", 20));

    team.push_back(new Kicker("Justin Tucker", 9));
    team.push_back(new Holder("Morgan Cox", 46));
    team.push_back(new Punter("Johnny Hekker", 6));
    team.push_back(new Returner("Cordarrelle Patterson", 84));

    // Displaying the list of players on the team
    std::cout << "List of Players on the Team:" << std::endl;
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



