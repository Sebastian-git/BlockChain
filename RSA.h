#pragma once
#include <iostream>
#include <string>

class RSA {

public:
	RSA();

	struct keys {
		std::string publicKeyExponent;
		std::string publicKeyModulus;
		std::string privateKey;
	} keys;

	bool keysExist();

	void generateKeys(); // Generates new public and private keys

	void displayKeys();

private:

	int gcd(int a, int b); // Returns greatest common divisor

};

