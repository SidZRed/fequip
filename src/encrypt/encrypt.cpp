#include <bits/stdc++.h>
#include<random>
#include <sstream>

using namespace std;

string generateKey(int length) {
    string key;
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    uniform_int_distribution<> dis(0, characters.size() - 1);

    for (int i = 0; i < length; ++i) {
        key += characters[dis(gen)];
    }

    return key;
}


int encryptFile(string inputFile, string outputFile, string keyFile, string type){
    if (type == "cipher"){
        cout<<"Encrypting using cipher\n";
        string key = generateKey(32);
        fstream keyFileStream(keyFile);
        if(keyFileStream.is_open()){
            keyFileStream<<key;
            keyFileStream.close();
        }
        else{
            cout<<"Error while creating key file\n";
            return 0;
        }
        
        ifstream inputFileStream(inputFile);
        string content;
        if(inputFileStream.is_open()){
            stringstream buffer;
            buffer << inputFileStream.rdbuf();
            content = buffer.str();
            inputFileStream.close();
        }
        else{
            cout<<"Error while reading input file\n";
            return 0;
        }
        
        // Cipher the content with the key.
        string cipheredContent;
        for (int i = 0; i < content.size(); i++) {
            cipheredContent += content[i] + key[i % key.size()];
        }

        // Write the ciphered content to the output file.
        ofstream outputFileStream(outputFile);
        if(outputFileStream.is_open()){
            outputFileStream<<cipheredContent;
            outputFileStream.close();
        }
        else{
            cout<<"Error while writing to output file\n";
            return 0;
        }
    }
    return 1;
}