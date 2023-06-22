#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    
    map<int, set<int>> edges;
    
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
    }
    
    vector<pair<int,int>> bidirect;
    
    for(auto edge : edges){
        for(auto dest : edge.second){
            if(edges[dest].count(edge.first))
                bidirect.push_back(make_pair(min(edge.first, dest), max(edge.first, dest)));
        }
    }
    
    sort(bidirect.begin(), bidirect.end());
    bidirect.erase(unique(bidirect.begin(), bidirect.end()), bidirect.end());
    
    cout << bidirect.size() << "\n";
    for(auto edge: bidirect)
        cout << edge.first << " " << edge.second << "\n";
    return 0;
}