#include <iostream>
#include <string>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"

using namespace std;

    void Image::lighten() {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                CS225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l <= 0.9) {
                    pixel.l = pixel.l + 0.1; 
                } else if (pixel > 0.9) {
                    pixel.l = 1;
                }
            }
        }
    }
    void Image::lighten(double amount) {
        for (unsigned i = 0; i < width(); i++) {
                    for (unsigned j = 0; j < height(); j++) {
                        CS225::HSLAPixel & pixel = getPixel(i,j);
                        if (pixel.l + amount <= 1) {
                            pixel.l = pixel.l + amount; 
                        } else if (pixel + amount > 1) {
                            pixel.l = 1;
                        }
                    }
                }
    }
    void Image::darken() {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                CS225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l - 0.1 < 0) {
                    pixel.l = 1; 
                } else {
                    pixel.l = pixel.l - 0.1;
                }
            }
        }
    }
    void Image::darken(double amount) {
        for (unsigned i = 0; i < width(); i++) {
            for (unsigned j = 0; j < height(); j++) {
                CS225::HSLAPixel & pixel = getPixel(i,j);
                if (pixel.l - amount < 0) {
                    pixel.l = 1; 
                } else {
                    pixel.l = pixel.l - amount;
                }
            }
        }
    }
    void Image::saturate() {
        
    }
    void Image::saturate(double amount) {

    }
    void Image::desaturate(){

    }
    void Image::desaturate(double amount) {

    }
    void Image::scale(double factor) {

    } 
    void Image::(unsigned w, unsigned h) {

    }
    void Image::illinify() {

    }
    void Image::grayScale() {

    } 
    void Image::rotateColor() {

    }