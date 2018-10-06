## Timer for SYSU-IARC Tutorial Project
* Author: Lam
* Revised: Lam
* Version: 1.0.0
* Date: 2018-10-06
* Abstract: Code for a timer.
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
[Output](backup/LAM林建乐/2_week/timer_exercise/output.png )
