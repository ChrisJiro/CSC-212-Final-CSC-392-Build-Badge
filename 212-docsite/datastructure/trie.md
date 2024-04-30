# Trie

The trie implementation is used to check whether customers orders already exist within the database, and interacts accordingly to whether or not they do. Three methods are used: insert, search, remove.

## insert Explained

This method takes a string and checks if each character exists in the Trie at the correct height. If not, a new node with that character is inserted. After the string is inserted, a child node is created at the last character and marked as a word.

### insert Implementation
```{literalinclude} ../../src/trie.cpp
:start-after: tag::insert[]
:end-before: end::insert[]
```

## search Explained

This method checks if a word exists in the Trie. It iterates through each character from the start of the word and compares it with the letter in the Trie. If the word is in the Trie, it returns 1, otherwise, it returns 0. This method utilizes recursion.

### search Implementation
```{literalinclude} ../../src/trie.cpp
:start-after: tag::search[]
:end-before: end::search[]
```

## remove Explained

This method navigates to the end of the word and marks the boolean as false, indicating the end of a word. If there are no children after the node, the child node is deleted. If there are children, as in the case of ‘jack’ and ‘jackson’, the node is left and the boolean is marked as false.

### remove Implementation
```{literalinclude} ../../src/trie.cpp
:start-after: tag::remove[]
:end-before: end::remove[]
```
