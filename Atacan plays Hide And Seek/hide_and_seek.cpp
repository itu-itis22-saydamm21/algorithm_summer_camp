#include <bits/stdc++.h>

using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> walls(N);
    vector<int> friends(M);
    unordered_map<int, int> mp;
    unordered_map<int, int> index;
    for(int i = 0; i < N; i++){
        cin >> walls[i];
        index[walls[i]] = i;
        mp[walls[i]]++;
        
    }
    for(int i = 0; i < M; i++){
        cin >> friends[i];
    }
    for(int i = 0; i < M; i++){
        if(mp[friends[i]] == 1)
            cout << index[friends[i]] + 1<< "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}