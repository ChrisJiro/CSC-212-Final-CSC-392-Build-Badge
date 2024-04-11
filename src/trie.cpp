#include "trie.h"

TrieNode::TrieNode(){
    
}

TrieNode::TrieNode(char letter){
    this->letter = letter;
}





TrieTree::TrieTree(){
    this->root = new TrieNode();
}
void TrieTree::insert(string word){
    // Make a pointer to the root
    TrieNode* temp = this->root;

    // For each letter in the word
    for(char currLetter : word){
        for(TrieNode* currChild : temp->lettersVec){
            // If the current node has a pointer to the letter
            if(currChild->letter == currLetter){
                temp = temp-currChild->letter;
                break;
            }
            else{
                TrieNode* childNode = new TrieNode(currLetter);
                temp->lettersVec.push_back(childNode);
                // Iterate through the vector to update the temp pointer
                for(int i = 0; i < temp->lettersVec.size() - 1; i++){
                    if(temp->lettersVec[i]->letter == currLetter){
                        temp = temp->lettersVec[i];
                    }
                }
                break;
            }
        }
    }
    if(temp->lettersVec.empty()){
        TrieNode* endNode = new TrieNode();
        endNode->isWord = true;
        temp->lettersVec.push_back(endNode);
    }
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