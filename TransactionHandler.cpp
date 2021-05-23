#include "TransactionHandler.h"
#include <iostream>
#include <fstream>

TransactionHandler::TransactionHandler() {}

void TransactionHandler::saveUserInfo(std::vector<std::string> data) {
    SHA256 sha256;

    // Ensure no duplicate accounts
    std::ifstream ifs("accounts.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        if (line == sha256(data[0])) {
            ifs.close();
            return;
        }
    }

    // Create new account, store hashed password and username
    std::ofstream out;
    out.open("accounts.txt", std::ios_base::app);
    for (int i = 0; i < data.size(); i++) {
        if (i == 0) {
            out << sha256(data[i]) << "\n";
        }
        else if (i == 1) {
            out << sha256(data[i]) << "\n";
        }
    }
    out << "----------------------------------------------------- \n"; 
    out.close();
}

void TransactionHandler::addBlock(std::vector<std::string> data) {

}