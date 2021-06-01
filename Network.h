#pragma once
#include <SFML/Network.hpp>
#include <string>

class Network {

public:
	Network();

	void connect(char mode);
	void send(std::string data);
	void close();

	void addClient(std::string client); // Adds new client IP on server

	void shareClientList(); // Sends list of clients from server to client
	void saveClientList(); // Saves list of clients received from server

private:

	bool keepConnection;

	sf::TcpSocket socket;
	sf::TcpListener listener;
	
	sf::IpAddress localIP; // Local IP contains the IP of whatever device is running the program
	sf::IpAddress clientIP; // Current client's IP is updated every time a new client connects
	//std::vector<sf::TcpSocket> connectedClientSockets;

	char buffer[2000];
	std::size_t received;

};

