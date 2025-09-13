#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int v = 0;
        int c = 0;
        for (int i = 0; i < 26; i++){
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) v = max(v, cnt[i]);
            else c = max(c, cnt[i]);
        }
        return v + c;
    }
};

int main(){
    string s = "successes";
    // string s = "aeiaeia";
    Solution S;
    cout << S.maxFreqSum(s) << endl;
    return 0;
}