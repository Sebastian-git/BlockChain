#include "Block.h"
#include <boost/multiprecision/cpp_int.hpp>

Block::Block() : sha(), senderPassword(), UID() {}

Block::Block(std::vector<std::string> data, std::string date) : sha(), senderPassword(), UID() {
	
	SHA256 sha;
	
	headerInfo.date = date;

	transferInfo.senderID = sha(data[0]);
	transferInfo.recipientID = sha(data[2]);
	transferInfo.quantity = data[3];
	
}

void Block::generateBlock(std::vector<std::string> data, std::string date) {

	headerInfo.date = date;

	transferInfo.senderID = sha(data[0]);
	transferInfo.recipientID = sha(data[2]);
	transferInfo.quantity = data[3];
	
    generateSignature();

}

void Block::generateSignature() {

    int publicKey;

    int privateKey;

    // if getPublic/PrivateKey == "", generatePublic/PrivateKey, else, set = return value

    int p = 89; // Random big prime number P
    int q = 97; // Random big prime number Q
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

    /* 
    RSA Signature Algorithms:

    Generation:     signature = (message^privateKey) % n

    Verification:     message = (signature^publicKey) % n
    */

    std::string msg = sha(transferInfo.senderPublicKey + transferInfo.recipientPublicKey);

    std::cout << "Hashed message: " << msg << "\n";

    std::vector<boost::multiprecision::int1024_t> signature; // Vector containing individually encrypted characters that make up signature

    boost::multiprecision::int1024_t cur; // Current character being encrypted

    for (int i = 0; i < msg.size(); ++i) {
        cur = boost::multiprecision::powm((int)msg[i], d, n);
        signature.push_back(cur);
    }

    std::cout << "\n\n Signature:\n";
    for (int i = 0; i < signature.size(); i++) {
        std::cout << signature[i];
    }
    std::cout << "\n\n";

    std::string ogMsg = ""; // Original message, decrypted
    for (int i = 0; i < signature.size(); i++) {
        ogMsg += (char)boost::multiprecision::powm(signature[i], e, n);
    }
    std::cout << "Original message, decrypted: " << ogMsg << "\n";
}

int Block::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}