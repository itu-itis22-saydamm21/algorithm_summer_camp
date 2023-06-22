#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long C, monster_power;
    cin >> N >> C;
    
    vector<long long> monsters;
    
    for (int i = 0; i < N; i++) {
        cin >> monster_power;
        monsters.push_back(monster_power);
    }
    
    sort(monsters.begin(), monsters.end());
    
    int time = 0;
    for(int i = 0; i < N; i++) {
        if (C <= monsters[i]) {
            time++;
            C -= monsters[i];
            break;
        }
        else {
            C -= monsters[i];
            time++;
        }
    }

    if (C > 0)
        cout << "EV" << endl;
    else
        cout << time << endl;

    return 0;
}
