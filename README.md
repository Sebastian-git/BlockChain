# <a name="title" /> BlockChain

### Introduction
As a final project for my Computer Science: Data Structures and Algorithms class, I decided to try to implement a basic blockchain to explore cryptography, hash functions, and how cryptocurrencies actually work with a mix of SFML for graphics (my Professor loves SFML).

Documentation is split into [Usage](#usage) and [Technical Information](#techinfo). Enjoy!

<hr>

<a name="usage"/>

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

<hr>

<a name="techinfo"/>

### Technical Information 

The technical information I've researched while creating this project will be documented according the following categories:

#### Objects/Libraries: 
- [Graphics](#graphics)
- [Blocks](#blocks)
- [Sockets](#sockets)
- [Threading](#threading)

#### Cryptography/Algorithms: 
- [Hash Functions]()
- [Rabin Miller Primality Test]()
- [Modular Exponentiation]()
- [Hash Trees and Merkle Roots]()
- [Proof of Work]()

#### Problems encountered:
- [Elliptic Curve Cryptography]()
- [Implementation of Proof of Work]()

<hr>

#### Objects / Libraries:

<br>

<a name="graphics"/>

#### Graphics

My professor requested that we create our own graphical components using [SFML](https://www.sfml-dev.org/), so I created the following objects:

<br>

- **GUIComponent**: An [abstract class](https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm) that all graphial components extend because of its two pure virtual functions; draw() and addEventHandler(). Both functions are from SFML, so any component that would be drawn to the screen would need to use the functions anyway.

- **TextLabel**: Extends GUIComponent, and has methods for getting/setting position, size, text, text color, and bounds. This is used for any words displayed on the GUI.

- **TextBox**: Extends GUIComponent, and has methods for getting/setting the position of everything inside the box, box size, box color, box thickness, text, text size, text color, and text margin. Although it might have been better to add additional GUI components for the text inside the box, part of the assignment required the textbox to have a blinking cursor. 

<br>

<a name="blocks"/>

#### Blocks

- **Block**: The block object contains two structs that make up the information of a transaction; headerInfo and transferInfo. There are methods to generate a block with a vector of data, and a reference to an object of the RSA class which generates RSA public and private keys. Once a block is generated, the information can be saved to a file and begins the blockchain. 

<br>

<a name="sockets"/>

#### Sockets

- **Network**: The network object handles all the connections, and uses SFML's Network library. One important detail about the library is the .setBlocking() function, which blocks all connections under certain cases and presented issues when first using sockets.

<br>

<a name="threading"/>

#### Threading

- Threading was originally implemented in the program to run the networking object at the same time as the GUI object, since the way SFML handles GUI's is through a while loop. However, multiple threads are also used inside the "powerpoint" explaining how RSA works to run the different tasks at the same time.

<br>

<hr>

#### Cryptography/Algorithms: 

<br>

<a name="hashfunctions"/>

#### Hash Functions

<br>

<a name="primalitytest"/>

#### Rabin Miller Primality Test

<br>

<a name="modularexponentiation"/>

#### Modular Exponentiation

<br>

<a name="hashtrees"/>

#### Hash Trees and Merkle Roots

<br>

<a name="proofofwork"/>

#### Proof of Work

<br>

<hr>

#### Problems encountered:

<br>

<a name="proofofwork"/>

#### Elliptic Curve Cryptography

<br>

<a name="proofofwork"/>

#### Implementation of Proof of Work



<br><br>

Readme will be updated when project is completed with a full description. Notes on how to complete the documentation are below and can be ignored.

Merckle Roots and hash trees and efficiency, hash functions and SHA256 and ECC and diffie hellman and RSA, Rabin Miller Primality Test, Modular Exponentiation's CRITICAL role in RSA, proof of work, how each client verifies transactions

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
