
#pragma once
#include <iostream>
#include "Image.h"
using namespace std;

class StickerSheet {
	public:
        StickerSheet (const Image &picture, unsigned max);
        ~StickerSheet();
        StickerSheet(const StickerSheet & other);
        const StickerSheet & operator= (const StickerSheet & other);
        void changeMaxStickers (unsigned max);
        int addSticker (Image & sticker, unsigned x, unsigned y);
		bool translate (unsigned index, unsigned x, unsigned y);
		void removeSticker (unsigned index);
		Image * getSticker (unsigned index);
		Image render() const;
    private:
        void _destroy();
        void _copy(StickerSheet const & other);
       // unsigned stickermax;
       // unsigned stickernum;
        Image* *pictures;
      //  int *num;
        unsigned int size;
        int *yCor;
        int *xCor;
};
 
