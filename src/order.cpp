#include "order.h"

Order::Order(){
    this->orderId = 0;
    this->orderSize = 0;
    this->clientName = "";
}

Order::Order(int orderId){
    this->orderId = orderId;
    this->orderSize = 0;
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