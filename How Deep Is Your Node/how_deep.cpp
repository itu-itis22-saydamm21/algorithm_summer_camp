#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find(vector<vector<int>> &tree, int target){
    int n = tree.size();
    vector<int> depths(n, -1);
    
    queue<int> q;
    q.push(0);
    depths[0] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int child: tree[curr]){
            if(depths[child] == -1){
                depths[child] = depths[curr] + 1;
                q.push(child);
            }
        }
    }
    
    return depths[target];
}
int main(){
    int n;
    cin >> n;
    
    vector < vector<int> > tree(n);
    for(int i = 1; i < n; i++){
        int parent;
        cin >> parent;
        tree[parent - 1].push_back(i);
    }
    
    int target;
    cin >> target;
    
    int depth = find(tree, target - 1);
    cout << depth << endl;
    
    return 0;
}