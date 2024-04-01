#include "order.h"
#include <vector>

using namespace std;

class warehouse{
    private:
        vector<Order*> orders;
    public:
        // Constructors
        warehouse();
        warehouse(string fName);

        // Public methods
        void printOrder(Order currOrder);
        void printVector();
};