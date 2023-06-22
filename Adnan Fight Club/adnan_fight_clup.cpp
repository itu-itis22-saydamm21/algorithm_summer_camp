#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;
    std::unordered_map<int, int> myMap;
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            int x;
            cin >> x;
            myMap[x]++;
        }
        else if (type == 2){
            int a, b;
            cin >>  a >> b;
            if(myMap.count(a) && myMap.count(a - b) && myMap.count(a + b))
                cout << "GG EZ" << endl;
            else
                cout << "GLHF" << endl;
        }
    }

	return 0;
}
