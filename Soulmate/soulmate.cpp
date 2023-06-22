#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, P;
    cin >> n >> P;
    
    unordered_map<int, int> modCount;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        int mod = ((a % P) + P) % P;

        if (modCount.count((P - mod) % P)) {
            cout << "Yes\n";
            return 0;
        }

        modCount[mod]++;
    }

    cout << "No\n";
    return 0;
}