---

This report was generated for **sasinkg2** using **a11245e8ae89b7cce1785908c4dbfd26e328962f** (latest commit as of **March 8th 2021, 3:06 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from tests/tests_part2.cpp:2:
In file included from tests/tests_helper.h:5:
In file included from tests/../List.h:305:
tests/../List.hpp:510:1: fatal error: control reaches end of non-void function [-Wreturn-type]
}
^
tests/../List.hpp:377:14: note: in instantiation of member function 'List<cs225::HSLAPixel>::merge' requested here
     head_ = merge(head_, otherList.head_);
             ^
tests/tests_part2.cpp:77:6: note: in instantiation of member function 'List<cs225::HSLAPixel>::mergeWith' requested here
  l1.mergeWith(l2);
     ^
1 error generated.
make: *** [.objs/tests/tests_part2.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o

```


---