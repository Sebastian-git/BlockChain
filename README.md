# <a name="title"></a> BlockChain

### Introduction
As a final project for my Computer Science: Data Structures and Algorithms class, I decided to try to implement a basic blockchain to explore cryptography, hash functions, and how cryptocurrencies actually work with a mix of SFML for graphics (my Professor loves SFML).

### Usage

#### Setup

1 - Clone the master repository (```git clone https://github.com/Sebastian-git/BlockChain.git```) <br>
2 - Install [C++](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0) and a compiler (I use [Visual Studio](https://visualstudio.microsoft.com/downloads/), but [G++](https://gcc.gnu.org/) is also good) if you don't already have them <br>
2 - Install SFML [here](https://www.sfml-dev.org/download/sfml/2.5.1/), and follow their [setup instructions](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) <br>
3 - Install Boost [here](https://www.boost.org/users/download/), and follow the instructions [below]() to make accessing the library easier

#### Previews

One fun feature is found after clicking the "toggle" button, which shows the entire process of generating RSA private and public keys in a sort of SFML powerpoint. Below is an image showing the generation of two large random prime numbers using the [Rabin-Miller Primality Test]() discussed below. <br>

<img width="600" height="350" alt="portfolio_view" src="https://github.com/Sebastian-git/BlockChain/blob/master/readmeImages/primeGeneration1.png"> 

<img width="400" height="300" alt="portfolio_view" src="https://github.com/Sebastian-git/BlockChain/blob/master/readmeImages/Screenshot_6.png"> <img width="400" height="300" alt="portfolio_view" src="https://github.com/Sebastian-git/BlockChain/blob/master/readmeImages/primeGeneration3.png"> 

<br> The main portion of the program comes from what happens behind the main screen, which is just a transaction prompt. At first glance, this might not look very secure. However, the power of [RSA Encryption](), the [Merkle Root system]() that was implemented, and [Proof of Work]() makes the program as secure as any other cryptocurrency. 

<img width="600" height="350" alt="portfolio_view" src="https://github.com/Sebastian-git/BlockChain/blob/master/readmeImages/transferDisplay.png"> 

### Technical Information 

The technical information I've researched while creating this project will be documented according the following categories:

#### Objects/Libraries: 
- [Graphics]()
- [Blocks]()
- [Sockets]()
- [Threading]()

#### Cryptography/Algorithms: 
- [Hash Functions]()
- [Rabin Miller Primality Test]()
- [Modular Exponentiation]()
- [Hash Trees and Merkle Roots]()
- [Proof of Work]()

#### Problems encountered:
- [Elliptic Curve Cryptography]()
- [Implementation of Proof of Work]()



Merckle Roots and hash trees and efficiency, hash functions and SHA256 and ECC and diffie hellman and RSA, Rabin Miller Primality Test, Modular Exponentiation's CRITICAL role in RSA, proof of work, how each client verifies transactions


<br><br>
Readme will be updated when project is completed with a full description.


## Topics that will be included in more detail in the README once the project is done:

- Basic SFML features, new objects like Buttons, TextInputs, and Labels
- Block object, how it distrbutes the "chain" to all clients to prevent fraud
- Sockets (what SFML's .setBlocking() function does, how clients share the blockchain with the server)
- Merckle roots/trees (what a hash tree is, efficiency compared to just hashing all values)
- Hash functions (asymmetric vs symmetric, SHA256, ECC, Diffie Hellman, Rabin-Miller Primality Test)
- Explain modular exponentiation, and why its the only reason the RSA code works fast enough
- Proof of work, computer networking, how each node/client verifies transactions
- C++ threading library
<br><br>


### Launch
C++ 14 <br>
Visual C++ 2019 <br>
SFML 2.5.1 <br>
Boost 1.76.0 <br>

### Status: 

In Progress 

#### [back to the top](#title)
