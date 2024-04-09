#include "order.h"

Order::Order(){
    this->orderId = -1;
    this->orderSize = -1;
    this->clientName = "";
}

Order::Order(int orderId){
    this->orderId = orderId;
    this->orderSize = -1;
    this->clientName = "";
}

Order::Order(int orderId, int orderSize){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = "";
}

Order::Order(int orderId, int orderSize, string clientName){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = clientName;
}

Order::~Order(){
    // Keep empty!
}


