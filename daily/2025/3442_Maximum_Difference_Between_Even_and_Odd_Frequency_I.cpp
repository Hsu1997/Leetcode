#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int M = INT_MIN;
        int m = INT_MAX;
        int cnt[26] = {0};
        for (char c : s) cnt[c-'a']++;
        for (int i : cnt){
            if (i == 0) continue;
            if (i % 2 == 0) m = min(m, i);
            else M = max(M, i);
        }
        return M - m;
    }
};

int main(){
    string s = "aaaaabbc";
    // string s = "abcabcab";
    Solution S;
    cout << S.maxDifference(s) << endl;
    return 0;
}