#include "warehouse.h"
#include "order.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

warehouse::warehouse(){

}

warehouse::warehouse(string fName){
    // Read from the file and make a vector of order objects
    ifstream inFile(fName);
    string currLine;
    while(getline(inFile, currLine)){
        stringstream ss(currLine);
        string clientName;
        int orderId, orderSize;
        ss >> clientName >> orderId >> orderSize;
        Order newOrder(orderId, orderSize, clientName);
        this->orders.push_back(newOrder);
    }
}