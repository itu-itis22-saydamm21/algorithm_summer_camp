#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int m, n;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if (x <=n && y <=n){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
    }
    for(int i = 1; i <=n; i++)
        cout << adj[i].size() << " ";
}