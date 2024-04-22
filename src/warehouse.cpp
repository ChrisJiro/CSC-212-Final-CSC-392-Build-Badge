#include "warehouse.h"



using namespace std;

warehouse::warehouse(){

}

warehouse::warehouse(string fName){
    // Read from the file and make a vector of order objects
    RadixSort rSort;
    ifstream inFile(fName);
    int fileSize = 0;
    string currLine;
    this->orders = vector<Order*>();
    // Get size of text file by line
    while(getline(inFile, currLine)) {
        fileSize += 1;
    }
    inFile.close();
    Bloom bFilter(fileSize);
    // Bloom* bloom = new Bloom (this->orders);
    ifstream inFile2(fName);
    while(getline(inFile2, currLine)){
        istringstream ss(currLine);
        string clientName, name;
        string orderId, orderSize;
        ss >> name;
        clientName = name;
        ss >> name;
        clientName += " " + name;
        ss >> orderId >> orderSize;
        Order* newOrder = new Order(orderId, orderSize, clientName);
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

    TrieTree idunno;
    idunno.insert("Hello");
    cout << idunno.search("Hello") << endl;
    idunno.remove("Hello");
    cout << idunno.search("Hello") << endl;
  
    // Sort orders by order size
    this->orders = rSort.radixSort(orders);
    printVector();
    inFile2.close();
}

void warehouse::printVector(){
    for(Order* curr : this->orders){
        cout << "Name:       " << curr->clientName << endl;
        cout << "OrderID:    " << curr->orderId << endl;
        cout << "Order Size: " << curr->orderSize << endl;
        cout << "__________________________________________" << endl;
    }
    cout << "End of print vector";
}