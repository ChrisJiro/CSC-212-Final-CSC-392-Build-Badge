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
        if(!node->lettersVec.empty()){
            if(node->lettersVec[0]->isWord){
                return true;
            }
        }
        return false;
    }
    currLetter = word[0];
    word.erase(word.begin());
    // Iterate through whole vector to compare to letter
    for(TrieNode* temp : node->lettersVec){
        if(temp->letter == currLetter){
            // Recursive call to that node
            if(search(temp, word)) return true;
        }
    }
    return false;
}

void TrieTree::remove(TrieNode* node, string word){
    if(!node){
        return;
    }
    char c = word[0];
    word.erase(word.begin());
    // cout << word << endl;

    // If there are still letters, navigate down
    if(!word.empty()){
        //Iterate all the way down
        for(int i = 0; i < node->lettersVec.size(); i++){
            TrieNode* temp = node->lettersVec[i];
            if(temp->letter == c){
                remove(temp, word);
                break;
            }
        }
    }
    // If our word is empty, we have navigated to the last node / We only want to
    // Update the current word's 'isword' bool
    if(word.empty()){
        // Update our current node's child to be no longer a word
        if(!node->lettersVec.empty()){
            // cout << "Child is word: " << node->lettersVec[0]->isWord << endl;
            node->lettersVec[0]->isWord = false;
            // cout << "Child is word: " << node->lettersVec[0]->isWord << endl;
        }
    }
    // Make a pointer to the current letter node
    for(TrieNode* temp : node->lettersVec){
        if(temp->letter == c){
            // See if there are any children (if not we can delete that node)
            for(int i = 0; i < temp->lettersVec.size(); i++){
                TrieNode* subTemp = temp->lettersVec[i];
                // The current child node has no children, we can delete it and remove it from our current vector
                if(subTemp->lettersVec.empty()){
                    delete subTemp;
                    temp->lettersVec.erase(temp->lettersVec.begin() + i);
                }
            }
        }
    }
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
void TrieTree::remove(string word){
    return remove(this->root, to_lower(word));
}