#include "order.h"
#include "radixsort.h"
#include <vector>

using namespace std;

<<<<<<< HEAD
Order* RadixSort::findMax(vector<Order*> orders) {
    Order* maxOrder = orders[0];
    for (Order* currOrder : orders) {
        if (stoi(currOrder->orderSize) > stoi(maxOrder->orderSize)) {
            maxOrder = currOrder;
        }
    }
    return maxOrder;
}

void RadixSort::countSort(vector<Order*> orders) {

}

vector<Order*> RadixSort::radixSort(vector<Order*> orders) {
    Order* largestOrder = findMax(orders);
    string tempDigits = largestOrder->orderSize;
    int digits = tempDigits.size();

}
=======
int main(int argc, char *argv[]){
    cout << "hi uwu";
}
>>>>>>> f588daa (added hi)
