#include "warehouse.h"



using namespace std;

warehouse::warehouse(){

}

warehouse::warehouse(string fName){
    //Create an instance of Radix Sort, call it rSort
    RadixSort rSort;
    //Read from input file
    ifstream inFile(fName);
    int fileSize = 0;
    string currLine;
    this->orders = vector<Order*>();
    //Get size of text file by line, call it fileSize
    while(getline(inFile, currLine)) {
        fileSize += 1;
    }
    inFile.close();
    //Create an instance of Bloom, call it bFilter that takes in the fileSize
    Bloom bFilter(fileSize);
    //Read from input file, again
    ifstream inFile2(fName);
    while(getline(inFile2, currLine)){
        //While reading, parse into an Order* called newOrder
        istringstream ss(currLine);
        string clientName, name;
        string orderId, orderSize;
        ss >> name;
        clientName = name;
        ss >> name;
        clientName += " " + name;
        ss >> orderId >> orderSize;
        //Create an Order* of newOrder set equal to a newly created order where the Id, size, and name are passed
        Order* newOrder = new Order(orderId, orderSize, clientName);
        // Line below is for debugging purposes
        // cout << newOrder->clientName << " " << newOrder->orderId << " " << newOrder->orderSize << endl;
        // Check the entire vector to ensure the order ID does not already exist
        bool exists = false;
        if(bFilter.search(newOrder)){
            exists = true;
        }
        // If the order ID doesn't already exist, then create a new order object and push to orders vector
        if(!exists){
            this->orders.push_back(newOrder);
            // Insert the new order into the bloom filter
            bFilter.insert(newOrder);
        }
    }
  
    TrieTree trie;
    // Insert all names in all orders to trie tree
    for(Order* curr : this->orders){
        trie.insert(curr->clientName);
    }
  
    // Request operation
    cout << "Select operation to perform: "<< endl;
    cout << "1 = search (By Name)" << endl;
    cout << "2 = Print orders from least to greatest" << endl;
    cout << "Operation: ";
    int command;
    cin >> command;
    cout << endl;
    if(command == 1){
        cout << "Enter name: ";
        string searchName, temp;
        cin >> searchName;
        cin >> temp;
        searchName += " " + temp;
        if(trie.search(searchName)){
            cout << searchName << " exists" << endl;
        }
        else{
            cout << searchName << " was not found" << endl;
        }
    }
    else if(command == 2){
        // Sort orders by order size
        this->orders = rSort.radixSort(orders);
        printVector();
    }
    else{
        cout << "Invalid Operation" << endl;
    }
    inFile2.close();
}

void warehouse::printVector(){
    for(Order* curr : this->orders){
        cout << "Name:       " << curr->clientName << endl;
        cout << "OrderID:    " << curr->orderId << endl;
        cout << "Order Size: " << curr->orderSize << endl;
        cout << "__________________________________________" << endl;
    }
}