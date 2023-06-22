#include <bits/stdc++.h>

const int MAX = 100005;
using namespace std;
bool visited[MAX];
vector<int> adj[MAX];
int dist[MAX];

void    BFS(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a, b, c;
    cin >> a >> b >> c;
    memset(visited, false, sizeof(visited));
    BFS(a);
    int distA[n + 1];
    for (int i = 1; i <= n; i++)
        distA[i] = dist[i];
    memset(visited, false, sizeof(visited));
    BFS(b);
    int distB[n + 1];
    for (int i = 1; i <= n; i++)
        distB[i] = dist[i];
    memset(visited, false, sizeof(visited));
    BFS(c);
    int distC[n + 1];
    for (int i = 1; i <=n ; i++)
        distC[i] = dist[i];
    int minDist = INT_MAX;
    int node;
    for(int i = 1; i <= n; i++){
        if(distA[i] + distB[i] + distC[i] < minDist)
        {
            minDist = distA[i] + distB[i] + distC[i];
            node = i;
        }
    }
    cout << node << endl;
	return 0;
}
