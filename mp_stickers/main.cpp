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

  Image arsenal;
  arsenal.readFromFile("arsenal.png");

  Image youtube;
  youtube.readFromFile("youtube.png");

  alma.rotateColor(225);
  ///StickerSheet s(alma, 5000);
  // Image mariners

  StickerSheet sheet(alma, 500);
  //sheet.addSticker(arsenal,20,1);
  sheet.addSticker(youtube,20,1);
  sheet.addSticker(i, 500, 200);
  sheet.addSticker(alma, 0,0);
  
  
  sheet.render().writeToFile("myImage.png");
  
  return 0;
}
