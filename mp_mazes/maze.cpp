 //Your code here! 
#include "maze.h"
#include <iostream>

using namespace std;
using namespace cs225;

SquareMaze::SquareMaze() {
    height = 0;
    width = 0;
}

void SquareMaze::makeMaze(int newWidth, int newHeight) {
    theMaze.clear();
    width = newWidth;
    height = newHeight;
    for (int i = 0; i< width * height; i++) {
        theMaze.push_back(3);
    }
    djs.addelements(width*height);

    while (djs.size(0) != width*height) {
        int randomWall = rand() % 2;
        int randomSquare = rand() % (width * height);
        int newX = randomSquare % (width);
        int newY = randomSquare / width;

        if (newY == height - 1 && randomWall == 1) {
            continue;
        }
        if (newX == width - 1 && randomWall == 0) {
            continue;
        }
        

        if (randomWall == 1 && (djs.find(randomSquare) != djs.find(randomSquare + width))) {
            setWall(newX, newY, randomWall, false);
            djs.setunion(randomSquare, randomSquare + width);
        } else if (randomWall == 00 && (djs.find(randomSquare) != djs.find(randomSquare+1))) {
            setWall(newX, newY, randomWall, false);
            djs.setunion(randomSquare, randomSquare + 1);
        }
    }
}

void SquareMaze::setWall(int x, int y, bool check, int direction) {
    //return;
    int curr = theMaze[y*width + x];
    if (check == true) {
        if (curr == 3) {
            return;
        }
        if (direction == 0) {
            if (curr == 0) {
                theMaze[y*width + x] = 1;
            }
            else if (curr == 2) {
                theMaze[y*width + x] = 3;//return;
            } else if (curr == 1) {
                return;
            }
        } else if (direction == 1) {
            if (curr == 0) {
                theMaze[y*width + x] = 2;
            } else if (curr == 2) {
                theMaze[y*width + x] = 3;
            } else if (curr == 1) {
               return; 
            }
        }
    } else {
        if (curr == 0) {
            return;
        } if (direction == 0) {
            if (curr == 3) {
                theMaze[y*width + x] = 2;
            } else if (curr == 1) {
                theMaze[y*width + x] = 0;
            } else if (curr == 2) {
                return;
            }
        } else if (direction == 1) {
            if (curr == 3) {
                theMaze[y*width + x] = 1;
            } else if (curr == 2) {
                theMaze[y*width + x] = 0;
            } else if (curr == 0) {
                return;
            }
        }
    }
    
}

bool SquareMaze::canTravel(int x, int y, int direction) const {
   // return 0;
   if (direction == 1 && x >= height - 1) {
        return false;
    }
    if (direction == 0 && x >= width - 1) {
        return false;
    }
    if (direction == 2 && x < 1) {
        return false;
    } 
    if (direction == 3 && y < 1 ) {
        return false;
    }

    int curr = theMaze[y*width + x];

    if (direction == 0) {
        if ((curr == 0 || curr == 2)) {
            return true;
        }
    }
    if (direction == 1) {
        if ((curr == 0 || curr == 1)) {
            return true;
        }
    }
    if (direction == 2) {
        if ((theMaze[y*width + (x-1)] == 0 || theMaze[y*width + (x-1)] == 2)) {
            return true;
        }
    }
    if (direction == 2) {
        if ((theMaze[y*width + (x)] == 0 || theMaze[y*width + (x)] == 1)) {
            return true;
        }
    }
    return false;
}

vector <int> SquareMaze::solveMaze() {
    queue <int> thequeue;
    vector <int> path;

    vector <int> test = {};
    return test;
}

PNG * SquareMaze::drawMaze() const {
  //  true;
  double widthNew = width*10 + 1;
  double heightNew = height*10 + 1;
  PNG *res = new PNG(widthNew, heightNew);
  return res;
}