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
	privKey("75263518707598184987916378021939673586055614731957507592904438851787542395619"),
	pubKey(),
	randNum("28695618543805844332113829720373285210420739438570883203839696518176414791234"),
	hashedData("86032112319101611046176971828093669637772856272773459297323797145286374828050")
{
	

}

int ECC::modECC(bigint randNum, bigint N) {
	return 1;
}

int ECC::multECC(bigint gX, bigint gY, bigint scalar, bigint& x, bigint& y) {
	if (scalar == (bigint)0 || scalar >= N) {
		std::cout << "Invalid scalar passed to multECC\n";
		return -1;
	}

	bigint originalGX = gX;
	bigint originalGY = gY;

	//std::cout << std::bitset<64> (scalar.str).to_string

	return 1;
}

void ECC::addECC(bigint pX, bigint pY, bigint qX, bigint qY, bigint& x, bigint& y) {
	bigint lambda = ((qY - pY) / (qX - pX)) % curve;
	x = (lambda * lambda - pX - qX) % curve;
	y = (lambda * (pX - x) - pY) % curve;
}

void ECC::doubleECC(bigint pX, bigint pY, bigint& x, bigint& y) {
	bigint lambdaNumerator = ((3 * pX * pX) + (bigint)aCurve);
	bigint lambdaDenominator = (2 * pY);
	bigint lambda = lambdaNumerator * (bigint)modECC(lambdaDenominator, curve);
	x = (lambda * lambda - 2 * pX) % curve;
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