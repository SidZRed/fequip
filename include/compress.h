#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
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

// Comparison object for min heap in priority queue
struct compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return (left->freq > right->freq);
    }
};

// Function declarations
int compressFile(string inputFile, string outputFile, string mapFile, string type);
int compressHuffman(string inputFile, string outputFile, string mapFile);
int compressLZW(string inputFile, string outputFile, string mapFile);

#endif // COMPRESS_H
