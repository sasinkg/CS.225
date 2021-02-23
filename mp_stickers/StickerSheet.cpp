#include "StickerSheet.h"
#include "Image.h"
#include <iostream>
#include "math.h"
using namespace std;

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    pictures = new Image*[max + 1];
    xCor = new int[max + 1];
    yCor = new int[max + 1];

    pictures[0] = new Image(picture);
    xCor[0] = 0;
    yCor[0] = 0;
    size = max + 1;

    for (int i = 1; i < (int)size; i++) {
        xCor[i] = -1;
    }
}

StickerSheet::~StickerSheet() {
    _destroy();
}

void StickerSheet::_destroy() {
    for(int i = 0; i < (int)size; i++) {
        if (xCor[i] != -1) {
            delete pictures[i];
            pictures[i] = NULL;
        }
    }

    delete[] pictures;
    delete[] xCor;
    delete[] yCor;

    pictures = NULL;
    xCor = NULL;
    yCor = NULL;
}

StickerSheet::StickerSheet(const StickerSheet & other) {
    _copy(other);
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {
    if (this != &other) {
        _destroy();
        _copy(other);
    }
    return *this;
}
void StickerSheet::_copy(StickerSheet const &other) {
    size = other.size;
    pictures = new Image*[size];
    xCor = new int[size];
    yCor = new int[size];

    for (int i = 0; i < (int)size; i++) {
        if (other.xCor[i] != -1) {
            pictures[i] = new Image(*(other.pictures[i]));
            xCor[i] = other.xCor[i];
            yCor[i] = other.yCor[i];
        } else {
            xCor[i] = -1;
        }
    }

}

void StickerSheet::changeMaxStickers (unsigned max){
    int size1 = size;
    int size2 = max + 1;

    Image **pictures2 = new Image*[size2]; 
    int *xCor2 = new int[size2];
    int *yCor2 = new int[size2];

    for(int i = 0; i < size2; i++) {
        if(i < size1 && xCor[i] != -1) {
            pictures2[i] = new Image(*pictures[i]); 
            xCor2[i] = xCor[i];
            yCor2[i] = yCor[i];
        } else {
            xCor2[i]=-1; 
        }
    }

    _destroy();

    pictures = pictures2;
    xCor = xCor2;
    yCor = yCor2;
    size = size2;
}

int StickerSheet::addSticker (Image & sticker, unsigned x, unsigned y){
    for (int i = 0; i < (int)size; i++) {
        if(xCor[i] == -1) {
            pictures[i] = new Image(sticker);
            xCor[i] = (int)x;
            yCor[i] = (int)y;

            return i;
        }
    }
    return -1;
}

bool StickerSheet::translate (unsigned index, unsigned x, unsigned y){
    if (index + 1 > size || xCor[index + 1] == -1) {
        return false;
    }
    xCor[index + 1] = x;
    yCor[index + 1] = y;
    return true;
}

void StickerSheet::removeSticker (unsigned index){
    if(index < stickermax && num[index] != 0) {
        delete pictures[index];
        
        pictures[index] = NULL;
        xCor[index] = 0;
        yCor[index] = 0;

        num[index]--;
        stickernum--;
    }
}

Image* StickerSheet::getSticker(unsigned index) {
    if(index + 1 >= size || xCor[index + 1] == -1) {
        return NULL;
    } 
    return &(*pictures[index + 1]);
}

Image StickerSheet::render() const{
    unsigned width = 0;
    unsigned height = 0;

    for(int i = 0; i < (int)size; i++) {
        if(xCor[i] != -1) {
            if(xCor[i] + pictures[i] -> width() > width) {
                width = xCor[i] + pictures[i]->width();
            } 
            if (yCor[i]+pictures[i] -> height() > height) {
                height = yCor[i] + pictures[i] -> height();
            }
        }
    }

    Image* stickerSheet = new Image();
    stickerSheet->resize(width, height);
    for(int i = 0; i < (int)size; i++) {
        if(xCor[i] != -1) {
            for (unsigned j = 0; j < pictures[i] -> width(); j++) {
                for (unsigned k = 0; k < pictures[i] -> height(); k++) {
                    if (pictures[i] -> getPixel(j, k).a > 0) {
                        stickerSheet -> getPixel(j+xCor[i], k + yCor[i]) = pictures[i] -> getPixel(j,k);
                    }
                }
            }
        }
    }
    
    Image output = *stickerSheet;
    delete stickerSheet;
    return output;
}


