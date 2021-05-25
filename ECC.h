#pragma once
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

//using boost::multiprecision::cpp_int;

class ECC {

public:
	ECC();

	int modECC(int randNum, int N); // Extended Euclidean Algorithm, "division" for elliptic curves

	int multECC(int gX, int gY); // Multiplication for elliptic curves, double and add

	void addECC(int P[], int Q[], std::vector<int>& r); // Addition invented for elliptic curves, adding 2 points

	void doubleECC(int P[], std::vector<int>& r);

private:
	// Curve parameters
	int curve; // Elliptic curve given by SECP256K1
	// Coefficients of curve
	int aCurve;
	int bCurve;
	boost::multiprecision::cpp_int N; // Number of points on domain

	// Generator point, random number in range of curve
	boost::multiprecision::cpp_int gX;
	boost::multiprecision::cpp_int gY;

	boost::multiprecision::cpp_int privKey; // Randomly generated private key
	boost::multiprecision::cpp_int pubKey; // Randomly generated public key
	boost::multiprecision::cpp_int hashedData; // Hash of message/transaction

};
