/*Program Name: Client Server Program
Author: Heritage Adigun
Date Last Updated: 07/12/24
Purpose: Server Program */


#include <iostream>
#include <unordered_map>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

const int PORT = 12345;
const int MAX_BUFFER_SIZE = 256;

std::unordered_map<std::string, std::string> initializeStateMap() {
    std::unordered_map<std::string, std::string> states;
    states["AL"] = "Alabama";
    states["AK"] = "Alaska";
    states["AZ"] = "Arizona";
    states["AR"] = "Arkansas";
    states["CA"] = "California";
    states["CO"] = "Colorado";
    states["CT"] = "Connecticut";
    states["DE"] = "Delaware";
    states["FL"] = "Florida";
    states["GA"] = "Georgia";
    states["HI"] = "Hawaii";
    states["ID"] = "Idaho";
    states["IL"] = "Illinois";
    states["IN"] = "Indiana";
    states["IA"] = "Iowa";
    states["KS"] = "Kansas";
    states["KY"] = "Kentucky";
    states["LA"] = "Louisiana";
    states["ME"] = "Maine";
    states["MD"] = "Maryland";
    states["MA"] = "Massachusetts";
    states["MI"] = "Michigan";
    states["MN"] = "Minnesota";
    states["MS"] = "Mississippi";
    states["MO"] = "Missouri";
    states["MT"] = "Montana";
    states["NE"] = "Nebraska";
    states["NV"] = "Nevada";
    states["NH"] = "New Hampshire";
    states["NJ"] = "New Jersey";
    states["NM"] = "New Mexico";
    states["NY"] = "New York";
    states["NC"] = "North Carolina";
    states["ND"] = "North Dakota";
    states["OH"] = "Ohio";
    states["OK"] = "Oklahoma";
    states["OR"] = "Oregon";
    states["PA"] = "Pennsylvania";
    states["RI"] = "Rhode Island";
    states["SC"] = "South Carolina";
    states["SD"] = "South Dakota";
    states["TN"] = "Tennessee";
    states["TX"] = "Texas";
    states["UT"] = "Utah";
    states["VT"] = "Vermont";
    states["VA"] = "Virginia";
    states["WA"] = "Washington";
    states["WV"] = "West Virginia";
    states["WI"] = "Wisconsin";
    states["WY"] = "Wyoming";
    return states;
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Initialize server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to the address and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Error listening on socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::unordered_map<std::string, std::string> stateMap = initializeStateMap();

    while (true) {
        std::cout << "Waiting for a client to connect..." << std::endl;
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket < 0) {
            std::cerr << "Error accepting client connection" << std::endl;
            continue;
        }

        std::cout << "Client connected" << std::endl;

        while (true) {
            // Clear buffer and read client message
            memset(buffer, 0, sizeof(buffer));
            int bytesRead = read(clientSocket, buffer, sizeof(buffer));
            if (bytesRead <= 0) {
                std::cerr << "Error reading from client or client disconnected" << std::endl;
                break;
            }

            std::string stateAbbreviation(buffer);

            // Get the state name from the map
            std::string stateName;
            if (stateMap.find(stateAbbreviation) != stateMap.end()) {
                stateName = stateMap[stateAbbreviation];
            } else {
                stateName = "Invalid state abbreviation";
            }

            // Send the state name back to the client
            if (write(clientSocket, stateName.c_str(), stateName.length()) < 0) {
                std::cerr << "Error writing to client" << std::endl;
                break;
            }
        }

        close(clientSocket);
    }

    close(serverSocket);

    return 0;
}
