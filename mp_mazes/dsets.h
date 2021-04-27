#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class DisjointSets{
    private:
    vector <int> objs {};
    
    public:
    DisjointSets();
    int find(int x);
    void setunion (int x, int y);
    void addelements (int x);
    int size(int x);
};