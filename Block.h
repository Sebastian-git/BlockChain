#pragma once
#include "sha256.h"
#include <string>
#include <vector>
#include <iostream>

class Block {

public:
	Block();

	std::string UID;

	struct headerInfo {
		std::string prevID; // Locally calculated. ID of previous block pulled from file
		std::string merkleRoot; // Locally calculated. Hash of all information inside block
		std::string date; // Externally calculated. Date of transaction
	} headerInfo;

	struct transferInfo {
		std::string signature; // Locally calculated. Sender's unique signature calculated with RSA
		std::string senderID; // Externally calculated. Sender's unique ID, hashed value of username
		std::string senderPublicKeyExponent; // Locally calculated. Sender's public key corresponding to their username
		std::string senderPublicKeyModulus; // Locally calculated. Sender's public key corresponding to their username
		std::string recipientID; // Externally calculated. Recipient's unique ID, hashed value of username
		std::string recipientPublicKeyExponent; // Locally calculated. Recipient's public key corresponding to their username
		std::string recipientPublicKeyModulus; // Locally calculated. Recipient's public key corresponding to their username
		std::string quantity; // Externally calculated. Quantity transferred
	} transferInfo;

	void generateBlock(std::vector<std::string> data);

	void displayBlockContent(); // Prints all block member variables

private:

	std::vector<std::string> getKeys(); // Returns private and two public keys from keys.txt if they exist

	void generateSignature(); // Generates unique signature for sender using RSA

	void getRecipientPublicKey();

	int gcd(int a, int b); // Returns greatest common divisor, used in RSA

	SHA256 sha; // Used to encrypt with SHA256
	
};

