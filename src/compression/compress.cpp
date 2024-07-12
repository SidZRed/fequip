#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// Huffman Tree Node
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// For priority queue: comparison object for min heap
struct compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return (left->freq > right->freq);
    }
};

// Function to generate Huffman codes and store them in a map
void generateHuffmanCodes(struct HuffmanNode* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;

    if (root->data != '$')
        huffmanCode[root->data] = str;

    generateHuffmanCodes(root->left, str + "0", huffmanCode);
    generateHuffmanCodes(root->right, str + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate the codes
void buildHuffmanTree(string text, unordered_map<char, string> &huffmanCode) {
    unordered_map<char, unsigned> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

    for (auto pair : freq) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        HuffmanNode *top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    generateHuffmanCodes(minHeap.top(), "", huffmanCode);
}

// Function to compress using Huffman Coding
int compressHuffman(string inputFile, string outputFile, string mapFile) {
    ifstream inputFileStream(inputFile);
    stringstream buffer;
    if (inputFileStream.is_open()) {
        buffer << inputFileStream.rdbuf();
        inputFileStream.close();
    } else {
        cout << "Error while reading input file\n";
        return 0;
    }

    string text = buffer.str();
    unordered_map<char, string> huffmanCode;
    buildHuffmanTree(text, huffmanCode);

    ofstream mapFileStream(mapFile);
    if (mapFileStream.is_open()) {
        for (auto pair : huffmanCode) {
            mapFileStream << pair.first << ":" << pair.second << "\n";
        }
        mapFileStream.close();
    } else {
        cout << "Error while writing to map file\n";
        return 0;
    }

    string compressedText;
    for (char ch : text) {
        compressedText += huffmanCode[ch];
    }

    ofstream outputFileStream(outputFile, ios::binary);
    if (outputFileStream.is_open()) {
        outputFileStream << compressedText;
        outputFileStream.close();
    } else {
        cout << "Error while writing to output file\n";
        return 0;
    }

    return 1;
}

// Function to compress using LZW Compression
int compressLZW(string inputFile, string outputFile, string mapFile) {
    ifstream inputFileStream(inputFile);
    stringstream buffer;
    if (inputFileStream.is_open()) {
        buffer << inputFileStream.rdbuf();
        inputFileStream.close();
    } else {
        cout << "Error while reading input file\n";
        return 0;
    }

    string text = buffer.str();

    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[string(1, i)] = i;
    }

    string w;
    vector<int> compressed;

    for (char c : text) {
        string wc = w + c;
        if (dictionary.find(wc) != dictionary.end()) {
            w = wc;
        } else {
            compressed.push_back(dictionary[w]);
            dictionary[wc] = dictionary.size();
            w = string(1, c);
        }
    }

    if (!w.empty()) {
        compressed.push_back(dictionary[w]);
    }

    ofstream outputFileStream(outputFile, ios::binary);
    if (outputFileStream.is_open()) {
        for (int code : compressed) {
            outputFileStream.write(reinterpret_cast<char*>(&code), sizeof(code));
        }
        outputFileStream.close();
    } else {
        cout << "Error while writing to output file\n";
        return 0;
    }

    return 1;
}

// Main function to handle command line arguments
int compressFile(string inputFile, string outputFile, string mapFile, string type) {
    if (type == "-huffman") {
        return compressHuffman(inputFile, outputFile, mapFile);
    } else if (type == "-lzw") {
        return compressLZW(inputFile, outputFile, mapFile);
    } else {
        cout << "Invalid compression type\n";
        return 0;
    }
}
