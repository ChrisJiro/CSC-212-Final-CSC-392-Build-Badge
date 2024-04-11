#pragma once

#include <vector>
#include <string>

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
    public:
        TrieTree();
        void insert(string word);
        bool search(string word);
        bool searchPrefix(string prefix);
};