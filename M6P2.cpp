//Program Name: Server Client Program
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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     // for close()
#include <cstring>      // for memset
#include <map>



using namespace std;

int main() {

    //Map for states and corresponding abbreviations
    std::map<std::string, std::string> states = {
        {"AL","Alabama"},{"AK","Alaska"},{"AZ","Arizona"},{"AR","Arkansas"},
        {"CA","California"},{"CO","Colorado"},{"CT","Connecticut"},{"DE","Delaware"},
        {"FL","Florida"},{"GA","Georgia"},{"HI","Hawaii"},{"ID","Idaho"},
        {"IL","Illinois"},{"IN","Indiana"},{"IA","Iowa"},{"KS","Kansas"},
        {"KY","Kentucky"},{"LA","Louisiana"},{"ME","Maine"},{"MD","Maryland"},
        {"MA","Massachusetts"},{"MI","Michigan"},{"MN","Minnesota"},{"MS","Mississippi"},
        {"MO","Missouri"},{"MT","Montana"},{"NE","Nebraska"},{"NV","Nevada"},
        {"NH","New Hampshire"},{"NJ","New Jersey"},{"NM","New Mexico"},{"NY","New York"},
        {"NC","North Carolina"},{"ND","North Dakota"},{"OH","Ohio"},{"OK","Oklahoma"},
        {"OR","Oregon"},{"PA","Pennsylvania"},{"RI","Rhode Island"},{"SC","South Carolina"},
        {"SD","South Dakota"},{"TN","Tennessee"},{"TX","Texas"},{"UT","Utah"},
        {"VT","Vermont"},{"VA","Virginia"},{"WA","Washington"},{"WV","West Virginia"},
        {"WI","Wisconsin"},{"WY","Wyoming"}
    };
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); return 1; }
    if (listen(server_fd, 1) < 0) { perror("listen"); return 1; }

    std::cout << "Server running on port 8080...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) { perror("accept"); return 1; }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    read(client_fd, buffer, sizeof(buffer));
    std::string word(buffer);
    word.erase(word.find_last_not_of(" \r\n\t") + 1);



    string message;
    if (states.find(word) != states.end()) {
        message = states[word];
    } else {
        message = "Invalid abbreviation";
    }
    

    send(client_fd, message.c_str(), message.size(), 0);
    close(client_fd);
    close(server_fd);
}
