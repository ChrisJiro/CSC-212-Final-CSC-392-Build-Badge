#include "trie.h"

TrieNode::TrieNode(){
    
}

TrieNode::TrieNode(char letter){
    this->letter = letter;
}





TrieTree::TrieTree(){
    this->root = new TrieNode();
}


void TrieTree::insert(TrieNode* node, string word){
    // Assign current working letter and remove first letter from word
    char currLetter;
    if(!word.empty()){
        currLetter = word[0];
        word.erase(word.begin());
    }
    // Check each Node of the vector to see if the letter exists
    for(TrieNode* letterNode : node->lettersVec){
        if(letterNode->letter == currLetter){
            // Recursive call navigating to that letter
            insert(letterNode, word);
            return;
        }
    }
    // If we navigate the whole vector and the letter doesn't exist
    TrieNode *temp = new TrieNode(currLetter);
    node->lettersVec.push_back(temp);
    insert(temp, word);

    // If there are no more letters to insert, we handle the isWord Bool
    if(word.empty()){
        // If there are no letters in the vec
        if(node->lettersVec.empty()){
            TrieNode* temp = new TrieNode();
            temp->isWord = true;
            node->lettersVec.push_back(temp);
        }
        // Otherwise there is letters in the vector so set the first one = true
        else{
            node->lettersVec[0]->isWord = true;
        }
    }
    return;
}

// Recursive method
bool TrieTree::search(TrieNode* node, string word){
    if(word.size() == 0){
        return true;
    }

    char currLetter = word[0];
    
    // Parse every letter following the first for recursive call
    string newWord;
    for(int i = 1; i < word.size() - 1; i++){
        newWord += word[i];
    }

    // Check every value in the current node's vector to see if its letter matches currLetter
    for(TrieNode* currNode : node->lettersVec){
        if(currNode->letter == currLetter){
            // Recursive call to that letter
            if(search(currNode, word)){
                return true;
            }
        }
    }

    return false;
}

bool TrieTree::search(string word){
    return search(this->root, word);

}
bool TrieTree::searchPrefix(string prefix){
    
}