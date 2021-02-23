#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image alma;
  alma.readFromFile("tests/alma.png");

  Image i;
  i.readFromFile("tests/i.png");
  i.scale(0.35);

  Image arsenal2;
  arsenal2.readFromFile("arsenal2.png");
  arsenal2.scale(0.035);

  Image youtube;
  youtube.readFromFile("youtube.png");
  youtube.scale(0.066);

  //alma.rotateColor(225);
  ///StickerSheet s(alma, 5000);
  // Image mariners

  StickerSheet sheet(alma, 800);
  //StickerSheet sheet2(i, 100);
  sheet.addSticker(arsenal2,200,200);
  sheet.addSticker(youtube,200,350);

  sheet.addSticker(i, 100, 250);


  
  
  
  sheet.render().writeToFile("myImage.png");
  
  return 0;
}
