#include "Block.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <ctime>

#pragma warning(disable : 4996) // To use localtime

Block::Block() : sha(), headerInfo(), transferInfo() {}

void Block::generateBlock(std::vector<std::string> data, RSA& rsa) {

    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string date(buffer);

	headerInfo.date = date;

	transferInfo.senderID = sha(data[0]);
	transferInfo.recipientID = sha(data[2]);
	transferInfo.quantity = data[3];
	
    addSignature(rsa);
    addRecipientPublicKey();

}

void Block::addSignature(RSA& rsa) {

    transferInfo.senderPublicKeyExponent = rsa.keys.publicKeyExponent;
    transferInfo.senderPublicKeyModulus = rsa.keys.publicKeyModulus;

    int privateKey = std::stoi(rsa.keys.privateKey);
    int ePublicKey = std::stoi(rsa.keys.publicKeyExponent);
    int mPublicKey = std::stoi(rsa.keys.publicKeyModulus);

    /*
    RSA Signature Algorithms:

    Generation:     signature = (message^privateKey) % n

    Verification:     message = (signature^publicKey) % n
    */

    // RSA signature of transaction is based off the exponent public keys of both parties, and the quantity transferred in the transaction

    std::string UID = sha(transferInfo.senderPublicKeyExponent + transferInfo.recipientPublicKeyExponent + transferInfo.quantity);

    std::vector<boost::multiprecision::int1024_t> signature; // Vector containing individually encrypted characters that make up signature

    boost::multiprecision::int1024_t cur; // Current character being encrypted

    for (int i = 0; i < UID.size(); ++i) {
        cur = boost::multiprecision::powm((int)UID[i], privateKey, mPublicKey);
        signature.push_back(cur);
    }

    for (int i = 0; i < signature.size(); i++) {
        transferInfo.signature += (signature[i]).str();
    }

    headerInfo.UID = UID;
}

void Block::addRecipientPublicKey() {

    // Check for previously stored private keys
    std::ifstream file("accounts.txt");
    std::string line;
    
    while (std::getline(file, line)) {
        if (line == transferInfo.recipientID) {
            std::getline(file, line);
            break;
        }
    }

    transferInfo.recipientPublicKeyExponent = line;
    std::getline(file, line);
    transferInfo.recipientPublicKeyModulus = line;


    if (line == "") std::cout << "Recipient does not exist.\n";

    file.close();
}

void Block::addPrevID() {

}

void Block::addMerkleRoot() {
    /*
    Merkle root will be unique hash based off previous blocks
    */
}

void Block::displayBlockContent() {

    std::cout << "-----------------------HEADER------------------------\n";
    std::cout << "UID: " << headerInfo.UID << "\n";
    std::cout << "prevID: " << headerInfo.prevID << "\n";
    std::cout << "merckleRoot: " << headerInfo.merkleRoot << "\n";
    std::cout << "date: " << headerInfo.date << "\n";
    std::cout << "-------------------TRANSFER INFO---------------------\n";
    std::cout << "signature: " << transferInfo.signature << "\n";
    std::cout << "senderID: " << transferInfo.senderID << "\n";
    std::cout << "senderPublicKeyExponent: " << transferInfo.senderPublicKeyExponent << "\n";
    std::cout << "senderPublicKeyModulus: " << transferInfo.senderPublicKeyModulus << "\n";
    std::cout << "recipientID: " << transferInfo.recipientID << "\n";
    std::cout << "recipientPublicKeyExponent: " << transferInfo.recipientPublicKeyExponent << "\n";
    std::cout << "recipientPublicKeyModulus: " << transferInfo.recipientPublicKeyModulus << "\n";
    std::cout << "quantity: " << transferInfo.quantity << "\n";
    std::cout << "-----------------------------------------------------\n";

}

int Block::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}