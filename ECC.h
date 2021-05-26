#pragma once
#include <vector>
#include <string>

#include "bigint.h"

class ECC {

public:
	ECC();

	int modECC(bigint randNum, bigint N); // Extended Euclidean Algorithm, "division" for elliptic curves

	int multECC(bigint gX, bigint gY); // Multiplication for elliptic curves, double and add

	void addECC(bigint pX, bigint pY, bigint qX, bigint qY, bigint& rX, bigint& rY); // Addition invented for elliptic curves, adding 2 points

	void doubleECC(bigint P, bigint r);

private:

	bigint randNum; // Random number on curve

	// Curve parameters
	bigint curve; // Elliptic curve given by SECP256K1

	// Coefficients of curve
	int aCurve;
	int bCurve;
	bigint N; // Number of points on domain

	// Generator point, random number in range of curve
	bigint gX;
	bigint gY;

	bigint privKey; // Randomly generated private key
	bigint pubKey; // Randomly generated public key
	bigint hashedData; // Hash of message/transaction

};
