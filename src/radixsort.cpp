#include "order.h"
#include "radixsort.h"
#include <vector>
#include <iostream>

using namespace std;

RadixSort::RadixSort() {
}

/*
Find max
*/
Order* RadixSort::findMax(vector<Order*> orders) {
    Order* maxOrder = orders[0];
    //for loop in through order vector
    for (Order* currOrder : orders) {
        //max comparison
        if (stoi(currOrder->orderSize) > stoi(maxOrder->orderSize)) {
            //swap
            maxOrder = currOrder;
        }
    }
    return maxOrder;
}

/*
Count sort method
*/
void RadixSort::countSort(vector<Order*>& orders, int place) {
    //create a vector of type Order* to store the output in
    vector<Order*> output(orders.size());
    //initialize countArray of 10 digits to 0 through 9. Radix sort only compares digit by digit, so only 0 through 9 are options.
    int countArray[10] ={0};
    //This for loop counts the occurances of each number 0-9 at the current place of each number in the vector
    for (int i = 0; i < orders.size(); i++) {
        //to get the digit in the current place, dividing by the place we are on and modding by 10 extracts that digit into the count array.
        countArray[(stoi(orders[i]->orderSize) / place) % 10]++;
    }
    //This for loop adds occurance counts together
    for (int i = 1; i < 10; i++) {
        countArray[i] += countArray[i - 1];
    }
    //This for loop sorts order into output
    for (int i = orders.size() - 1; i >= 0; i--) {
        //Here we modify the output array at a certain index to be equal to index i within the order list
        //we calculate the index by first calculating an index with the count array. We extract a digit as we did prior. 
        //We use this as the index for countArray. The return of this we subtract by one to find our index for output to set equal to orders[i]
        output[countArray[(stoi(orders[i]->orderSize) / place) % 10] - 1] = orders[i];
        //Here we decrement occurence count at a calculated index
        countArray[(stoi(orders[i]->orderSize) / place) % 10]--;
    }
    //Here we make swaps in the original order vector
    for (int i = 0; i < orders.size(); i++) {
        orders[i] = output[i];
    }
}

/*
Radix sort method using Least significant digit
Calls findMax by passing in the vector populated by order objects. The return is set equal to the largestOrder which is of type Order*. 
Within the method we have a for loop that runs for a duration equal to the size of the largestOrder's orderSize as a string.
*/
vector<Order*> RadixSort::radixSort(vector<Order*> orders) {
    Order* largestOrder = findMax(orders);
    for (int place = 1; stoi(largestOrder->orderSize) / place > 0; place *= 10) {
        countSort(orders, place);
    }
    
    return orders;
}
