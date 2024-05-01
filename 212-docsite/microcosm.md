# Microcosm

An introduction to our CSC-212 Final Project.

## Overview

In the modern era, every company specializing in sales of any kind is compelled to manage its orders in a systematic and efficient manner. This necessity stems from the fundamental desire to ensure customer satisfaction, streamline operations, and ultimately, drive growth. 

Our group has made an effort to address this, and with such we have developed a database system. Our goal is to enhance a hypothetical company’s operational efficiency. It would serve as the backbone of their order management process. Our hopes would be for it to provide a clear, organized view of the customers within the system, their orders, and to ensure that issues will not occur often, if at all.

With these goals in mind, we have succeeded in constructing a database capable of filtering out potential duplicate orders, checking whether a customer already exists within the database based solely off their name, and the ability to sort each order based on size from least to greatest. 

## Indepth

We attempted to make our interface as user-friendly as possible for managing customer orders. Users should start by create a text file in a specific, easy-to-follow format. Each line of this file *should* represent a **unique** customer and their order information. The line should proceed as follows:

<p align="center">
Customer Name, Order Number, Order Size
</p>

As previously stated we are able to handle duplicates within our database, but for the sake of efficiency it is best to avoid repeat customers.

Users have the choice to either download the entire codebase from our GitHub Repository or simply download the executable file. The second option will allow for users to use command line arguments to specify the path to their order file. This ensures that users can choose the method that best suits their technical comfort level, and specific needs.

Our program reads each line of the text file, constructing our database one customer at a time. This approach ensures accuracy and completeness in the data transfer process.

Upon successful construction of the database, users can perform two operations currently, as per their requirements. These include checking to see whether or not a customer exists within the database, and sorting based on order size.

In essence, our program is not just a tool, but a solution with the goal to be a simple, yet effective, order management process. 
