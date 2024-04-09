#pragma once

#include <string>

using namespace std;

struct TrieNode{
    struct TrieNode* 
}

class TrieTree{
    private:

    public:
        TrieTree();
        void insert(string word);
        bool search(string word);
        bool searchPrefix(string prefix);
};