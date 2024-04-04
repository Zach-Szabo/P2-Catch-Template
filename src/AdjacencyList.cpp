#include <iostream>
#include "AdjacencyList.h"

using namespace std;

map<string,vector<int>> AdjacencyMap;
map<string,int> URLMaps;
int URLNum = 1;

void addPath(string firstURL, string secondURL){
    if(URLMaps.find(firstURL) == URLMaps.end()){
        URLMaps.insert({firstURL,URLNum});
        vector <int> emptyVector;
        AdjacencyMap.insert({firstURL,emptyVector});
        URLNum ++;
    }
    if(URLMaps.find(secondURL) == URLMaps.end()){
        URLMaps.insert({secondURL,URLNum});
        vector <int> URLToJoin;
        auto URL = URLMaps.find(firstURL);
        URLToJoin.push_back(URL->second);
        AdjacencyMap.insert({secondURL,URLToJoin});
        URLNum ++;
    } else{
        auto URL = URLMaps.find(firstURL);
        AdjacencyMap[secondURL].push_back(URL->second);
    }

}
// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;

    // do your page rank

    cout << result;
    return result;
}
