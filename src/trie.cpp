#include "trie.h"

/**
 * @brief Construct a new Trie Node:: Trie Node object as empty. No letter or child nodes.
 */
TrieNode::TrieNode(){
}

/**
 * @brief Construct a new Trie Node:: Trie Node object with a specified letter, but no child nodes.
 * 
 * @param letter The letter to be stored within the node
 */
TrieNode::TrieNode(char letter){
    this->letter = letter;
}

/**
 * @brief Construct a new Trie Tree:: Trie Tree object with a root node.
 * 
 */
TrieTree::TrieTree(){
    this->root = new TrieNode();
}

/**
 * @brief This method inserts a word into the Trie Tree. In our case we are inserting names within.
 * 
 * @param node The node in which the insertion will start at
 * @param word The word to be inserted
 */
void TrieTree::insert(TrieNode* node, string word){
    //Assign current working letter and remove first letter from word.
    char currLetter;
    if(!word.empty()){
        currLetter = word[0];
        word.erase(word.begin());

        //Check each Node of the vector to see if the letter exists.
        for(TrieNode* letterNode : node->lettersVec){
            if(letterNode->letter == currLetter){
                //Recursive call navigating to that letter.
                insert(letterNode, word);
                return;
            }
        }

        //If we navigate the whole vector and the letter doesn't exist, create a node of that letter to insert.
        TrieNode *temp = new TrieNode(currLetter);
        node->lettersVec.push_back(temp);
        insert(temp, word);
    }

    //If there are no more letters to insert, we handle the isWord Bool.
    if(word.empty()){
        // If there are no letters in the vector.
        if(node->lettersVec.empty()){
            TrieNode* temp = new TrieNode();
            temp->isWord = true;
            node->lettersVec.push_back(temp);
        }

        //Otherwise there is letters in the vector so set the first one = true.
        else{
            node->lettersVec[0]->isWord = true;
        }
    }
    return;
}

/**
 * @brief This method searchs our Trie Tree to see if a word exists. In our case, names. We start at a specified node.
 * 
 * @param node The node in which to start at
 * @param word The word in which to search for
 * @return true Return true if word is found
 * @return false Return false if word is NOT found
 */
bool TrieTree::search(TrieNode* node, string word){
    char currLetter;
    if(word.empty()){
        //Check to see if the current node's node is a word.
        if(!node->lettersVec.empty()){
            if(node->lettersVec[0]->isWord){
                return true;
            }
        }
        return false;
    }
    currLetter = word[0];
    word.erase(word.begin());

    //Iterate through whole vector to compare to letter
    for(TrieNode* temp : node->lettersVec){
        if(temp->letter == currLetter){
            //Recursive call to that node
            if(search(temp, word)) return true;
        }
    }
    return false;
}

/**
 * @brief This method removes a word from the Trie Tree.
 * 
 * @param node The node in which to start at.
 * @param word The word in which to remove.
 */
void TrieTree::remove(TrieNode* node, string word){
    //If not a node, return out.
    if(!node){
        return;
    }
    char c = word[0];
    word.erase(word.begin());

    //If there are still letters, navigate down.
    if(!word.empty()){
        //Iterate all the way down.
        for(int i = 0; i < node->lettersVec.size(); i++){
            TrieNode* temp = node->lettersVec[i];
            if(temp->letter == c){
                remove(temp, word);
                break;
            }
        }
    }

    //If our word is empty, we have navigated to the last node / We only want to update the current word's 'isword' bool.
    if(word.empty()){
        //Update our current node's child to be no longer a word.
        if(!node->lettersVec.empty()){
            node->lettersVec[0]->isWord = false;
        }
    }

    //Make a pointer to the current letter node.
    for(TrieNode* temp : node->lettersVec){
        if(temp->letter == c){
            //See if there are any children (if not we can delete that node).
            for(int i = 0; i < temp->lettersVec.size(); i++){
                TrieNode* subTemp = temp->lettersVec[i];

                //The current child node has no children, we can delete it and remove it from our current vector.
                if(subTemp->lettersVec.empty()){
                    delete subTemp;
                    temp->lettersVec.erase(temp->lettersVec.begin() + i);
                }
            }
        }
    }
}

/**
 * @brief Convert string to lower case
 * 
 * @param word The word to convert
 * @return string 
 */
string to_lower(string word){
    string lowerWord;
    for(char c : word){
        lowerWord += tolower(c);
    }
    return lowerWord;
}

/**
 * @brief Public insert method.
 * 
 * @param word Word to insert
 */
void TrieTree::insert(string word){
    insert(this->root, to_lower(word));
}

/**
 * @brief Public search method.
 * 
 * @param word Word to search
 * @return true Return true if exists
 * @return false Return false if not
 */
bool TrieTree::search(string word){
    return search(this->root, to_lower(word));

}

/**
 * @brief Public remove method.
 * 
 * @param word Word to remove
 */
void TrieTree::remove(string word){
    return remove(this->root, to_lower(word));
}
