Copyright 2018 ASHISH PANDEY

# Blockchaincpp
THIS PROJECT IS ABOUT IMPLEMENTATION OF BLOCKCHAIN TECHNOLOGY IN C++.
About the project:

This program will hold the simple tracaction history in cryptographically linked blocks.
I have implemented 3 security checks to ensure the ledger is immutable.
1. Security check of difficulty level(default 4): This will ensure that all blocks are having same level of difficulty Eg:numbers of zeros in start of hash.
2. Security check of previous hash : This will ensure that all the blocks are well linked and there can be no tampering in ledger by adding any block that has not been mined.
3. Security check of Cryptographic hash: This will further ensure that no block will be added without minning and no block can be added without minning (proof of work concept ). 

The default difficulty level has been set to 4 that is too low and was set for demonstration you can increase the difficulty level in blockchain.h to ensure security like level 6 or level 7, but this incresed difficulty level will require more computation power to mine the block.

THIS IS A BASIC STRUCTURE. YOU CAN USE THIS STRUCTURE TO IMPLEMENT BLOCKCHAIN TEACHNOLOGY IN ANY OTHER PROJECT YOU WANT.
