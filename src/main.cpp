#include "warehouse.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Main to call upon warehouse driver code.
int main(int argc, char *argv[]){
    // CLA format is: (.exe) (Input file (data))
    string fName = argv[1];

    //orders.txt is Names, Order ID, Number of Items
    warehouse myWarehouse(fName);
    // myWarehouse.printVector();
}