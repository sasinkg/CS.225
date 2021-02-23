#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "math.h"
#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG png;
  png.readFromFile(inputFile);
  cs225::PNG png2(png.width(),png.height());
  for (unsigned int x = 0; x < png2.width(); x++) {
    for (unsigned int y = 0; y < png2.height(); y++) {
      cs225::HSLAPixel &pixel=png.getPixel(x,y);
      cs225::HSLAPixel &pixel2=png2.getPixel(png2.width()-x-1,png2.height()-y-1);
      pixel2=pixel;
    }
  }
  png2.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for (unsigned int x = 0; x < width; x++) {
    for (unsigned int y = 0; y < height; y++) {
      //cs225::HSLAPixel &pixel=png.getPixel(x,y);
      double f = (x/2);
    
      double distance = sqrt((width-x/2)*(width-x/2)+(height-y/2)*(height-y/2));
      double maxDistance = sqrt((height/2)*(height/2)+(width/2)*(width/2));
      png.getPixel(x,y) = cs225::HSLAPixel(360.0* maxDistance / distance, f, maxDistance / distance, 1); 
      
      
      // png.getPixel(x,y) = cs225::HSLAPixel(360, f, f, 1);

      /* if(pixel.h >= 113.5 && pixel.h < 239.5) {
        pixel.h = 216;
      } else {
        pixel.h = 11;
      } */
      

    }
  }
  return png;

}
