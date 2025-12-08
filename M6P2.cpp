//Program Name: Abstract Base NFL Player Class
//Author: Nathan Schoenike
//Date Last Updated: 12/7/2025
//Purpose: To create a server client program
#include <iostream>
#include <fstream> 
#include <vector> 
#include <limits>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>
//Found these from internet for sockets, it reminds me of using SQLite 
//but even so its hard for me to grasp fully so I copied over most of the socket programming so I can focus on the actual communication
#include <winsock2.h>
#include <ws2tcpip.h>


using namespace std;

#pragma comment(lib, "ws2_32.lib")

bool is_full_word(const std::string& s) {
    static const std::vector<std::string> dictionary = {
        "hello", "world", "cat", "dog", "apple", "banana"
    };

    return std::find(dictionary.begin(), dictionary.end(), s) != dictionary.end();
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, SOMAXCONN);

    std::cout << "Server running on port 8080...\n";

    SOCKET client_fd = accept(server_fd, nullptr, nullptr);

    char buffer[1024] = {};
    recv(client_fd, buffer, sizeof(buffer), 0);

    std::string word = buffer;
    std::cout << "Client sent: " << word << "\n";

    // Trim whitespace
    word.erase(word.find_last_not_of(" \r\n\t") + 1);

    std::string reply;
    if (is_full_word(word))
        reply = "VALID";
    else
        reply = "INVALID";

    send(client_fd, reply.c_str(), reply.size(), 0);

    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
}