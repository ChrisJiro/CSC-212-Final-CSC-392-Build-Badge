#include "warehouse.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Main to call upon warehouse driver code.
int main(int argc, char *argv[]){
    // CLA format is: (.exe) (Input file (data)) (function to perform)
    string fName = argv[1];

    // Below commented out to allow for future function implementation
    // string func = argv[2];

    //orders.txt is Names, Order ID, Number of Items
    warehouse myWarehouse(fName);
    // myWarehouse.printVector();
}