#pragma once
#include "sha256.h"
#include <vector>
#include <string>

///
///     Called everytime a new transaction happens, will handle:
///		1 - Hashing password, then storing with corresponding username
///		2 - Creating new block containing elliptic curve encrypted transaction
///
class TransactionHandler {

public:
	TransactionHandler();

	void saveUserInfo(std::vector<std::string> data);
	void addBlock(std::vector<std::string> data);

private:

};

