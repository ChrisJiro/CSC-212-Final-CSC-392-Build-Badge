#include "order.h"

/**
 * @brief Construct a new Order:: Order object with default values for when nothing is passed in.
 */
Order::Order(){
    this->orderId = "-1";
    this->orderSize = "-1";
    this->clientName = "";
}

/**
 * @brief Construct a new Order:: Order object with defaults values, except for an order number being passed in.
 * 
 * @param orderId The order number being passed in
 */
Order::Order(string orderId){
    this->orderId = orderId;
    this->orderSize = "-1";
    this->clientName = "";
}

/**
 * @brief Construct a new Order:: Order object with default values, except for an order number and order size being passed in.
 * 
 * @param orderId The order number being passed in
 * @param orderSize The order size being passed in
 */
Order::Order(string orderId, string orderSize){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = "";
}

/**
 * @brief Construct a new Order:: Order object with order number, order size, and client name being passed in.
 * 
 * @param orderId The order number being passed in
 * @param orderSize The order size being passed in
 * @param clientName The client name being passed in
 */
Order::Order(string orderId, string orderSize, string clientName){
    this->orderId = orderId;
    this->orderSize = orderSize;
    this->clientName = clientName;
}

/**
 * @brief Destroy the Order:: Order object. Destructor is empty.
 */
Order::~Order(){
    // Keep empty!
}


