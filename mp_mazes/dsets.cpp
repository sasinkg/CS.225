/* Your code here! */
#include <cmath>
#include "dsets.h"

DisjointSets::DisjointSets() {
}

int DisjointSets::find(int x) {
    if (objs[x] < 0) {
        return x;
    } else {
        int root = find (objs[x]);
        objs[x] = root;
        return root;
    }
}
void DisjointSets::addelements (int x) {
    for (int i = 0; i < x; i++) {
        objs.push_back(-1);
    }
}
void DisjointSets::setunion(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    if (root1 == root2) {
        return;
    }

    int newSize = objs[root1] + objs[root2];

    if(objs[root1] <= objs[root2]) {
        objs[root2] = root1;
        objs[root1] = newSize;
    } else {
        objs[root1] = root2;
        objs[root2] = newSize;
    }
}



int DisjointSets::size (int x) {
    return abs (objs[find(x)]);
}