#include "warehouse.h"

/**
 * @brief Main method to call upon warehouse driver code.
 * 
 * @param argc The number of CLAs
 * @param argv The array of CLAs
 * @return int Return 0 to successfully complete program
 */
int main(int argc, char *argv[]){
    //CLA format is: (.exe) (Input file (data))
    string fName = argv[1];

    //orders.txt is Names, Order ID, Number of Items
    warehouse myWarehouse(fName);
    //Return 0 to successfully complete program
    return 0;
}
