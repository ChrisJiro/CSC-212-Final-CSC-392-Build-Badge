#pragma once
//basic searches 
//checks for 
using namespace std;
#include <string>
#include <vector>
#include "order.h"

class Bloom{
    private:
        vector<Order*> orders;

        int hash(Order* order); //function to calculate hash value from order
        void findDuplicates(Order* order);

        void insert(Order* order); 
        bool search(Order* order); //function to search for the order in the vector of orders
        void deleteOrder(Order* order); //function to delete the order from the vector of orders


    friend class Order;
    friend class warehouse;

    public:
        Bloom();
        Bloom(vector<Order*> orders);
        



};