#include "Controller.h"

Controller::Controller() : gui(this), network(), transactionHandler() {};

void Controller::startGUI() {
	gui.display();
	network.close();
}

void Controller::startConnection(char mode) {
	network.connect(mode);
}

void Controller::handleTransaction(std::vector<std::string> data) {
	transactionHandler.saveUserInfo(data);
	transactionHandler.addBlock(data);
	network.send(data[3]);
}