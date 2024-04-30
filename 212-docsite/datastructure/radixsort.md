# Radix Sort
The radix sort implementation is used to sort a database of orders by order size. Three methods are used: findMax, countSort, and radixSort.

## findMax Explained
This method finds the order with the largest size in the database. It iterates through all orders, comparing each one to the current maximum. The order with the largest size is returned.

### findMax implementation:
```{literalinclude} ../../src/radixsort.cpp
:start-after: tag::findMax[]
:end-before: end::findMax[]
```

## countSort Explained
This method sorts the orders based on a specific digit place, for as many times as we have total digits in our max order and for each digit place within. It creates an output vector and a count array of size ten. The count array keeps track of the occurrence of each digit at the current place. The method then fills the output vector using the count array and finally, the original database is updated with the sorted orders.

### countSort implementation:
```{literalinclude} ../../src/radixsort.cpp
:start-after: tag::countSort[]
:end-before: end::countSort[]
```

## radixSort explained
This method sorts the orders. It first ascertains the largest order by calling findMax. Then, it calls countSort for each digit place of the largest order size, starting from the ones place and moving to the next digit place by multiplying the current place by ten.

### radixSort implementation:
```{literalinclude} ../../src/radixsort.cpp
:start-after: tag::radixSort[]
:end-before: end::radixSort[]
```
