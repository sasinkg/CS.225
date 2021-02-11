---

This report was generated for **sasinkg2** using **724f7386f335af71f3a48cec44adba8dd3b3d655** (latest commit as of **February 8th 2021, 12:00 am**)

---




## Score: 5/8 (62.50%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/catch/catchmain.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests-part1.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests-part2.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/PNG.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/HSLAPixel.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/lodepng/lodepng.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic lab_intro.cpp
clang++ catchmain.o tests-part1.o tests-part2.o PNG.o HSLAPixel.o lodepng.o lab_intro.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o test

```


### ✗ - [0/1] - HSLAPixel's default constructor creates a white pixel

- **Points**: 0 / 1


```
Original: pixel.l == 1
Expanded: 0.0 == 1
```


### ✗ - [0/1] - HSLAPixel's default constructor creates an opaque pixel

- **Points**: 0 / 1


```
Original: pixel.a == 1
Expanded: 0.0 == 1
```


### ✓ - [1/1] - HSLAPixel's HSL constructor creates a pixel with provided HSL values

- **Points**: 1 / 1





### ✗ - [0/1] - HSLAPixel's HSL constructor creates an opaque pixel

- **Points**: 0 / 1


```
Original: pixel.a == 1
Expanded: 0.0 == 1
```


### ✓ - [1/1] - HSLAPixel's HSLA constructor creates a pixel with provided HSLA values

- **Points**: 1 / 1





### ✓ - [1/1] - createSpotlight

- **Points**: 1 / 1





### ✓ - [1/1] - illinify

- **Points**: 1 / 1





### ✓ - [1/1] - watermark

- **Points**: 1 / 1





---