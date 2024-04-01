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
        string clientName, name;
        int orderId, orderSize;
        ss >> name;
        clientName = name;
        ss >> name;
        clientName += " " + name;
        ss >> orderId >> orderSize;
        Order* newOrder = new Order(orderId, orderSize, clientName);
        this->orders.push_back(newOrder);
    }

}

void warehouse::printVector(){
    for(Order* curr : this->orders){
        cout << "Name:       " << curr->clientName << endl;
        cout << "OrderID:    " << curr->orderId << endl;
        cout << "Order Size: " << curr->orderSize << endl;
    }
}