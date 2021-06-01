#include "Block.h"
#include "RSA.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <ctime>

#pragma warning(disable : 4996) // To use localtime

Block::Block() : sha(), UID(), headerInfo(), transferInfo() {}

Block::Block(std::vector<std::string> data) : sha(), UID(), headerInfo(), transferInfo() {

    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string date(buffer);
	
	SHA256 sha;
	
	headerInfo.date = date;

	transferInfo.senderID = sha(data[0]);
	transferInfo.recipientID = sha(data[2]);
	transferInfo.quantity = data[3];
	
}

void Block::generateBlock(std::vector<std::string> data) {

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
	
    generateSignature();

}

void Block::generateSignature() {

    int p = 1, q = 1, n = 1, phi_n = 1, e = 1, d = 1;

    std::vector<std::string> keys = getKeys();

    // Check if private and public keys already exist, and if they do, update them locally

    if (keys.size() == 0) { // Since no keys exist, generate and save new public and private keys

        RSA rsa;
        rsa.generateKeys();

        std::ofstream out;
        out.open("keys.txt", std::ios_base::app);
        out << rsa.keys.privateKey << "\n" << rsa.keys.publicKeyExponent << "\n" << rsa.keys.publicKeyModulus << "\n";
        out.close();

    }
    else {
        d = std::stoi(keys[0]);
        e = std::stoi(keys[1]);
        n = std::stoi(keys[2]);
    }

    transferInfo.senderPublicKeyExponent = std::to_string(e);
    transferInfo.senderPublicKeyModulus = std::to_string(n);

    /* 
    RSA Signature Algorithms:

    Generation:     signature = (message^privateKey) % n

    Verification:     message = (signature^publicKey) % n
    */

    std::string msg = sha(transferInfo.senderPublicKeyExponent + transferInfo.recipientPublicKeyExponent);

    std::cout << "Hashed message: " << msg << "\n";

    std::vector<boost::multiprecision::int1024_t> signature; // Vector containing individually encrypted characters that make up signature

    boost::multiprecision::int1024_t cur; // Current character being encrypted

    for (int i = 0; i < msg.size(); ++i) {
        cur = boost::multiprecision::powm((int)msg[i], d, n);
        signature.push_back(cur);
    }

    for (int i = 0; i < signature.size(); i++) {
        transferInfo.signature += (signature[i]).str();
    }

    std::string ogMsg = ""; // Original message, decrypted
    for (int i = 0; i < signature.size(); i++) {
        ogMsg += (char)boost::multiprecision::powm(signature[i], e, n);
    }
    std::cout << "Original message, decrypted: " << ogMsg << "\n";

    getRecipientPublicKey();
}

int Block::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

std::vector<std::string> Block::getKeys() {

    std::vector<std::string> keys;

    // Check for previously stored private keys
    std::ifstream file("keys.txt");
    std::string line;
    while (std::getline(file, line)) {
        keys.push_back(line);
    }
    file.close();
    return keys;

}

void Block::getRecipientPublicKey() {

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

void Block::displayBlockContent() {

    std::cout << "UID: " << UID << "\n";
    std::cout << "-----------------------HEADER------------------------\n";
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