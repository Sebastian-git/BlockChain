#pragma once
#include <vector>
#include <string>

#include "bigint.h"

/*
Sources:

Full process of ECDSA (Elliptic Curve Digital Signature Algorithm)
https://learnmeabitcoin.com/technical/ecdsa

Python implementation:
https://github.com/wobine/blackboard101/blob/master/EllipticCurvesPart5-TheMagic-SigningAndVerifying.py
*/

class ECC {

public:
	ECC();

	void addECC(bigint pX, bigint pY, bigint qX, bigint qY, bigint& x, bigint& y); // Addition invented for elliptic curves, adding 2 points
	void doubleECC(bigint pX, bigint pY, bigint& x, bigint& y); // FIGURE OUT WHAT THIS DOES
	int multECC(bigint gX, bigint gY, bigint scalar, bigint& x, bigint& y); // Multiplication for elliptic curves, double and add
	int modECC(bigint randNum, bigint N); // Extended Euclidean Algorithm, "division" for elliptic curves

	void toBase2(bigint base10, bigint& base2); // Convert bigint base 10 to bigint base 2 for multECC

private:

	bigint randNum; // Random number WHAT IS THIS FOR

	// Curve parameters
	bigint curve; // Elliptic curve given by SECP256K1 ARE YOU SURE? Big prime number for sure

	// Coefficients of curve
	int aCurve;
	int bCurve;
	bigint N; // Number of points on domain

	// Generator point, random number in range of curve
	bigint gX;
	bigint gY;

	bigint privKey; // Randomly generated private key
	bigint pubKey; // Randomly generated public key
	bigint hashedData; // Hash of message/transaction to be signed

};
