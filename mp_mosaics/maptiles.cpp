/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    std::map <Point<3>, TileImage *> newMap;
    vector <Point<3>> newPoint;

    for(unsigned int i = 0; i < theTiles.size(); i++) {
        LUVAPixel pixel = theTiles[i].getAverageColor();
        Point<3> newPointTwo;

        newPointTwo[0] = pixel.l;
        newPointTwo[1] = pixel.u;
        newPointTwo[2] = pixel.v;

        newMap.insert(pair <Point<3>, TileImage *> (newPoint, &(theTiles[i]) ));
    }

    KDTree<3> newTree(newPoint);
    //int rows = theSource.getRows();
    //int col = theSource.getColumns();

    MosaicCanvas * newCanvas = new MosaicCanvas(theSource.getRows(), theSource.getColumns());

    for(int i = 0; i < theSource.getRows(); i++) {
        for (int j = 0; j < theSource.getColumns(); j++) {
            LUVAPixel pixel = theSource.getRegionColor(i, j);
            Point<3> newPointTwo;

            newPointTwo[0] = pixel.l;
            newPointTwo[1] = pixel.u;
            newPointTwo[2] = pixel.v;

            Point<3> newPointThree = newTree.findNearestNeighbor(newPointTwo);
            newCanvas -> setTile(i,j, newMap.find(newPointThree) -> second);
        }
    }
    return newCanvas;
}

