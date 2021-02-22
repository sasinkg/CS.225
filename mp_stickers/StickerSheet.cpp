#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include "StickerSheet.h"
#include "Image.h"
#include <iostream>
using namespace std;


	StickerSheet::StickerSheet (const Image & picture, unsigned max){
		max++;
		pics = new Image [max];
		pics [0] = picture;
		pics [0].setFlag(1);
		pics [0].setXcor(0);
		pics [0].setYcor(0);
		for (unsigned i = 1; i < max; i++){
			pics [i].setFlag(0);
		}
		maxs = max;
	}
	StickerSheet::~StickerSheet(){
		delete [] pics;
	}
	StickerSheet::StickerSheet (const StickerSheet & other){
		//if (pics != NULL){
		//	delete [] pics;
		//}
		pics = new Image [other.maxs];
		maxs = other.maxs;
		for (unsigned i = 0; i < other.maxs; i++){
			pics [i] = other.pics [i];
		}
	}
	const StickerSheet & StickerSheet:: operator= (const StickerSheet & other){
		if (pics != NULL){
			delete [] pics;
		}
		pics = new Image [other.maxs];
		maxs = other.maxs;
		for (unsigned i = 0; i < maxs; i++){
			pics [i] = other.pics [i];
		}
		return *this;
	}
	void StickerSheet::changeMaxStickers (unsigned max){
		max++;
		if (max == maxs){
			return;
		}else if (max > maxs){
			Image * tempics = new Image [max];
			for (unsigned i = 0; i < maxs; i++){
				tempics [i] = pics[i];
			}
			delete [] pics;
			pics = new Image [max];
			for (unsigned i = 0; i < max; i++){
				pics [i] = tempics[i];
				if (i >= maxs){
					pics[i].setFlag(0);
				}
				//std::cout << i << std::endl;
			}
		}else{
			Image * tempics = new Image [max];
			for (unsigned i = 0; i < max; i++){
				tempics [i] = pics[i];
			}
			delete [] pics;
			pics = new Image [max];
			for (unsigned i = 0; i < max; i++){
				pics [i] = tempics[i];
			}
		}
		maxs = max;
	}
	int StickerSheet::addSticker (Image & sticker, unsigned x, unsigned y){
		for(unsigned i = 0; i < maxs; i++){
			//std::cout << pics[i].getFlag() << std::endl;
			if (pics[i].getFlag() == 0){
				sticker.setXcor (x);
				sticker.setYcor (y);
				pics [i] = sticker;
				return i;
			}
		}
		return -1;
	}
	bool StickerSheet::translate (unsigned index, unsigned x, unsigned y){
		index++;
		if (index < 0 || index >= maxs){
			return false;
		}else if (pics[index].getFlag() == 0){
			return false;
		}else{
			pics[index].setXcor(x);
			pics[index].setYcor(y);
			return true;
		}
	}
	void StickerSheet::removeSticker (unsigned index){
		pics[index+1].setFlag(0);		
	}
	Image * StickerSheet::getSticker (unsigned index){
		index++;
		if (index > 0 && index <= maxs){
			if (pics[index].getFlag() == 1){
				return &(pics[index]);
			}
		}
		return NULL;
	}
	Image StickerSheet::render() const{
		unsigned backwidth = pics[0].width();
		unsigned backheight = pics[0].height();		
		Image * canvas = new Image (backwidth, backheight);
		for (unsigned i = 0; i < maxs; i++){
			//std::cout << pics[i].getFlag() << std::endl;
			if (pics[i].getFlag() == 1){
				unsigned xloc = pics[i].getXcor();
				unsigned yloc = pics[i].getYcor();
				unsigned xwidth = pics[i].width();
				unsigned yheight = pics[i].height();

				if (xloc + xwidth > canvas->width()){
					canvas->resize(xloc+xwidth, canvas->height());
				}else if (yloc + yheight > canvas->height()){
					canvas->resize (canvas->width(), yloc+yheight);
				}

				for (unsigned xdir = 0; xdir < xwidth; xdir++){
					for (unsigned ydir = 0; ydir < yheight; ydir++){
						cs225::HSLAPixel& curr = pics[i].getPixel(xdir, ydir);
						if (xdir+xloc < canvas->width() && ydir+yloc < canvas->height() && curr.a != 0){
							cs225::HSLAPixel& back = canvas->getPixel(xdir+xloc, ydir+yloc);
							back = curr;
						}
					}
				}

			}
		}
		return *canvas;
	}

