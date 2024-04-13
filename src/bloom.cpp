#include "bloom.h"

//focusing on handling duplicates
//

//Default constructor
Bloom::Bloom(){
    
}

//Constructor with Order object
Bloom::Bloom(vector<Order*> orders){
    this->orders = orders;
    
}



//Private methods

//Method to calculate hash value from order
int Bloom::hash(Order* order){

}


void Bloom::insert(Order* order){
    //If the order is not already in the vector, then add it
    if(!search(order)){
        this->orders.push_back(order);
    }
    //Collision handling
    else{
        //something
    }

}

//Method to check if an order is already in the vector of orders
bool Bloom::search(Order* order){
    bool found = false;
    for(Order* curr : this->orders){
        if(curr->orderId == order->orderId){
            found = true;
            break;
        }
    }
    return found;


}

//Method to delete an order from the vector
void Bloom::deleteOrder(Order* order){
    
    

}