#include "ECC.h"
#include <iostream>
#include <cmath>
#include <bitset>

ECC::ECC() :
	curve(big_pow(2, 256) - big_pow(2, 32) - big_pow(2, 9) - big_pow(2, 8) - big_pow(2, 7) - big_pow(2, 6) - big_pow(2, 4) - bigint(1)),
	aCurve(0), 
	bCurve(7),
	N("115792089237316195423570985008687907852837564279074904382605163141518161494337"),
	gX("55066263022277343669578718895168534326250603453777594175500187360389116729240"),
	gY("32670510020758816978083085130507043184471273380659243275938904335757337482424"),
	privKey("108165236279178312660610114131826512483935470542850824183737259708197206310322"),
	pubKey(),
	randNum("28695618543805844332113829720373285210420739438570883203839696518176414791234"),
	hashedData("86032112319101611046176971828093669637772856272773459297323797145286374828050")
{

	/*
	bigint x = gX;
	bigint y = gY;
	
	multECC(gX, gY, privKey, x, y);

	std::cout << "Private key: \n" << privKey << "\n\n";
	std::cout << "Public keys uncompressed: \n";
	std::cout << "X: \n" << x << "\nY:\n" << y << "\n\n";

	bigint xSig;
	bigint ySig;
	multECC(gX, gY, randNum, xSig, ySig);
	bigint r = xSig % N;
	std::cout << "R: " << r << "\n";
	bigint s = (hashedData + r * privKey) * (modECC(randNum, N)) % N;
	std::cout << "S: " << s << "\n";





	bigint w = modECC(s, N);
	
	bigint xu1;
	bigint yu1;

	bigint xu2;
	bigint yu2;

	std::cout << "A/N\n";
	std::cout << ((r * w) % N) << "\n";
	std::cout << N << "\n";




	multECC(gX, gY, (hashedData * w) % N, xu1, yu1);
	multECC(x, y, (r * w) % N, xu2, yu2);
	
	bigint sigX;
	bigint sigY;

	addECC(xu1, yu1, xu2, yu2, sigX, sigY);

	std::cout << "Signature : " << sigX << "\n" << sigY << "\n";

	std::cout << (r == x) << "\n";
	*/

}

bigint ECC::modECC(bigint a, bigint m) {

	m = curve;

	if (a < bigint(0)) {
		a = a % curve;
	}
	
	bigint prevY = 0;
	bigint y = 1;
	
	bigint q;

	while (a > bigint(1)) {
		q = m / a; 
		
		// m / a becomes 0, creates error
		//https://en.wikipedia.org/wiki/Division_algorithm#Newton%E2%80%93Raphson_division
		//http://burtleburtle.net/bob/math/bigfloat.html

		y = prevY - q * y;
		prevY = y;

		a = m % a;
		m = a;
	}

	return y;
}

void ECC::multECC(bigint xS, bigint yS, bigint scalar, bigint& x, bigint& y) {
	if (scalar == (bigint)0 || scalar >= N) {
		std::cout << "Scalar is " << scalar << "\n";
		std::cout << "Invalid scalar passed to multECC\n";
		return;
	}

	bigint currentX = xS;
	bigint currentY = yS;

	bigint newX;
	bigint newY;

	bigint binaryScaler("");
	toBase2(scalar, binaryScaler);

	for (int i = 1; i < binaryScaler.str.size(); i++) {
		doubleECC(currentX, currentY, newX, newY);
		currentX = newX;
		currentY = newY;

		if (binaryScaler.str[i] == '1') {
			addECC(currentX, currentY, gX, gY, newX, newY);
			currentX = newX;
			currentY = newY;
		}
	}

	x = currentX;
	y = currentY;
}

void ECC::addECC(bigint pX, bigint pY, bigint qX, bigint qY, bigint& x, bigint& y) {
	if (pX == qX && pY == qY) {
		x = pX;
		y = pY;
		return;
	}
	bigint lambda = ((qY - pY) * modECC((qX - pX), curve)) % curve;
	x = ((lambda * lambda) - pX - qX) % curve;
	y = (lambda * (pX - x) - pY) % curve ;
}

void ECC::doubleECC(bigint pX, bigint pY, bigint& x, bigint& y) {
	bigint num = 2;
	bigint lambdaNumerator = 3 * big_pow(pX, num);
	bigint lambdaDenominator = (2 * pY);
	bigint lambda = (lambdaNumerator * modECC(lambdaDenominator, curve)) % curve;
	x = ((lambda * lambda) - (2 * pX)) % curve;
	y = (lambda * (pX - x) - pY) % curve;
}

void ECC::toBase2(bigint base10, bigint& base2) {

	// divide base10 by 2
	// if remainder = 0, add 1 to left of binary conversion
	// if remainder = 1, add 0 to left of binary conversion

	bigint quotient = base10;
	bigint remainder;

	while (quotient > bigint(0)) {
		remainder = quotient % bigint(2);
		quotient /= 2;
		if (remainder == bigint(0)) {
			base2.str.insert(0, "0");
		}
		else {
			base2.str.insert(0, "1");
		}
	}
}