#pragma once;

//Creating order objects to hold order number, client name, and number of items in order
#include <string>

using namespace std;

class Order{
    private:
        int orderId;
        int orderSize;
        string clientName;

        friend class warehouse;
    public:
        Order();
        Order(int orderId);
        Order(int orderId, int orderSize);
        Order(int orderId, int orderSize, string clientName);
        ~Order();
};