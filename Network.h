#pragma once
#include <SFML/Network.hpp>

class Network {

public:
	Network();

	void connect(char mode);
	
	void send(std::string data);

	void close();

private:

	bool keepConnection;

	sf::TcpSocket socket;
	sf::TcpListener listener;
	sf::IpAddress ip;

	char buffer[2000];
	std::size_t received;
};

