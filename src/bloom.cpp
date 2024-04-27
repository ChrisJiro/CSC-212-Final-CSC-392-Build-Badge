#include "bloom.h"

/**
 * @brief Construct a new Bloom:: Bloom object as empty
 */
Bloom::Bloom(){
}

/**
 * @brief Construct a new Bloom:: Bloom object with a specified file size. The file size will be used in a calculation to determine what the table
 * size should be. The table of this new size will be then populated with zeros to simulate a bit array.
 * 
 * @param fileSize The size of the file in which to calculate the table size with
 */
Bloom::Bloom(int fileSize){
    //tableSize is set equal to the below equation. Within the first log, changing the decimal value changes the amount of acceptable false
    //positives. i.e: log(0.01) equates to an acceptance of 99.99% accurate. log(1) would in theory be just 99% accurate.
    int tableSize = -(fileSize * log(0.01)) / (log(2) * log(2));
    //Round the table size up.
    tableSize = ceil(tableSize);
    //Make the table equal to tableSize populated with zeros.
    this->table = vector<bool>(tableSize, 0);
}

/**
 * @brief This method calculates and returns the hash value of the current order. This is done by using fmod to perform modulus on h1,
 * where h1 is the orderId and h2 where it is the orderSize. 
 * 
 * @param currOrder The current order in which to hash
 * @return int The hash value of the current order
 */
int Bloom::hash(Order* currOrder){
    double h1 = stod(currOrder->orderId);
    double h2 = stod(currOrder->orderSize);
    //Mod the order id by the size of the order.
    return fmod(h1, h2);
}

/**
 * @brief This method inserts an order into the bloom filter at its hash value. 
 * 
 * @param order The order in which to be inserted
 */
void Bloom::insert(Order* order){
    //If the order is not already in the vector, then add it.
    if(!search(order)){
        //Hash the value.
        int index = hash(order);
        //Insert a 1 into the table at the index.
        this->table[index] = 1;
    }
}

/**
 * @brief This method searches through the bloom filter to see whether the current order already exists. It does so by checking the hash value and
 * seeing if the bit array at said hash value is already 1.
 * 
 * @param order The current order to be searched for
 * @return true Return true if order is found
 * @return false Return false if order is not found
 */
bool Bloom::search(Order* order){
    //If the table is not empty, continue.
    if(this->table.size() != 0){
        //Get hash value of the order.
        int index = hash(order);
        //Check if index in bit array is 1, if so print message.
        if(this->table[index] == 1){
            cout << "____________________________________________________" << endl << endl;
            cout << order->clientName << "'s order hashes to existing index: " << index << endl;
            cout << "____________________________________________________" << endl;
            return true;
        }
    }
    //if the index with this hash value is a 0, the order is definitely not in the table.
    return false;
}
