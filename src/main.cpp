#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "compression/compress.h"
#include "encrypt/encrypt.h"
#include "decrypt/decrypt.h"


using namespace std;

void printUsage(){
    cout<<"Usage: \n";
    cout<<"fequip -command -type <input_file> \n";
    cout<<"Commands: encrypt/decrypt | compress \n";
    cout<<"Types: \n";
    cout<<"-compress: huffman | lzw \n";
    cout<<"-encrypt: cipher \n";
    cout<<"Please run using above commands \n";
    }

void printHelp(){
    cout<<"Help: \n";
    cout<<"This is a file encryption and compression tool. \n";
    cout<<"Commands: encrypt/decrypt | compress \n";
    cout<<"Types: \n";
    cout<<"-compress: huffman | lzw \n";
    cout<<"-encrypt: cipher \n";
    cout<<"Please run using above commands \n";
}

int main(int argc, char* argv[]) {
    if(argc == 2){
        if (argv[2] == "-help"){
            printHelp();
            return 0;
        }
    }
    if (argc < 4) {
        printUsage();
        return 1;
    }

    string command = argv[1];

    // Handle compression command
    if (command == "-compress") {
        if (argc != 4) {
            cout << "Invalid number of arguments for compress command.\n";
            printUsage();
            return 1;
        }

        string inputFile = argv[3];
        string outputFile = inputFile + ".cmp";
        string mapFile = inputFile + ".map";

        string type = argv[2];

        // Call compression function
        bool success = compressFile(inputFile, outputFile, mapFile, type);
        if (success) {
            cout << "File compressed successfully.\n";
        } else {
            cout << "Compression failed.\n";
        }
    }

    if (command == "-encrypt"){
        if (argc != 4) {
            cout << "Invalid number of arguments for encrypt command.\n";
            printUsage();
            return 1;
        }

        string inputFile = argv[3];
        string outputFile = inputFile + ".enc";
        string keyFile = inputFile + ".key";

        string type = argv[2];

        // Call encryption function
        bool success = encryptFile(inputFile, outputFile, keyFile, type);
        if (success) {
            cout << "File encrypted successfully.\n";
        } else {
            cout << "Encryption failed.\n";
        }
    }

    if (command == "-decrypt"){
        if (argc != 4) {
            cout << "Invalid number of arguments for decrypt command.\n";
            printUsage();
            return 1;
        }

        string inputFile = argv[3];
        string keyFile = argv[4];
        string outputFile = inputFile + ".dec";

        string type = argv[2];

        // Call decryption function
        bool success = decryptFile(inputFile, outputFile, keyFile, type);
        if (success) {
            cout << "File decrypted successfully.\n";
        } else {
            cout << "Decryption failed.\n";
        }
    }

   


    // Invalid command
    else {
        cout << "Invalid command.\n";
        printUsage();
        return 1;
    }

    return 0;
}