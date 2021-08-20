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

One fun feature is found after clicking the "toggle" button, which shows the entire process of generating RSA private and public keys in a sort of SFML powerpoint. Below is an image showing the generation of two large random prime numbers using the [Rabin-Miller Primality Test](#primalitytest) discussed below. <br>

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
- [Hash Functions](#hashfunctions)
- [Rabin Miller Primality Test](#primalitytest)
- [Modular Exponentiation](#modularexponentiation)
- [Hash Trees and Merkle Roots](#hashtrees)
- [Proof of Work](#proofofwork)

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

- Hash functions are used to store passwords locally, so that even if malicious users managed to get the accounts.txt file, it would be impossible to crack the passwords or usernames of other users.

<br>

<a name="primalitytest"/>

#### Rabin Miller Primality Test
- [The Rabin Miller Primality Test](https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/) is a critical component in the generation of RSA keys, as it is one of the only ways to efficiently generate random prime numbers. Essentially, it's a probability test that checks whether the numbers generated are prime which works a majority of the time and is how most random prime number generators work.

<br>

<a name="modularexponentiation"/>

#### Modular Exponentiation
- [Modular Exponentiation](https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/) is another reason RSA key generation was so fast, for calculating the exponentials of such large prime numbers would take far too long. Luckily, Boost has several [built in functions](https://www.boost.org/doc/libs/1_66_0/libs/multiprecision/doc/html/boost_multiprecision/perf/int_real_world.html) for topics like this.

<br>

<a name="proofofwork"/>

#### Proof of Work
- The last form of security used in the program is [Proof of Work](https://www.investopedia.com/terms/p/proof-work.asp), which can be implemented to secure transactions in different ways. The main idea is that computers need to race to "mine" data (use their processing power to try different combinations of characters to achieve a specified hash value). The winning computer then gets a portion of the cryptocurrency as a reward, then shares the new "block" with the new specified hash. This was the last concept to be implemented on the program, but won't be because of how extensive the computer networking would be. 

<br>

<hr>

### Launch
C++ 14 <br>
Visual C++ 2019 <br>
SFML 2.5.1 <br>
Boost 1.76.0 <br>

### Status: 

Complete

#### [back to the top](#title)
