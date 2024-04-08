#pragma once;

//Creating order objects to hold order number, client name, and number of items in order
#include <string>

using namespace std;

class Order{
    private:
        string orderId;
        string orderSize;
        string clientName;

        friend class warehouse;
        friend class RadixSort;
    public:
        Order();
        Order(string orderId);
        Order(string orderId, string orderSize);
        Order(string orderId, string orderSize, string clientName);
        ~Order();
};