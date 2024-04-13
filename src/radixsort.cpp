#include "order.h"
#include "radixsort.h"
#include <vector>

using namespace std;

RadixSort::RadixSort() {
}

//find max
Order* RadixSort::findMax(vector<Order*> orders) {
    Order* maxOrder = orders[0];
    for (Order* currOrder : orders) {
        if (stoi(currOrder->orderSize) > stoi(maxOrder->orderSize)) {
            maxOrder = currOrder;
        }
    }
    return maxOrder;
}

//count sort
void RadixSort::countSort(vector<Order*>& orders, int exp) {
    vector<Order*> output(orders.size());
    int i, count[10] = {0};

    for (i = 0; i < orders.size(); i++)
        count[(stoi(orders[i]->orderSize) / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = orders.size() - 1; i >= 0; i--) {
        output[count[(stoi(orders[i]->orderSize) / exp) % 10] - 1] = orders[i];
        count[(stoi(orders[i]->orderSize) / exp) % 10]--;
    }

    for (i = 0; i < orders.size(); i++)
        orders[i] = output[i];
}

//sort by radix
vector<Order*> RadixSort::radixSort(vector<Order*> orders) {
    Order* largestOrder = findMax(orders);
    int max = stoi(largestOrder->orderSize);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(orders, exp);

    return orders;
}
