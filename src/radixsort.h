#include "order.h"
#include <vector>
#include <iostream>

using namespace std;

#pragma once

class RadixSort{
    private:
    public:
        RadixSort();
        //Necessary methods
        Order* findMax(vector<Order*> orders);
        void countSort(vector<Order*>& orders, int place);
        vector<Order*> radixSort(vector<Order*> orders);
};
