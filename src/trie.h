#pragma once

#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class TrieNode{
    private:
        char letter;
        bool isWord = false;
        vector<TrieNode*> lettersVec;

        friend class TrieTree;
    public:
        TrieNode();
        TrieNode(char letter);
};

class TrieTree{
    private:
        TrieNode* root;
        bool search(TrieNode* node, string word);
        void insert(TrieNode* node, string word);
        void remove(TrieNode* node, string word);
        bool searchPrefix(TrieNode* node, string prefix);
    public:
        TrieTree();
        void insert(string word);
        bool search(string word);
        void remove(string word);
        bool searchPrefix(string prefix);
};