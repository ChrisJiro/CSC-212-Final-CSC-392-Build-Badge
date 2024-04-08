#include "order.h"

Order::Order(){
    this->orderId = -1;
    this->orderSize = -1;
    this->clientName = "";
}

Order::Order(string orderId){
    this->orderId = orderId;
    this->orderSize = -1;
    this->clientName = "";
}

Order::Order(string orderId, string orderSize){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = "";
}

Order::Order(string orderId, string orderSize, string clientName){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = clientName;
}

Order::~Order(){
    // Keep empty!
}