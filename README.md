# queue

Queue implementation with simple test threads writing to the queue and reading from.

# Building
CMake is used for generating makefiles. You can using shell scripts for building, cleaning and running program instead.

# Running
The test directory contains a text file that can be used as the input. Data are read from standard input so chain has to be created
```
 cat test/testfile.txt | build/testapp/testapp
````
 
