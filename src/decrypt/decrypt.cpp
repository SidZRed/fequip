#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int decryptFile(string inputFile, string outputFile, string keyFile, string type){
    if (type == "cipher"){
        cout<<"Decrypting using cipher \n";

        string key;
        fstream keyFileStream(keyFile);
        if(keyFileStream.is_open()){
            keyFileStream >> key;
            keyFileStream.close();
        }
        else{
            cout<<"Error while reading key file\n";
            return 0;
        }

        ifstream inputFileStream(inputFile);
        string cipheredContent;
        if(inputFileStream.is_open()){
            stringstream buffer;
            buffer << inputFileStream.rdbuf();
            cipheredContent = buffer.str();
            inputFileStream.close();
        }
        else{
            cout<<"Error while reading input file\n";
            return 0;
        }

        // Decrypt the content with the key.
        string originalContent;
        for (int i = 0; i < cipheredContent.size(); i++) {
            originalContent += cipheredContent[i] - key[i % key.size()];
        }

        // Write the original content to the output file.
        ofstream outputFileStream(outputFile);
        if(outputFileStream.is_open()){
            outputFileStream << originalContent;
            outputFileStream.close();
        }
        else{
            cout<<"Error while writing to output file\n";
            return 0;
        }
    }

    return 1;
}
