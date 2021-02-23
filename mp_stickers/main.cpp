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

  alma.rotateColor(225);
  StickerSheet s(alma, 5000);
  // Image mariners

  StickerSheet sheet(alma, 5);
  
  sheet.addSticker(i, 500, 200);
  sheet.addSticker(alma, 200,200);
  sheet.render().writeToFile ("myImage.png");
  return 0;
}
