# Examples

For those wanting to know what will and won't work.

## File Format

To ensure file functionality, we suggest only using **.txt** files as of this moment.

The contents of your files should be formatted as follows:

<p align="center">
Customer Name, Order Number, Order Size
</p>

Below is an example that our group used when testing:

```{literalinclude} ../Orders/orders.txt
```

Any other format *will* result in errors due to the way we parse the information from the files. For example:

<p align="center">
Customer Name, Order Size, Order Number
</p>

<p align="center">
Order Number, Order Size, Customer Name
</p>

<p align="center">
Order Size, Order Number, Customer Name
</p>

<p align="center">
Order Number, Customer Name, Order Size
</p>

<p align="center">
Order Size, Customer Name, Order Number
</p>

## Program Runs

Our program uses driver code that prompts the user to select an option. This could be 1 for checking whether a name exists, or 2 to sort the orders least to greatest by size. If utilizing our driver code,
only enter 1 or 2 as anything else will print our error message. Will update when implemented further.


