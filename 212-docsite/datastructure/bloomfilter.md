# Bloom Filter

We use a bloom filter to search for duplicate Order ID numbers before we insert a new order into the table. This data structure can produce false positive results, but will never produce a false negative. It is also memory efficient and all of its functions (hash, search, insert) run in constant time.
