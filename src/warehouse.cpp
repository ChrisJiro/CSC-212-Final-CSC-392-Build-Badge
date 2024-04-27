#include "warehouse.h"

/**
 * @brief Construct a new warehouse::warehouse object as empty
 */
warehouse::warehouse(){
}

/**
 * @brief Construct a new warehouse::warehouse object and call driver code to populate with orders from file
 * 
 * Here we insantiate our Radix Sort class, Bloom Filter class, Trie class, and Order class. We open and read line by line from our file
 * to find the amount of orders as fileSize. Afterwards, by utilizing the Bloom Filter to negate potential duplicates, we read through the file.
 * As we read through the file, we parse each line and store within a new Order object that holds the clients name, order number, and order size.
 * Next we populate our Trie Tree with all names from all orders. We do this for quick look ups of customers. We then prompt the user whetehr they
 * would like to perform said look up, or sort the orders by size of the order.
 * 
 * @param fName 
 */
warehouse::warehouse(string fName){
    //Create an instance of Radix Sort, call it rSort.
    RadixSort rSort;

    //Read from input file
    ifstream inFile(fName);
    int fileSize = 0;
    string currLine;
    this->orders = vector<Order*>();

    //Get size of text file by line, call it fileSize.
    while(getline(inFile, currLine)) {
        fileSize += 1;
    }
    inFile.close();

    //Create an instance of Bloom, call it bFilter that takes in the fileSize.
    Bloom bFilter(fileSize);

    //Read from input file, again.
    ifstream inFile2(fName);

    //While reading, parse each line and store client name, order number, and order size into an Order* called newOrder.
    while(getline(inFile2, currLine)){
        istringstream ss(currLine);
        string clientName, name;
        string orderId, orderSize;
        ss >> name;
        clientName = name;
        ss >> name;
        clientName += " " + name;
        ss >> orderId >> orderSize;
        //Create an Order* of newOrder set equal to a newly created order where the Id, size, and name are passed.
        Order* newOrder = new Order(orderId, orderSize, clientName);

        //Check the entire vector to ensure the order ID does not already exist.
        bool exists = false;
        if(bFilter.search(newOrder)){
            exists = true;
        }

        //If the order ID doesn't already exist, then create a new order object and push to orders vector.
        if(!exists){
            this->orders.push_back(newOrder);
            //Insert the new order into the bloom filter.
            bFilter.insert(newOrder);
        }
    }
    
    //Create an instance of TrieTree and call it trie.
    TrieTree trie;

    //Insert all names in all orders to trie tree.
    for(Order* curr : this->orders){
        trie.insert(curr->clientName);
    }
  
    //Prompt user for operation they'd like to perform.
    cout << "Select operation to perform: "<< endl;
    cout << "1 = search (By Name)" << endl;
    cout << "2 = Print orders from least to greatest" << endl;
    cout << "Operation: ";

    //Initialize and read in users command.
    int command;
    cin >> command;
    cout << endl;

    //If command 1 is chosen, the user would like to see if a customers order exists within the system. To do this enter in 1 line as 2 words.
    //"(First name) (Last name)" i.e: Sarah Brown.
    if(command == 1){
        cout << "Enter name: ";
        string searchName, temp;
        cin >> searchName;
        cin >> temp;
        searchName += " " + temp;

        //Check to see if name exists within the Trie Tree.
        if(trie.search(searchName)){
            cout << searchName << " exists" << endl;
        }

        //Print statement for if does not exist.
        else{
            cout << searchName << " was not found" << endl;
        }
    }

    //If command 2 is chosen, the user would like to see the orders sorted by size order. 
    else if(command == 2){
        //Sort orders by order size
        this->orders = rSort.radixSort(orders);
        
        //Call printVector to view the sorted database.
        printVector();
    }

    //If not 1 or 2 chosen, throw an error message.
    else {
        cout << "Invalid Operation" << endl;
    }
    inFile2.close();

    //Delete Bloom Filter at end of this run.
    delete &bFilter;
}

/**
 * @brief Print the database of orders
 */
void warehouse::printVector(){
    for(Order* curr : this->orders){
        cout << "Name:       " << curr->clientName << endl;
        cout << "OrderID:    " << curr->orderId << endl;
        cout << "Order Size: " << curr->orderSize << endl;
        cout << "__________________________________________" << endl;
    }
}
