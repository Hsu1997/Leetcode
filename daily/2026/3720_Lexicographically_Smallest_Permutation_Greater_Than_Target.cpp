#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool remainGreater(int idx, vector<int> cnt, string target){
        for (int c = 25; c >= 0; c--){
            while(cnt[c]){
                if (c > target[idx] - 'a') return true;
                if (c < target[idx] - 'a') return false;
                cnt[c]--;
                idx++;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        string ans(n, ' ');
        for (int i = 0; i < n; i++){
            int curr = target[i] - 'a';
            if (cnt[curr]){
                cnt[curr]--;
                if (remainGreater(i + 1, cnt, target)){
                    ans[i] = target[i];
                    continue;
                }
                cnt[curr]++;
            }
            for (int c = curr + 1; c < 26; c++){
                if (cnt[c]){
                    cnt[c]--;
                    ans[i] = 'a' + c;
                    int idx = 0;
                    for (int j = i + 1; j < n; j++){
                        while(cnt[idx] == 0) idx++;
                        ans[j] = 'a' + idx;
                        cnt[idx]--;
                    }
                    return ans;
                }
            }
            return "";
        }
        return "";
    }
};

int main(){
    string s = "abc";
    string target = "bba";
    // string s = "leet";
    // string target = "code";
    // string s = "baba";
    // string target = "bbaa";
    Solution S;
    cout << S.lexGreaterPermutation(s, target) << endl;
    return 0;
}