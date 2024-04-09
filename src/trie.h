#pragma once

#include <string>

using namespace std;

class TrieNode{
    private:

    public:
        TrieNode();


};

class TrieTree{
    private:

    public:
        TrieTree();
        void insert(string word);
        bool search(string word);
        bool searchPrefix(string prefix);
};