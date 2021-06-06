#pragma once
#include "Block.h"
#include <vector>
#include <string>

class Save {

public:

	Save();

	void saveBlock(Block& block);
	bool verifyMerkle(Block& block);

	void saveUserInfo(std::vector<std::string> data);

	bool accountExists(std::string name);

	bool verifyPassword(std::string username, std::string pswd);

private:

	SHA256 sha;

};