# Data Structures and Abstractions Utilized

With our primary goals being database speed efficiency, we found it best to make implementations of Bloom Filter, Trie, and Radix Sort. The following will best explain why we chose each data structure.

## Bloom Filter

For our project, we implemented Bloom Filter. We eventually chose Bloom Filters due to their memory efficiency. Bloom Filters, while not exactly hash tables, use hash functions to represent set membership, which we found useful for checking duplicate orders by order ID in their warehouse database. A unique property of Bloom Filters is that elements cannot be removed, aligning with our need for a running list of orders that can’t be deleted once placed. With Bloom Filters, false positives for existance can occur but is not a problem for us as we now completely negate the possiblity of false negatives. This is how we rule out duplicates.

## Trie

For our project, we also implemented a Trie. This decision was driven by our desire for efficiency and speed in our database. The Trie structure, with its ability to reuse characters added into the tree, reduces the number of nodes, making it particularly efficient for large datasets.

## Radix Sort

For our project, we lastly implemented Radix Sort. As a non-comparative sorting algorithm, Radix Sort excels with large datasets. It organizes data based on the digit place in the number, specifically the largest number’s digit count. Radix Sort utilizes a modified Count Sort to perform the actual necessary swaps, which is where it derives it's stability and non-comparative characteristics from. 

## Driver Code

The program employs a driver class responsible for reading from the file supplied at runtime and invoking the other data structure classes. It maintains a vector composed of order objects. Each of these order objects contains the buyer’s name, the order ID, and the quantity of their order.
