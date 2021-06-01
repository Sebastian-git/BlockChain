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

	void generateKeys(); // Generates new public and private keys

	int gcd(int a, int b); // Returns greatest common divisor


private:

};

