#include "Network.h"
#include <iostream>
#include <fstream>

// Update localIP to have .publicIP() to port forward and accept new connections
Network::Network() : socket(), localIP(sf::IpAddress::getLocalAddress()), clientIP(), buffer(), received(), keepConnection(true) {}

void Network::connect(char mode) {

    if (mode == 'S' || mode == 's') { // If current user is server

        listener.setBlocking(false);
        listener.listen(2008);

        while (keepConnection) {
            
            if (listener.accept(socket) == sf::Socket::Done) {
                socket.setBlocking(false);
                
                clientIP = (socket.getRemoteAddress()).getPublicAddress();
                //connectedClientSockets.push_back(socket);
                addClient(clientIP.toString());
                shareClientList();

                std::cout << "New client connected, IP: " << clientIP << "\n";
            }

        }
    }
    else if (mode == 'C' || mode == 'c') { // If current user is client
        socket.connect(localIP, 2008);

        saveClientList();

        std::cout << "Connected to server on " << socket.getRemoteAddress() << "\n";
    }
}

void Network::send(std::string data) {
    std::cout << "Sending " << data << "\n";
    socket.send(data.c_str(), data.length() + 1);
}

void Network::close() {
    listener.close();
    keepConnection = false;
}

void Network::addClient(std::string client) {

    // Ensure no duplicate accounts
    std::ifstream ifs("clients.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        if (line == client) {
            ifs.close();
            return;
        }
    }

    // Create new account, store hashed password and username
    std::ofstream out;
    out.open("clients.txt", std::ios_base::app);
    out << client << "\n";   
    out.close();
}

void Network::shareClientList() {

    // List of clients saved in server's list of clients
    std::string clientIPList;

    // Fill clientIPList with IP's from file
    std::ifstream ifs("clients.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        clientIPList += line;
    }

    // Send IP's to connected client
    socket.send(clientIPList.c_str(), clientIPList.length() + 1);

}

void Network::saveClientList() {

    socket.receive(buffer, sizeof(buffer), received);

    std::cout << "Current client list:\n";

    std::ifstream ifs("clients.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << "\n";
    }

    std::cout << "Updated client list:\n" << buffer << "\n";

    std::ofstream out;
    out.open("clients.txt", std::ios_base::app);
    out << buffer << "\n";
    out.close();

}