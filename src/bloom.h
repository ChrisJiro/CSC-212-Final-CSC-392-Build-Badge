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
        vector<int> table;

        int hash(Order* order); //method to calculate hash value from order
        void insert(Order* order); //method to insert an order into the hash table
        bool search(Order* order); //method to search for the order in the vector of orders
        void reset(); //method to reset the hash table


        friend class warehouse;

    public:
        Bloom();
        Bloom(vector<Order*> orders);
        



};