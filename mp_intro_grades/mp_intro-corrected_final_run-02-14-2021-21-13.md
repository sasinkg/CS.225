---

This report was generated for **sasinkg2** using **ef353c40b54232b5578dc7fab0802d54a1538c34** (latest commit as of **February 8th 2021, 11:59 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
intro.cpp:30:25: error: use of undeclared identifier 'sqrt'
      double distance = sqrt((width-x/2)*(width-x/2)+(height-y/2)*(height-y/2));
                        ^
intro.cpp:31:28: error: use of undeclared identifier 'sqrt'
      double maxDistance = sqrt((height/2)*(height/2)+(width/2)*(width/2));
                           ^
2 errors generated.
make: *** [intro.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/PNG.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/HSLAPixel.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/lodepng/lodepng.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic main.cpp intro.cpp

```


---