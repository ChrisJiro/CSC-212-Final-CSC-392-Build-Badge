#pragma once
//basic searches 
//checks for 
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "order.h"

using namespace std;

class Bloom{
    private:
        vector<bool> table;

        int hash(Order* order); //method to calculate hash value from order
        void insert(Order* order); //method to insert an order into the hash table
        bool search(Order* order); //method to search for the order in the vector of orders

        friend class warehouse;

    public:
        Bloom();
        Bloom(int fileSize);
};