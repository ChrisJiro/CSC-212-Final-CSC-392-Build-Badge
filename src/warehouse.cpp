#include "warehouse.h"
#include "order.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

warehouse::warehouse(){
    vector<Order> orders;
}

warehouse::warehouse(string fName){
    vector<Order> orders;
    // Read from the file
    ifstream inFile(fName);
    string currLine;
    while(getline(inFile, currLine)){
        stringstream ss(currLine);
        string clientName;
        int orderId, orderSize;
        ss >>clientName >> orderId, orderSize;
        Order newOrder(orderId, orderSize,clientName);
        orders.push_back(newOrder);
    }
}