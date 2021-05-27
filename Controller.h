#pragma once
#include "GUI.h"
#include "Network.h"
#include "TransactionHandler.h"
#include <vector>
#include <string>

class Controller {

public:
	Controller();

	void startGUI();
	void startConnection(char mode);

	void handleTransaction(std::vector<std::string> data);

private:
	GUI gui;
	Network network;
	TransactionHandler transactionHandler;

};

