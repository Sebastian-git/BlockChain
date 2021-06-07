#pragma once
#include "RSA.h"
#include "sha256.h"
#include <string>
#include <vector>
#include <iostream>

class Block {

public:
	Block();

	struct headerInfo {
		std::string UID;
		std::string prevID; // Locally calculated. ID of previous block pulled from file
		std::string merkleRoot; // Locally calculated. Hash of all previous blocks
		std::string date; // Externally calculated. Date of transaction
		std::string count;
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

	void generateBlock(std::vector<std::string> data, RSA& rsa);

	void displayBlockContent(); // Prints all block member variables

private:

	void addSignature(RSA& rsa); // Generates unique signature for sender using RSA
	void addRecipientPublicKey(); // Pulls recipient's public key from accounts.txt to add to block's transfer info
	void searchPrev(); // Search previous blocks to find prevID, merkleRoot, count

	int gcd(int a, int b); // Returns greatest common divisor, used in RSA

	SHA256 sha; // Used to encrypt with SHA256
	
};

