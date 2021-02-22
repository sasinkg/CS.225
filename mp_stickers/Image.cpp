#include <iostream>
#include <string>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"

using namespace std;

    void Image::lighten() {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l > 0.9) {
                    pixel.l = 1; 
                } else {
                    pixel.l += 0.1;
                }
            }
        }
    }
    void Image::lighten(double amount) {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l + amount <= 1) {
                    pixel.l += amount; 
                } else if (pixel.l + amount > 1) {
                      pixel.l = 1;
                }
            }
        }
    }
    void Image::darken() {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l - 0.1 < 0) {
                    pixel.l = 1; 
                } else {
                    pixel.l -= 0.1;
                }
            }
        }
    }
    void Image::darken(double amount) {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l - amount < 0) {
                    pixel.l = 1; 
                } else {
                    pixel.l -= amount;
                }
            }
        }
    }
    void Image::saturate() {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.s > 0.9) {
                    pixel.s = 1;
                } else {
                    pixel.s += 0.1;
                }
            }
        }
    }
    void Image::saturate(double amount) {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.s + amount > 0.9) {
                    pixel.s = 1; 
                } else {
                    pixel.s += amount;
                }
            }
        }
    }
    void Image::desaturate(){
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.s - 0.1 < 0) {
                    pixel.s = 1; 
                } else {
                    pixel.s -= 0.1;
                }
            }
        }
    }
    void Image::desaturate(double amount) {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                cs225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.s - amount < 0) {
                    pixel.s = 1; 
                } else {
                    pixel.s -= amount;
                }
            }
        }
    }
    void Image::scale(double factor) {
        unsigned  fwidth = factor * width();
        unsigned  fheight = factor * height();
        unsigned  decimal = 1/factor; 
        cs225::PNG * p1 = new cs225::PNG (fwidth, fheight);

        if (factor < 1) { 
           for (unsigned i = 0; i < width(); i++) {
                for (unsigned j = 0; j < height(); j++) {
                    cs225::HSLAPixel & pixel = getPixel(i,j);
                    for (unsigned a = 0; a < factor; a++) {
                        for (unsigned b = 0; b < factor; b++) {
                            
                            unsigned  d = a + i;
                            unsigned  e = b + j;
                            cs225::HSLAPixel & pixel2 = p1->getPixel(factor * d, factor * e);
                            pixel2 = pixel;
                        }   
                    }    
                }
            }    
            
        } else if (factor > 1) {
            for (unsigned i = 0; i < fwidth; i++) {
                for (unsigned j = 0; j < fheight; j++) {
                    cs225::HSLAPixel & pixel = getPixel(i / factor, j / factor);
                    cs225::HSLAPixel & pixel2 = p1->getPixel(i,j);
                    pixel2 = pixel;
                }
            }    
        } else {
            return;
        }
        
        resize(p1->width(), p1->height());

        for (unsigned f = 0; f < width(); f++) {
            for (unsigned g = 0; g < height(); g++) {
                cs225::HSLAPixel & pixel3 = getPixel(f,g);
                cs225::HSLAPixel & pixel4 = p1->getPixel(f,g);
                pixel3 = pixel4;
            }
        }
        delete p1;   
        
        
        
    } 
    void Image::scale(unsigned w, unsigned h) {
        unsigned  newWidth = w / width();
        unsigned  newHeight = h / height();
        if (newHeight < newWidth) {
            scale(newHeight);
        } else {
            scale (newWidth);
        }
    }
    void Image::illinify() {
        for (unsigned i = 0; i < width(); i++) {
                for (unsigned j = 0; j < height(); j++) {
                    cs225::HSLAPixel & pixel = getPixel(i,j);
                    if (pixel.h > 293 || pixel.h < 113) {
                        pixel.h  = 11;
                    } else {
                        pixel.h = 216;
                    }
            }
        }
    }
    void Image::grayScale() {
        for (unsigned i = 0; i < width(); i++){
			for (unsigned j = 0; j < height(); j++){		
				cs225::HSLAPixel & pixel = getPixel(i,j);
				pixel.s = 0;
			}
		}
    } 
    void Image::rotateColor(double degrees) {
        for (unsigned i = 0; i < width(); i++){
			for (unsigned j = 0; j < height(); j++){		
				cs225::HSLAPixel & pixel = getPixel(i,j);
				if (degrees > 0) {
                    pixel.h = (pixel.h + degrees) / 360;
                } else {
                    int rotate = (degrees * -1) / 360;
                    rotate++;  
                    pixel.h = (360 * rotate) + degrees + pixel.h;
                }
			}
		}
    }