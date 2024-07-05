/*Program Name: Client Server Program
Author: Heritage Adigun
Date Last Updated: 07/12/24
Purpose: Client Program
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

const int PORT = 12345;
const int MAX_BUFFER_SIZE = 256;

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Initialize server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //Server's IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error connecting to the server" << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "Enter a state abbreviation (or 'STOP' to quit): ";
        std::string userInput;
        std::cin >> userInput;

        // Check for 'STOP' to exit the loop
        if (userInput == "STOP") {
            break;
        }

        // Send the user input (state abbreviation) to the server
        if (write(clientSocket, userInput.c_str(), userInput.length()) < 0) {
            std::cerr << "Error writing to server" << std::endl;
            break;
        }

        // Read the server's response (state name)
        memset(buffer, 0, sizeof(buffer));
        if (read(clientSocket, buffer, sizeof(buffer)) < 0) {
            std::cerr << "Error reading from server" << std::endl;
            break;
        }

        std::cout << "State name: " << buffer << std::endl;
    }

    // Close the client socket
    close(clientSocket);

    return 0;
}
