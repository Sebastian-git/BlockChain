#include "RSA.h"

RSA::RSA() {}

void RSA::generateKeys() {
    int p = 227; // Random big prime number P
    int q = 239; // Random big prime number Q
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

    keys.publicKeyExponent = e;
    keys.publicKeyModulus = n;
    keys.privateKey = d;
}

int RSA::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}