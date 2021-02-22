/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once

#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace std;

class Image: public cs225::PNG {
    /* private:
        unsigned int xCor, yCor;
        int flag; */
    public:
        /* Image();
        Image(unsigned w, unsigned h); */
        
        void lighten();
        void lighten(double amount);
        
        void darken();
        void darken(double amount);

        void saturate();
        void saturate(double amount);

        void desaturate(); 
        void desaturate(double amount);

        void scale(double factor);
        void scale(unsigned w, unsigned h);


        void illinify();
        void grayScale();
        void rotateColor(double degrees);
        
        /* unsigned get
        int getFlag() const;
        void setFlag(int x); */
};
