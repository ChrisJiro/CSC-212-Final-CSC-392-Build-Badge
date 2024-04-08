#include "order.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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