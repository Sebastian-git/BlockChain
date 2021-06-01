#pragma once
#include "RSA.h"
#include "GUI.h"
#include "Network.h"
#include "TransactionHandler.h"
#include <vector>
#include <string>

class Controller {

public:

	Controller();

	void startGUI();
	bool startConnection();

	void handleTransaction(std::vector<std::string> data);

private:

	void handleKeys();

	RSA rsa;
	GUI gui;
	Network network;
	TransactionHandler transactionHandler;
};

