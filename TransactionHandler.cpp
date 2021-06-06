#include "TransactionHandler.h"
#include "Block.h"

TransactionHandler::TransactionHandler() : data(), save(), block() {}

bool TransactionHandler::handle(std::vector<std::string> data, RSA& rsa) {

    if (isValidTransaction(data)) {
        this->data = data;
        save.saveUserInfo(data);
        if (verifyPassword(data[0], data[1])) {
            std::cout << "Invalid password.\n";
        }
        if (accountExists(data[2])) {
            generateBlock(rsa);
        }
        else {
            std::cout << "Recipient's account does not exist.\n";
        }
        return true;
    }

    return false;
}

void TransactionHandler::generateBlock(RSA& rsa) {
    block.generateBlock(data, rsa);
    save.saveBlock(block);
}

void TransactionHandler::shareTransaction() {
    // Spread transaction block to everyone else in network
}

bool TransactionHandler::accountExists(std::string recipient) {
    return save.accountExists(recipient);
}

bool TransactionHandler::verifyPassword(std::string username, std::string pswd) {
    return save.verifyPassword(username, pswd);
}

bool TransactionHandler::isValidTransaction(std::vector<std::string> data) {
    int total = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].size() <= 0) {
            return false;
        }
    }
    return true;
}