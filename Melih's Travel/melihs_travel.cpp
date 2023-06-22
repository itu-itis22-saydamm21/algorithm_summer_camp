#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> graph[200005];
set<int> unvisited;

void dfs(int v) {
    cout << v << " ";
    unvisited.erase(v);

    while(!graph[v].empty()) {
        auto it = max_element(graph[v].begin(), graph[v].end());
        int u = *it;
        graph[v].erase(it);
        if(unvisited.count(u)) {
            dfs(u);
        }
    }

    if(!unvisited.empty()) {
        dfs(*unvisited.begin());
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        unvisited.insert(i);
    }

    dfs(1);

    return 0;
}
