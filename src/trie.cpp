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
    }
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
    char currLetter;
    if(word.empty()){
        // Check to see if the current node's node is a word
        if(node->lettersVec[0]->isWord){
            
        }
    }
    currLetter = word[0];
    word.erase(word.begin());

    
}

string to_lower(string word){
    string lowerWord;
    for(char c : word){
        lowerWord += tolower(c);
    }
    return lowerWord;
}

void TrieTree::insert(string word){
    insert(this->root, to_lower(word));
}

bool TrieTree::search(string word){
    return search(this->root, to_lower(word));

}
bool TrieTree::searchPrefix(string prefix){
    
}