## Timer for SYSU-IARC Tutorial Project
* Author: Lam
* Revised: Lam
* Version: 1.0.0
* Date: 2018-10-06
* Abstract: The `picop.cpp` is my test file, which is the base of the make-version timer. System control it through some `if...` and `sleep`, and it can run properly. However, I can't `make` through `main.cpp` `timer.cpp` `timer.h`, which are consist of the make-version timer. So I can't judge whether they are correct.
***
**Required**

For `Unix/Linux`:
* gcc >= 3.0
* opencv >= 3.0.0
***
**Usage**

* Since it doesn't have a proper Makefile, it can't be compile properly.
* The following output is come from my test file `picop.cpp`.
```
#compile  
g++ picop.cpp `pkg-config opencv --cflags --libs`  -lpthread  
#run  
./a.out
```
***
**Expected Output**  
[Output](output.png )
