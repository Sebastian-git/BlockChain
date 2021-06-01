#pragma once
#include "sha256.h"
#include <vector>
#include <string>

class TransactionHandler {

public:
	TransactionHandler();

	void saveUserInfo(std::vector<std::string> data); // Save user data into shared file

	void shareTransaction(std::vector<std::string> data); // Send transaction data for proof of work

	void addBlock(std::vector<std::string> data);

private:

};

