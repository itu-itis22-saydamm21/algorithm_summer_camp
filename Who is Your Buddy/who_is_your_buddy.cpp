#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string findSmallestPalindrome(string clue) {
    vector<int> freq(26, 0);

    for (char ch : clue) {
        freq[ch - 'A']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount > 1) {
        return "NO SOLUTION";
    }

    string firstHalf = "", secondHalf = "", mid = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            mid = std::string(1, i + 'A');
            freq[i]--;
        } 
        firstHalf += string(freq[i] / 2, i + 'A');
    }

    secondHalf = firstHalf;
    
    reverse(secondHalf.begin(), secondHalf.end());

    return firstHalf + mid + secondHalf;
}

int main() {
    string clue;
    cin >> clue;
    cout << findSmallestPalindrome(clue);
    return 0;
}
