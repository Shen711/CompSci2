//Program Name: Server Client Program
//Author: Nathan Schoenike
//Date Last Updated: 12/7/2025
//Purpose: To create a server client program
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     // for close()
#include <cstring>      // for memset
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>  
#include <limits>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <stdexcept>

using namespace std;
int main() {
    //Abbreviation input for user
    string abbrev;
    cout << "Enter a abbreviation of a state: " << endl;
    //input validation
    while(true)
    {
        cin >> abbrev;

        //Convert input to uppercase
        transform(abbrev.begin(), abbrev.end(), abbrev.begin(), ::toupper);

        if (abbrev.length() != 2 || cin.fail())
        {
            cout << "Please enter a valid 2-letter state abbreviation: ";
            continue;
        }
        else 
        {
            break;
        }
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) { perror("socket"); return 1; }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock_fd, (struct sockaddr*)&server, sizeof(server)) < 0) { perror("connect"); return 1; }

    std::string message;
    std::cout << "Enter a word: ";
    std::getline(std::cin, message);

    send(sock_fd, abbrev.c_str(), abbrev.size(), 0);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    read(sock_fd, buffer, sizeof(buffer));
    std::cout << "Server replied: " << buffer << "\n";

    close(sock_fd);
}
