# Driver Code

The driver class is used to make necessary calls to necessary classes and their methods to create the database. Two methods are used: The actual driver method, and a print method for if sorting.

## Driver Explained

The driver method handles the reading from the file passed in at runtime, and calling the other data structure classes. It holds a vector of order objects. Each order object holds the customer name, order number, and order size.
Below we show how we read from, parse information, make calls to methods in other classes, and more.
### Driver Implementation

```{literalinclude} ../src/warehouse.cpp
:start-after: tag::driver[]
:end-before: end::driver[]
```

## Print Explained

The print method will print each method in a specific format that we find easily readable, though obviously the user can adjust to their specific needs.

### Print Implementation

```{literalinclude} ../src/warehouse.cpp
:start-after: tag::print[]
:end-before: end::print[]
```
