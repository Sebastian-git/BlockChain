#include "TransactionHandler.h"
#include "Block.h"

TransactionHandler::TransactionHandler() : data(), save() {}

void TransactionHandler::handle(std::vector<std::string> data) {
    this->data = data;
    save.saveUserInfo(data);
    generateBlock();
    shareTransaction();
}

void TransactionHandler::generateBlock() {
    Block block = Block();
    block.generateBlock(data);
    block.displayBlockContent();
    save.saveBlock(block);
}

void TransactionHandler::shareTransaction() {
    // Spread transaction block to everyone else in network
}