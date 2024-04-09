#include "order.h"
#include <vector>

#pragma once

using namespace std;

class RadixSort{
    private:

    public:
        RadixSort();
        //Necessary methods
        Order* findMax(vector<Order*> orders);
        void countSort(vector<Order*>& orders, int place);
        vector<Order*> radixSort(vector<Order*> orders);

};