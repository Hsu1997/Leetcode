#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c : text) cnt[c-'a']++;
        int ans = text.length();
        ans = min(ans, cnt['b' - 'a']);
        ans = min(ans, cnt['a' - 'a']);
        ans = min(ans, cnt['l' - 'a'] / 2);
        ans = min(ans, cnt['o' - 'a'] / 2);
        ans = min(ans, cnt['n' - 'a']);
        return ans;
    }
};

int main(){
    string text = "nlaebolko";
    // string text = "loonbalxballpoon";
    // string text = "leetcode";
    Solution S;
    cout << S.maxNumberOfBalloons(text) << endl;
    return 0;
}