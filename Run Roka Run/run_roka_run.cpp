#include <bits/stdc++.h>
using namespace std;
vector <int> adj[1001];
bool visited[1001];


int bfs(int start, int end){
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int> > q;
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()){
        int v = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(v == end)
            return dist;
        
        for(int u : adj[v]) {
            if(!visited[u]){
                q.push({u, dist + 1});
                visited[u] = true;
            }
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n >> m;
    int r, u;
    cin >> r >> u;
    for(int i = 0; i < n; i++){
        int u, q;
        cin >> u >> q;
        while(q--){
            int room;
            cin >> room;
            adj[u].push_back(room);
        }
    }
    int minimum_distance = bfs(r, u);
    cout << minimum_distance << endl;
	return 0;
}
