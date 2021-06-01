#pragma once
#include "RSA.h"
#include "Save.h"
#include <vector>
#include <string>

class TransactionHandler {

public:
	TransactionHandler();

	/*
	Handle:
	1 - Save user information if account hasn't already been created (hashed username, hashed public keys, hashed password)
	2 - Create a new block with transaction data
	3 - Save block locally (adding to chain) and share to server or all connected clients (networking to be determined)
	*/
	void handle(std::vector<std::string> data, RSA& rsa); 

private:

	void shareTransaction(); // Send transaction data for proof of work

	void generateBlock(RSA& rsa); // Create new block from transaction

	std::vector<std::string> data;

	Save save;
};

