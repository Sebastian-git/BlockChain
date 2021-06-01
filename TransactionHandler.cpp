#include "TransactionHandler.h"
#include "Block.h"

TransactionHandler::TransactionHandler() : data(), save() {}

void TransactionHandler::handle(std::vector<std::string> data, RSA& rsa) {
    this->data = data;
    save.saveUserInfo(data);
    generateBlock(rsa);
    shareTransaction();
}

void TransactionHandler::generateBlock(RSA& rsa) {
    Block block = Block();
    block.generateBlock(data, rsa);
    save.saveBlock(block);
}

void TransactionHandler::shareTransaction() {
    // Spread transaction block to everyone else in network
}