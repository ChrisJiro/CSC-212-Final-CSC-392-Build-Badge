#include "order.h"
#include "radixsort.h"

/**
 * @brief Construct a new Radix Sort:: Radix Sort object as empty
 */
RadixSort::RadixSort() {
}

// tag::findMax[]
/**
 * @brief Hi jason This method finds and returns the order of maximum size from a vector of Order*s
 * 
 * @param orders The vector of orders to be searched through
 * @return Order* The order of maximum size gets returned
 */
Order* RadixSort::findMax(vector<Order*> orders) {
    //Start at the first order.
    Order* maxOrder = orders[0];

    //Loop through each order in the vector.
    for (Order* currOrder : orders) {
        //Compare the current max to each next order to determine if swap should occur.
        if (stoi(currOrder->orderSize) > stoi(maxOrder->orderSize)) {
            //Swap if so.
            maxOrder = currOrder;
        }
    }
    return maxOrder;
}
// end::findMax[]

// tag::countSort[]
/**
 * @brief This method performs count sort on our vector of orders at our current passed in digit place. Sorting is stable as well.
 * 
 * @param orders The vector of orders to be sorted
 * @param place The current digit place in which to sort at
 */
void RadixSort::countSort(vector<Order*>& orders, int place) {
    //Create a vector of type Order* to store the output in.
    vector<Order*> output(orders.size());
    //Initialize countArray of 10 digits to 0 through 9. Radix sort only compares digit by digit, so only 0 through 9 are options.
    int countArray[10] ={0};
    //This for loop counts the occurances of each number 0-9 at the current place of each number in the vector.
    for (int i = 0; i < orders.size(); i++) {
        //To get the digit in the current place, dividing by the place we are on and modding by 10 extracts that digit into the count array.
        countArray[(stoi(orders[i]->orderSize) / place) % 10]++;
    }
    //This for loop adds occurance counts together.
    for (int i = 1; i < 10; i++) {
        countArray[i] += countArray[i - 1];
    }
    //This for loop sorts order into output.
    for (int i = orders.size() - 1; i >= 0; i--) {
        //Here we modify the output array at a certain index to be equal to index i within the order list.
        //We calculate the index by first calculating an index with the count array. We extract a digit as we did prior. 
        //We use this as the index for countArray. The return of this we subtract by one to find our index for output to set equal to orders[i].
        output[countArray[(stoi(orders[i]->orderSize) / place) % 10] - 1] = orders[i];
        //Here we decrement occurence count at a calculated index.
        countArray[(stoi(orders[i]->orderSize) / place) % 10]--;
    }
    //Here we make swaps in the original order vector.
    for (int i = 0; i < orders.size(); i++) {
        orders[i] = output[i];
    }
}
// end::countSort[]

// tag::radixSort[]
/**
 * @brief This method performs radix sort on our vector of orders. To do so, counting sort is called for an amount of iterations equal to the 
 * amount of digits within the max orders order size. We at each iteration move up a digit place.
 * 
 * @param orders The vector of orders to be sorted
 * @return vector<Order*> Return the sorted vector
 */
vector<Order*> RadixSort::radixSort(vector<Order*> orders) {
    //Obtain the max order.
    Order* largestOrder = findMax(orders);
    //For each digit place to sort, call count sort.
    for (int place = 1; stoi(largestOrder->orderSize) / place > 0; place *= 10) {
        //Count sort call.
        countSort(orders, place);
    }
    return orders;
}
// end::radixSort[]
