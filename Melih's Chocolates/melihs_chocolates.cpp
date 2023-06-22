#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int main() {
    int x, y, a, b;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int cnt = 0;
        while(x >0 && y > 0){
            int tmp1, tmp2;
            tmp1 = max(x, y) - max(a, b);
            tmp2 = min(x, y) - min(a, b);
            x = tmp1;
            y = tmp2;
            if(x < 0 || y < 0)
                break;
            cnt++;
        }
        cout << cnt << endl;
    }
	return 0;
}
