#include "Controller.h"

Controller::Controller() : gui(this), transactionHandler() {};

void Controller::startGUI() {
	gui.display();
}

void Controller::handleTransaction(std::vector<std::string> data) {
	transactionHandler.saveUserInfo(data);
}