#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "compression/compress.h"
#include "encrypt/encrypt.h"

using namespace std;

void printUsage(){
    cout<<"Usage: \n";
    cout<<"fequip -command -type <input_file> \n";
}

int main(int argc, char* argv[]) {
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
        string outputFile = inputFile + ".huff";
        string mapFile = inputFile + ".map";

        // Call compression function
        bool success = compressFile(inputFile, outputFile, mapFile);
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

        // Call encryption function
        bool success = encryptFile(inputFile, outputFile, keyFile);
        if (success) {
            cout << "File encrypted successfully.\n";
        } else {
            cout << "Encryption failed.\n";
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