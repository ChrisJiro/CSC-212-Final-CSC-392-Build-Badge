#include "bloom.h"

//Default constructor
Bloom::Bloom(){
}

//Constructor with Order object
Bloom::Bloom(int fileSize){
    int tableSize = -(fileSize * log(0.01)) / (log(2) * log(2));
    tableSize = ceil(tableSize);
    this->table = vector<bool>(tableSize, 0);
}

//Private methods

//Method to calculate hash value from order
int Bloom::hash(Order* currOrder){
    double h1 = stod(currOrder->orderId);
    double h2 = stod(currOrder->orderSize);
    //mod the order id by the size of the vector of orders
    return fmod(h1, h2);
}

//Method to insert an order into the hash table
void Bloom::insert(Order* order){
    //If the order is not already in the vector, then add it
    if(!search(order)){
        //hash the value
        int index = hash(order);
        //insert a 1 into the table at the index
        this->table[index] = 1;
    }
}

//Method to check if an order is already in the vector of orders
bool Bloom::search(Order* order){
    // cout << "Checking " << order->clientName << endl;
    //if the table is not empty, continue
    if(this->table.size() != 0){
        //get hash value of the order
        int index = hash(order);
        //check if the index is already marked with a 1
        if(this->table[index] == 1){
            // cout << order->clientName << " hashes to value: " << index << endl;
            return true;
        }
    }
    //if the index with this hash value is a 0, the order is definitely not in the table
    return false;
}