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
    // cout << word << " " << node->letter << endl;
    if(!node){
        return;
    }
    if(word.empty()){
        if(node->isWord){
            node->isWord = false;
        }
        return;
    }
    char c = word[0];
    word.erase(word.begin());

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
    // If it is not a prefix
    // If the current vector has children and the node is the last letter in the word
    if(!node->lettersVec.empty() && node->lettersVec[0]->isWord == true){
        // cout << "Deleting" << node->letter << endl;
        node->lettersVec[0]->isWord = false;
        // If the current word is not a prefix
        if(node->lettersVec[0]->lettersVec.empty()){
            delete node->lettersVec[0];
            node->lettersVec.erase(node->lettersVec.begin());
            node->lettersVec[0] = nullptr;
        }
    }
    // As we return back up the stack, we delete if possible (There are no other nodes)
}

// bool TrieTree::searchPrefix(TrieNode* node, string prefix){
//     char currLetter;
//     if(prefix.empty()){
//         // Check if there are still letters (not the end of a word)
//         if(!node->lettersVec.empty()){
//             TrieNode* temp = node->lettersVec[0];
//             if(!temp->lettersVec.empty()){
//                 return true;
//             }
//         }
//         return false;
//     }
//     currLetter = prefix[0];
//     prefix.erase(prefix.begin());
//     // Iterate through whole vector to compare to letter
//     for(TrieNode* temp : node->lettersVec){
//         if(temp->letter == currLetter){
//             // Recursive call to that node
//             if(search(temp, prefix)) return true;
//         }
//     }
//     return false;
// }

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
    return search(this->root, to_lower(prefix));
}
void TrieTree::remove(string word){
    return remove(this->root, to_lower(word));
}