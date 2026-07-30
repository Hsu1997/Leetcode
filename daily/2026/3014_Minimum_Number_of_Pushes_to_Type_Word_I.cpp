#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (char c : word) cnt[c - 'a']++;
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++){
            ans += cnt[i] * (i / 8 + 1);
        }
        return ans;
    }
};

int main(){
    string word = "abcde";
    // string word = "xycdefghij";
    Solution S;
    cout << S.minimumPushes(word) << endl;
    return 0;
}