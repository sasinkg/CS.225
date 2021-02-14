---

This report was generated for **sasinkg2** using **724f7386f335af71f3a48cec44adba8dd3b3d655** (latest commit as of **February 8th 2021, 12:59 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from cs225/PNG.cpp:23:
cs225/PNG.h:87:5: error: unknown type name 'HSLAPixel'
    HSLAPixel & getPixel(unsigned int x, unsigned int y);
    ^
cs225/PNG.h:97:11: error: unknown type name 'HSLAPixel'
    const HSLAPixel & getPixel(unsigned int x, unsigned int y) const;
          ^
cs225/PNG.h:123:5: error: unknown type name 'HSLAPixel'
    HSLAPixel *imageData_;          /*< Array of pixels */
    ^
cs225/PNG.h:135:5: error: unknown type name 'HSLAPixel'
    HSLAPixel & _getPixelHelper(unsigned int x, unsigned int y) const;
    ^
cs225/PNG.cpp:35:22: error: unknown type name 'HSLAPixel'
    imageData_ = new HSLAPixel[width_ * height_];
                     ^
cs225/PNG.cpp:50:22: error: unknown type name 'HSLAPixel'
    imageData_ = new HSLAPixel[width * height];
                     ^
cs225/PNG.cpp:76:7: error: unknown type name 'HSLAPixel'
      HSLAPixel & p1 = imageData_[i];
      ^
cs225/PNG.cpp:77:7: error: unknown type name 'HSLAPixel'
      HSLAPixel & p2 = other.imageData_[i];
      ^
cs225/PNG.cpp:95:3: error: unknown type name 'HSLAPixel'
  HSLAPixel & PNG::_getPixelHelper(unsigned int x, unsigned int y) const {
  ^
cs225/PNG.cpp:120:3: error: unknown type name 'HSLAPixel'
  HSLAPixel & PNG::getPixel(unsigned int x, unsigned int y) { return _getPixelHelper(x,y); }
  ^
cs225/PNG.cpp:122:9: error: unknown type name 'HSLAPixel'
  const HSLAPixel & PNG::getPixel(unsigned int x, unsigned int y) const { return _getPixelHelper(x,y); }
        ^
cs225/PNG.cpp:134:22: error: unknown type name 'HSLAPixel'
    imageData_ = new HSLAPixel[width_ * height_];
                     ^
cs225/PNG.cpp:144:7: error: unknown type name 'HSLAPixel'
      HSLAPixel & pixel = imageData_[i/4];
      ^
cs225/PNG.cpp:191:5: error: unknown type name 'HSLAPixel'
    HSLAPixel * newImageData = new HSLAPixel[newWidth * newHeight];
    ^
cs225/PNG.cpp:191:36: error: unknown type name 'HSLAPixel'
    HSLAPixel * newImageData = new HSLAPixel[newWidth * newHeight];
                                   ^
cs225/PNG.cpp:198:11: error: unknown type name 'HSLAPixel'
          HSLAPixel & oldPixel = this->getPixel(x, y);
          ^
cs225/PNG.cpp:199:11: error: unknown type name 'HSLAPixel'
          HSLAPixel & newPixel = newImageData[ (x + (y * newWidth)) ];
          ^
cs225/PNG.cpp:220:15: error: unknown type name 'HSLAPixel'
        const HSLAPixel &pixel = png.getPixel(x, y);
              ^
18 errors generated.
make: *** [PNG.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/PNG.cpp

```


---