#include "warehouse.h"



using namespace std;

warehouse::warehouse(){

}

warehouse::warehouse(string fName){
    // Read from the file and make a vector of order objects
    RadixSort rSort;
    ifstream inFile(fName);
    string currLine;
    this->orders = vector<Order*>();
    while(getline(inFile, currLine)){
        istringstream ss(currLine);
        string clientName, name;
        string orderId, orderSize;
        ss >> name;
        clientName = name;
        ss >> name;
        clientName += " " + name;
        ss >> orderId >> orderSize;
        // Check the entire vector to ensure the order ID does not already exist
        Bloom* bloom = new Bloom (this->orders);
        bool exists = false;
        for(Order* curr : this->orders){
            if(bloom->search(curr)){
                exists = true;
                break;
            }
        }
        // If the order ID doesn't already exist, then create a new order object and push to orders vector
        if(!exists){
            Order* newOrder = new Order(orderId, orderSize, clientName);
            this->orders.push_back(newOrder);
            // Insert the new order into the bloom filter
            bloom->insert(newOrder);
        }
    }
    TrieTree idunno;
    idunno.insert("Hello");
    cout << idunno.search("Hello") << endl;
    idunno.remove("Hello");
    cout << idunno.search("Hello") << endl;
  
    //Sort orders by order size
    this->orders = rSort.radixSort(orders);
    printVector();
}

void warehouse::printVector(){
    for(Order* curr : this->orders){
        cout << "Name:       " << curr->clientName << endl;
        cout << "OrderID:    " << curr->orderId << endl;
        cout << "Order Size: " << curr->orderSize << endl;
        cout << "__________________________________________" << endl;
    }
}