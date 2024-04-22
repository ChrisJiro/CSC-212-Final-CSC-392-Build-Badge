# Database for Company Logicstics

## Team Members
- Jason Fopiano
- Ethan DeMelo
- Colleen Quinn
- Christian Lopez

## Project Overview
Our team has developed a database utilizing various data structures including radix sort, bloom filters, and trie trees. The goal was to create an efficient sorting algorithm for customer orders and implement features like customer lookups by name while avoiding duplicate order IDs.

## Research
We began our project with extensive research into the chosen data structures, understanding their background, use cases, properties, and operations. We then used this research to determine the best way to implement these data structures into our program.

## Implementation
The scaffolding of our project includes a GitHub repository setup for asynchronous collaboration. We've divided tasks among team members and created a driver class to handle command line arguments and process inputs from txt files.

### Radix Sort
We implemented a radix sort algorithm that can take in a size or the order. This algorithm uses a method to return the maximum value order size, uses a modified counting sort based on current digit place for each order, and radix sort driver code to iterate the counting sort for each digit place of the max order size.

### Bloom Filters
We implemented a bloom filter that can hash order ID values as well as insert, search, and reset within the table. The search algorithm checks for 
order IDs that already exist in the database.

### Trie
We implemented a trie tree capable of insertions, removals, and searches. Our insertion algorithm checks for existing characters at the correct height before adding new nodes. Utilizing recursive calls, we were able to achieve code that is much easier to read and understand.

## Goals
Our aim is to achieve efficiency in our database, keeping in mind the handling of large data entries as a future goal.
