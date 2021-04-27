 //Your code here! 
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "dsets.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <queue>
using namespace cs225;
using namespace std;

class SquareMaze {
    public:
        SquareMaze();
        void makeMaze (int width, int height);
         bool canTravel (int x, int y, int direction) const;
        void setWall (int x, int y, bool check, int direction);
        vector <int> solveMaze();
        PNG * drawMaze() const;
        PNG *drawMazeWithSolution();

        private:
        DisjointSets djs;
        int width;
        int height;
        vector <int> theMaze;
};

