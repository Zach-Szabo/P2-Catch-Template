#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class AdjacencyList {
    private:
    //Think about what member variables you need to initialize
    map<string,vector<int>> AdjacencyMap;
    map<string,int> URLMaps;
    int URLNum;
    public:
    //Think about what helper functions you will need in the algorithm
    void addPath(string firstURL, string secondURL);
    string PageRank(int n);
};

// This class and method are optional.
