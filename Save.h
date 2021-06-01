#pragma once
#include "Block.h"
#include <vector>
#include <string>

class Save {

public:
	Save();

	void saveUserInfo(std::vector<std::string> data);

	void saveBlock(Block& block);

};