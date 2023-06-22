#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100005
vector<int> tree[MAX];
vector <bool> visited(MAX, false);
int sum = 0;

void dfs(int node, int depth){
    visited[node] = true;
    bool isLeaf = true;
    for(auto child: tree[node]){
        if(!visited[child]){
            dfs(child, depth + 1);
            isLeaf = false;
        }
    }
    if(isLeaf == true)
        sum += depth;
}

int main() {
    int N, u, v;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    cout << sum * 2;
    return 0;
}