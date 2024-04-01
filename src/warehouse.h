#include "order.h"
#include <vector>

using namespace std;

class warehouse{
    private:
        vector<Order> orders;
    public:
    // Create Orders
    warehouse();
    warehouse(string fName);
};