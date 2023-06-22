#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    int n1, n2;

    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for(int i = 0; i < n1; i++)
        cin >> arr1[i];
    for(int i = 0; i < n2; i++)
        cin >> arr2[i];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n1; i++) {
        while (j < n2 && arr1[i] > arr2[j]) {
            j++;
        }
        cnt += n2 - j;
    }

    cout << cnt << "\n";
    return 0;
}
