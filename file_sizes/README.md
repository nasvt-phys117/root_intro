# Size of root file

This program calculates the size of the different branches of a rootfile. See the root file for the TTree structure.

In detail the code does the following:

- Calculates sizes
- Adds together **blocks** of the same prefix (en, mn, mc, etc... )
- Calculates the size per event for each block
- Prints them in a table

- Latest addition: get the 4 highest consumers in each block.


*The code for getting sizes is heavily inspired by [this tutorial](https://root.cern/doc/master/printSizes_8C.html).*
