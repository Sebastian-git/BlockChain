#include "ECC.h"
#include <iostream>
#include <math.h>
#include <cmath>

ECC::ECC() : curve((int)(pow(2, 3) - pow(2, 32) - pow(2, 9) - pow(2, 8) - pow(2, 7) - pow(2, 6) - pow(2, 4) - 1)), N("115792089237316195423570985008687907852837564279074904382605163141518161494337"), aCurve(0), bCurve(7), gX(), gY(), privKey("75263518707598184987916378021939673586055614731957507592904438851787542395619"), pubKey(), hashedData() {

}

int ECC::modECC(int randNum, int N) {

}

int ECC::multECC(int gX, int gY, int privKey) {
	if (privKey == 0 || privKey >= N) {
		std::cout << "Invalid private key.\n";
	}

}

void ECC::addECC(int P[], int Q[], std::vector<float>& r) {
	float lamAdd = ((Q[1] - P[1] * modECC(Q[0] - P[0], curve)) % curve);
	r.push_back(std::fmod(lamAdd * lamAdd - P[0] - Q[0], curve));
	r.push_back(std::fmod(lamAdd * (P[0] - xR) - P[1], curve));
}

void ECC::doubleECC(int P[], std::vector<float>& r) {
	float lamDouble = std::fmod((3 * P[0] * P[0] + aCurve) * modECC((2 * P[1]), curve), curve);
	r.push_back(std::fmod(lamDouble * lamDouble - 2 * P[0], curve));
	r.push_back(std::fmod((lamDouble * (P[0] - r[0]) - P[1]), curve));
}