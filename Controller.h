#pragma once
#include "GUI.h"
#include "TransactionHandler.h"
#include <vector>
#include <string>

class Controller {

public:
	Controller();

	void startGUI();

	void handleTransaction(std::vector<std::string> data);

private:
	GUI gui;
	TransactionHandler transactionHandler;

};

