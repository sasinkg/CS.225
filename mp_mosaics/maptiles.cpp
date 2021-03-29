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

    map <Point<3>, unsigned> newMap;
    vector<Point<3>> index;

    for(unsigned i = 0; i < theTiles.size(); i++) {
        Point<3> luva = convertToXYZ(theTiles[i].getAverageColor());
        newMap.insert({luva, i});
        index.push_back(luva);
    }

    KDTree<3> tree(index);
    int row = theSource.getRows();
    int col = theSource.getColumns();
    MosaicCanvas* newCanvas = new MosaicCanvas(row, col);
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Point<3> luva = convertToXYZ(theSource.getRegionColor(i,j));
            Point<3> tiles = tree.findNearestNeighbor(luva);
            unsigned newIndex = newMap[tiles];
            newCanvas -> setTile(i,j,&theTiles[newIndex]);
        }
    }
    return newCanvas;

    // std::map <Point<3>, TileImage *> mapmap;
    // vector<Point<3>> pts;
    // for (unsigned i = 0; i < theTiles.size(); i++){
    //     LUVAPixel luv = theTiles[i].getAverageColor();
    //     Point<3> popo;
    //     popo[0] = luv.l;
    //     popo[1] = luv.u;
    //     popo[2] = luv.v;
    //     mapmap.insert(pair<Point<3>, TileImage *> (popo, &(theTiles[i]) ));
    //     pts.push_back(popo);
    // }
    // KDTree<3> treetree(pts);
    // int rows = theSource.getRows();
    // int cols = theSource.getColumns();
    // MosaicCanvas * mc = new MosaicCanvas (rows, cols);
    // for (int i = 0; i < rows; i++){
    //     for (int j = 0; j < cols; j++){
    //         LUVAPixel luv = theSource.getRegionColor(i, j);    
    //         Point<3> popo;
    //         popo[0] = luv.l;
    //         popo[1] = luv.u;
    //         popo[2] = luv.v;
    //         Point<3> po = treetree.findNearestNeighbor(popo);
    //         mc->setTile (i, j, mapmap.find(po)->second);
    //     }
    // }
    // return mc;
}
