#include "Network.h"
#include <iostream>

Network::Network() : socket(), ip(), buffer(), received(), keepConnection(true) {
    ip = sf::IpAddress::getLocalAddress();

}

void Network::connect(char mode) {
    std::cout << "Called connect\n";
    if (mode == 'S' || mode == 's') { // If current user is server
        listener.listen(2008);
        while (keepConnection) {
            
            if (listener.accept(socket) == sf::Socket::Done) {
                std::cout << "New client connected, IP:" << socket.getRemoteAddress() << "\n";
                socket.receive(buffer, sizeof(buffer), received);
                std::cout << buffer << "\n";
                memset(buffer, 0, sizeof(buffer));
            }
            socket.receive(buffer, sizeof(buffer), received);

            std::cout << "Buffer: " << buffer << "\n";
            /*
            * for buffer/data communication issue, visit
            https://stackoverflow.com/questions/53448141/sfml-detect-multiple-connections-to-server-and-count-them
            */
        }

    }
    else if (mode == 'C' || mode == 'c') { // If current user is client
        socket.connect(ip, 2008);
        std::string msg = "Client confirmation message";
        socket.send(msg.c_str(), msg.size() + 1);
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