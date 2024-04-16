#include "bloom.h"

//Default constructor
Bloom::Bloom(){
    
}

//Constructor with Order object
Bloom::Bloom(vector<Order*> orders){
    this->orders = orders;
    this->table = vector<int>();
}

//Private methods

//Method to calculate hash value from order
int Bloom::hash(Order* currOrder){
    //mod the order id by the size of the vector of orders
    return stoi(currOrder->orderId) % this->orders.size();
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
    //loop through the hash table
    for(int i = 0; i < table.size(); i++){
        //if the index with this hash value is marked with a 1, then the order is most likely in the table
        if(this->table[i] == 1){
            return true;
        }
    }
    //if the index with this hash value is not found, the order is definitely not in the table
    return false;
}

//Method to reset the hash table 
void Bloom::reset(){
    //loop through the hash table and set all values to 0
    for(int i = 0; i < this->orders.size(); i++){
        this->table[i] = 0;
    }
}