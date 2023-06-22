#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector < pair<int,int> > ranges(N);
    
    for (int i = 0; i < N; i++)
        cin >> ranges[i].first >> ranges[i].second;
    
    sort(ranges.begin(), ranges.end());
    
    while(Q--){
        int x;
        cin >> x;
        bool found = false;
        
        int left = 0, right = N - 1;
        while(left <= right) {
            int mid = (right + left) / 2;
            if (x <= ranges[mid].second && x >= ranges[mid].first)
            {
                found = true;
                break;
            }
            else if (x < ranges[mid].first)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (found)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}