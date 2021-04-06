---

This report was generated for **sasinkg2** using **3759d64a1793a5fc45775ea2ce6692f326686555** (latest commit as of **April 5th 2021, 9:41 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from FloodFilledImage.cpp:6:
./imageTraversal/ImageTraversal.h:50:23: fatal error: implicit instantiation of undefined template 'std::__1::vector<int, std::__1::allocator<int> >'
    std::vector <int> visit;
                      ^
/usr/local/bin/../include/c++/v1/iosfwd:200:28: note: template is declared here
class _LIBCPP_TEMPLATE_VIS vector;
                           ^
1 error generated.
make: *** [.objs/FloodFilledImage.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Point.cpp -o .objs/Point.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c FloodFilledImage.cpp -o .objs/FloodFilledImage.o

```


---