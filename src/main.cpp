#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

map<string,vector<int>> AdjacencyMap;
map<string,int> URLMaps;
map<string,int> OutDegreeMap;
int URLNum = 1;

void addPath(string firstURL, string secondURL){
    if(URLMaps.find(firstURL) == URLMaps.end()){
        URLMaps.insert({firstURL,URLNum});
        vector <int> emptyVector;
        AdjacencyMap.insert({firstURL,emptyVector});
        OutDegreeMap.insert({firstURL,1});
        URLNum ++;
    }
    if(URLMaps.find(secondURL) == URLMaps.end()){
        URLMaps.insert({secondURL,URLNum});
        vector <int> URLToJoin;
        auto URL = URLMaps.find(firstURL);
        URLToJoin.push_back(URL->second);
        AdjacencyMap.insert({secondURL,URLToJoin});
        OutDegreeMap.insert({secondURL,0});
        OutDegreeMap[firstURL] = OutDegreeMap[firstURL] + 1;
        URLNum ++;
    } else{
        auto URL = URLMaps.find(firstURL);
        AdjacencyMap[secondURL].push_back(URL->second);
        OutDegreeMap[firstURL] = OutDegreeMap[firstURL] + 1;
    }

}
// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
void PageRank(int n){
    map<string,double> RankMap;
    if(n < 0){
        cout << "Unsuccesfull" << endl;
    }
    //Initializes the value for all the nodes
    for (auto& pair : URLMaps) {
        RankMap[pair.first] = 1.0 / URLMaps.size();
    }
    //Runs the rank calculation N times
    for (int i = 0; i < n; i++){
        map<string,double> newRankMap;
        //Traverses through the AdjacencyMap to find all the paths connecting the websites
        for (auto& website : AdjacencyMap) {
            vector<int> paths = website.second;
            //For each website then calculates the page rank of the websites on its paths.
            double newRank = 0.0;
            for(int j = 0; j < paths.size(); j++){
                string LinkedURL;
                //Iterates through the URLMaps list to find the name of the website pointing to the website to change
                for(auto& name: URLMaps){
                    if(name.second == paths[j]){
                        LinkedURL = name.first;
                    }
                }
                cout << "Out Degree: " << OutDegreeMap[LinkedURL] << endl;
                newRank += RankMap[LinkedURL] / OutDegreeMap[LinkedURL];
            }
            newRankMap[website.first] = newRank;
        }
        RankMap = newRankMap;
    }
    //Round the decimal places to the nearest two
    for (auto& website : RankMap) {
        website.second = round(website.second * 100) / 100;
    }
    //Print the result
    for (auto& website : RankMap) {
        cout << website.first << " " << website.second << endl;
    }
}

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        addPath(from,to);
    }
    PageRank(power_iterations);
    return 0;
}
