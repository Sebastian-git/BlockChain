#include "Controller.h"
#include <iostream>

Controller::Controller() : gui(this), network(), transactionHandler() {}

void Controller::startGUI() {
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
	transactionHandler.handle(data);
	network.send(data[3]);
}