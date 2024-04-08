#include "order.h"
#include "warehouse.h"
#include <vector>

using namespace std;

class RadixSort{
    private:

    public:
        //Necessary methods
        Order* findMax(vector<Order*> orders);
        void countSort(vector<Order*> orders);
        vector<Order*> radixSort(vector<Order*> orders);

};