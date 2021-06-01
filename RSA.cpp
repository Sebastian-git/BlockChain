#include "RSA.h"
#include <fstream>

RSA::RSA() {}

bool RSA::keysExist() {

    // Check if keys exist, if they do, update the member variables
    std::ifstream file("keys.txt");
    std::string line;
    std::getline(file, line);
    if (line != "") {
        keys.publicKeyExponent = line;
        std::getline(file, line);
        keys.publicKeyModulus = line;
        std::getline(file, line);
        keys.privateKey = line;
        return true;
    }
    return false;
}

void RSA::generateKeys() {
    int p = 7723; // Random big prime number P
    int q = 7919; // Random big prime number Q
    int n = p * q; // Public key n is the product of the two large prime numbers
    int phi_n = (p - 1) * (q - 1); // phi_n helps generate second public key, e, and the private key, d

    unsigned int i = 2;
    while (gcd(i, phi_n) != 1) {
        i++;
    }

    int e = i; // e is a value between 1 and phi_n - 1, and doesn't share any common factors with phi_n

    unsigned int k = 1;
    while ((k * phi_n + 1) % e != 0) {
        k++;
    }

    int d = (k * phi_n + 1) / e; // d is calculated such that (e * d) ^ phi_n = 1

    keys.publicKeyExponent = std::to_string(e);
    keys.publicKeyModulus = std::to_string(n);
    keys.privateKey = std::to_string(d);

    // Save new keys
    std::ofstream out;
    out.open("keys.txt", std::ios_base::app);
    out << keys.publicKeyExponent << "\n";
    out << keys.publicKeyModulus << "\n";
    out << keys.privateKey << "\n";
    out.close();
}

void RSA::displayKeys() {
    std::cout << "-------------Keys---------------\n";
    std::cout << "Public exponent: " << keys.publicKeyExponent << "\n";
    std::cout << "Public modulus: " << keys.publicKeyModulus << "\n";
    std::cout << "Private: " << keys.privateKey << "\n";
}

int RSA::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}