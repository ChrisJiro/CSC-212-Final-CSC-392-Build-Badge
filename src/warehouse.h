#include "order.h"
#include "trie.h"
#include "cctype"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "radixsort.h"

#pragma once

using namespace std;

class warehouse{
    private:
        vector<Order*> orders;
        friend class RadixSort;
    public:
        // Constructors
        warehouse();
        warehouse(string fName);

        // Public methods
        void printOrder(Order currOrder);
        void printVector();
};