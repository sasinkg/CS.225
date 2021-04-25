---

This report was generated for **sasinkg2** using **7e61f2e3f4b5b35ea14f0c14bedd39ccd2d4c336** (latest commit as of **April 25th 2021, 2:56 pm**)

---




## Score: 64/150 (42.67%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c hashes.cpp -o .objs/hashes.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c textfile.cpp -o .objs/textfile.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-dh.cpp -o .objs/tests/tests-dh.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-sc.cpp -o .objs/tests/tests-sc.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-lp.cpp -o .objs/tests/tests-lp.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/hashes.o .objs/textfile.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-dh.o .objs/tests/tests-sc.o .objs/tests/tests-lp.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✗ - [0/6] - DH::testRemoveEASY

- **Points**: 0 / 6


```
FAIL: Insert did not work
```


### ✗ - [0/10] - DH::testRemoveHard

- **Points**: 0 / 10


```
FAIL: Insert did not work
```


### ✗ - [0/7] - DH::testResizeOnce

- **Points**: 0 / 7


```
Original: hashTable.tableSize() >= val / 0.7
Expanded: 17 >= 122.8571428571
```


### ✗ - [0/11] - DH::testResizeAll

- **Points**: 0 / 11


```
Original: hashTable.tableSize() >= strings.size() / 0.7
Expanded: 17 >= 37.1428571429
```


### ✗ - [0/6] - DH::testInsertEasy

- **Points**: 0 / 6


```
FAIL: Did not insert key: 'all'
```


### ✗ - [0/10] - DH::testInsertHard

- **Points**: 0 / 10


```
FAIL: Did not insert properly key: 'has'
```


### ✓ - [6/6] - SC::testRemoveEASY

- **Points**: 6 / 6

```
==81== Memcheck, a memory error detector
==81== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==81== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==81== Command: ./test -r xml "SC::testRemoveEASY"
==81== 
==81== 
==81== HEAP SUMMARY:
==81==     in use at exit: 0 bytes in 0 blocks
==81==   total heap usage: 1,855 allocs, 1,855 frees, 241,392 bytes allocated
==81== 
==81== All heap blocks were freed -- no leaks are possible
==81== 
==81== For counts of detected and suppressed errors, rerun with: -v
==81== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - SC::testRemoveHard

- **Points**: 10 / 10

```
==83== Memcheck, a memory error detector
==83== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==83== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==83== Command: ./test -r xml "SC::testRemoveHard"
==83== 
==83== 
==83== HEAP SUMMARY:
==83==     in use at exit: 0 bytes in 0 blocks
==83==   total heap usage: 1,877 allocs, 1,877 frees, 242,272 bytes allocated
==83== 
==83== All heap blocks were freed -- no leaks are possible
==83== 
==83== For counts of detected and suppressed errors, rerun with: -v
==83== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/7] - SC::testResizeOnce

- **Points**: 0 / 7


```
Original: hashTable.tableSize() >= val / 0.7
Expanded: 17 >= 64.2857142857
```


### ✗ - [0/11] - SC::testResizeAll

- **Points**: 0 / 11


```
Original: hashTable.tableSize() >= strings.size() / 0.7
Expanded: 17 >= 37.1428571429
```


### ✓ - [6/6] - SC::testInsertEasy

- **Points**: 6 / 6

```
==87== Memcheck, a memory error detector
==87== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==87== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==87== Command: ./test -r xml "SC::testInsertEasy"
==87== 
==87== 
==87== HEAP SUMMARY:
==87==     in use at exit: 0 bytes in 0 blocks
==87==   total heap usage: 1,854 allocs, 1,854 frees, 241,344 bytes allocated
==87== 
==87== All heap blocks were freed -- no leaks are possible
==87== 
==87== For counts of detected and suppressed errors, rerun with: -v
==87== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - SC::testInsertHard

- **Points**: 10 / 10

```
==89== Memcheck, a memory error detector
==89== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==89== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==89== Command: ./test -r xml "SC::testInsertHard"
==89== 
==89== 
==89== HEAP SUMMARY:
==89==     in use at exit: 0 bytes in 0 blocks
==89==   total heap usage: 1,876 allocs, 1,876 frees, 242,224 bytes allocated
==89== 
==89== All heap blocks were freed -- no leaks are possible
==89== 
==89== For counts of detected and suppressed errors, rerun with: -v
==89== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [6/6] - LP::testRemoveEASY

- **Points**: 6 / 6

```
==91== Memcheck, a memory error detector
==91== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==91== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==91== Command: ./test -r xml "LP::testRemoveEASY"
==91== 
==91== 
==91== HEAP SUMMARY:
==91==     in use at exit: 0 bytes in 0 blocks
==91==   total heap usage: 1,856 allocs, 1,856 frees, 240,685 bytes allocated
==91== 
==91== All heap blocks were freed -- no leaks are possible
==91== 
==91== For counts of detected and suppressed errors, rerun with: -v
==91== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - LP::testRemoveHard

- **Points**: 10 / 10

```
==93== Memcheck, a memory error detector
==93== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==93== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==93== Command: ./test -r xml "LP::testRemoveHard"
==93== 
==93== 
==93== HEAP SUMMARY:
==93==     in use at exit: 0 bytes in 0 blocks
==93==   total heap usage: 1,878 allocs, 1,878 frees, 241,389 bytes allocated
==93== 
==93== All heap blocks were freed -- no leaks are possible
==93== 
==93== For counts of detected and suppressed errors, rerun with: -v
==93== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/7] - LP::testResizeOnce

- **Points**: 0 / 7

```
[Process timed out]
```
```
Error: Unable to read buffer.
```


### ✗ - [0/11] - LP::testResizeAll

- **Points**: 0 / 11

```
[Process timed out]
```
```
Error: Unable to read buffer.
```


### ✓ - [6/6] - LP::testInsertEasy

- **Points**: 6 / 6

```
==97== Memcheck, a memory error detector
==97== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==97== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==97== Command: ./test -r xml "LP::testInsertEasy"
==97== 
==97== 
==97== HEAP SUMMARY:
==97==     in use at exit: 0 bytes in 0 blocks
==97==   total heap usage: 1,855 allocs, 1,855 frees, 240,653 bytes allocated
==97== 
==97== All heap blocks were freed -- no leaks are possible
==97== 
==97== For counts of detected and suppressed errors, rerun with: -v
==97== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - LP::testInsertHard

- **Points**: 10 / 10

```
==99== Memcheck, a memory error detector
==99== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==99== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==99== Command: ./test -r xml "LP::testInsertHard"
==99== 
==99== 
==99== HEAP SUMMARY:
==99==     in use at exit: 0 bytes in 0 blocks
==99==   total heap usage: 1,877 allocs, 1,877 frees, 241,357 bytes allocated
==99== 
==99== All heap blocks were freed -- no leaks are possible
==99== 
==99== For counts of detected and suppressed errors, rerun with: -v
==99== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---