#pragma once
#include "bigint.h"

class ECC {

public:
	ECC();

	int modECC(int randNum, int N); // Extended Euclidean Algorithm, "division" for elliptic curves

	int multECC(int gX, int gY, int privKey); // Multiplication for elliptic curves, double and add

	void addECC(int P[], int Q[], std::vector<float>& r); // Addition invented for elliptic curves, adding 2 points

	void doubleECC(int P[], std::vector<float>& r);

private:
	// Curve parameters
	int curve; // Elliptic curve given by SECP256K1
	// Coefficients of curve
	int aCurve;
	int bCurve;
	bigint N; // Number of points on domain

	// Generator point, random number in range of curve
	int gX;
	int gY;

	float xR;
	float yR;

	bigint privKey; // Randomly generated private key
	int pubKey; // Randomly generated public key
	int hashedData; // Hash of message/transaction

};

