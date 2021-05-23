#include "ECC.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <bitset>

ECC::ECC() : curve((int)(pow(2, 3) - pow(2, 32) - pow(2, 9) - pow(2, 8) - pow(2, 7) - pow(2, 6) - pow(2, 4) - 1)), N("115792089237316195423570985008687907852837564279074904382605163141518161494337"), aCurve(0), bCurve(7), gX(), gY(), privKey("75263518707598184987916378021939673586055614731957507592904438851787542395619"), pubKey(), hashedData() {

	std::cout << "Privkey size " << privKey.size() << "\n";
	std::cout << "n size " << N.size() << "\n";
}

int ECC::modECC(int randNum, int N) {
	return 1;
}

int ECC::multECC(int gX, int gY) {
	if (privKey.size() == 0 || privKey.size() >= N.size()) {
		std::cout << "Invalid private key.\n";
	}
	std::bitset<8> binary = std::bitset<8>(privKey);
	std::cout << binary << "\n";

	return 1;
}

void ECC::addECC(int P[], int Q[], std::vector<int>& r) {
	int lamAdd = ((Q[1] - P[1] * modECC(Q[0] - P[0], curve)) % curve);
	r.push_back(std::fmod(lamAdd * lamAdd - P[0] - Q[0], curve));
	r.push_back(std::fmod(lamAdd * (P[0] - r[0]) - P[1], curve));
}

void ECC::doubleECC(int P[], std::vector<int>& r) {
	int lamDouble = std::fmod((3 * P[0] * P[0] + aCurve) * modECC((2 * P[1]), curve), curve);
	r.push_back(std::fmod(lamDouble * lamDouble - 2 * P[0], curve));
	r.push_back(std::fmod((lamDouble * (P[0] - r[0]) - P[1]), curve));
}