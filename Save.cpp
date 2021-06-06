#include "Save.h"
#include "sha256.h"
#include <fstream>

Save::Save() {}

void Save::saveUserInfo(std::vector<std::string> data) {
    // Ensure no duplicate accounts
    std::ifstream file("accounts.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line == sha(data[0])) {
            file.close();
            return;
        }
    }

    // Create new account, store hashed password and username
    std::ofstream out;
    out.open("accounts.txt", std::ios_base::app);
    for (int i = 0; i < data.size(); i++) {
        if (i == 0) {
            out << sha(data[i]) << "\n";
        }
    }
    out << "------------------------------------------------------------- \n";
    out.close();

}

void Save::saveBlock(Block& block) {
    // check if merckle root is valid by calling function

    // if root is valid, save to file using same structure as print
    if (verifyMerkle(block)) {
        std::ofstream out;
        out.open("chain.txt", std::ios_base::app);

        out << "---------------------------Block 1--------------------------\n";
        out << "UID: " << block.headerInfo.UID << "\n";
        out << "prevID: " << block.headerInfo.prevID << "\n";
        out << "merckleRoot: " << block.headerInfo.merkleRoot << "\n";
        out << "date: " << block.headerInfo.date << "\n";
        out << "count: " << block.headerInfo.count << "\n";
        out << "------------------------TRANSFER INFO-------------------------\n";
        out << "signature: " << block.transferInfo.signature << "\n";
        out << "senderID: " << block.transferInfo.senderID << "\n";
        out << "senderPublicKeyExponent: " << block.transferInfo.senderPublicKeyExponent << "\n";
        out << "senderPublicKeyModulus: " << block.transferInfo.senderPublicKeyModulus << "\n";
        out << "recipientID: " << block.transferInfo.recipientID << "\n";
        out << "recipientPublicKeyExponent: " << block.transferInfo.recipientPublicKeyExponent << "\n";
        out << "recipientPublicKeyModulus: " << block.transferInfo.recipientPublicKeyModulus << "\n";
        out << "quantity: " << block.transferInfo.quantity << "\n";
        out << "--------------------------------------------------------------\n";

        out.close();
    }
}

bool Save::verifyMerkle(Block& block) {
    return true;
}

bool Save::accountExists(std::string name) {
    name = sha(name);

    // Ensure no duplicate accounts
    std::ifstream file("accounts.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line == name) {
            return true;
        }
    }
    return false;
}

bool Save::verifyPassword(std::string username, std::string pswd) {
    username = sha(username);

    // Ensure no duplicate accounts
    std::ifstream file("accounts.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line == username) {
            std::getline(file, line);
            std::getline(file, line);
            std::getline(file, line);
            if (line == pswd) {
                return true;
            }
            return false;
        }
    }
    return false;
}