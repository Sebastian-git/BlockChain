#include "Controller.h"
#include <iostream>

Controller::Controller() : gui(this), network(), transactionHandler(), rsa() {}

void Controller::startGUI() {
	handleKeys();

	gui.display();
	network.close();
}

bool Controller::startConnection() {

	std::cout << "S for server, C for client: ";
	char mode;
	std::cin >> mode;

	if (mode != 'S' && mode != 's' && mode != 'C' && mode != 'c') {
		std::cout << "Invalid input.\n";
		return false;
	}

	network.connect(mode);
	return true;
}

void Controller::handleTransaction(std::vector<std::string> data) {
	if (transactionHandler.handle(data, rsa))
	network.send(data[3]);
}

void Controller::handleKeys() {
	if (!rsa.keysExist()) {
		rsa.generateKeys();
	}
}