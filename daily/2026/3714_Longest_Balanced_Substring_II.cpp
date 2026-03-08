#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int duo(string& s, char c1, char c2){
        int n = s.length();
        int delta = 0;
        int ans = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++){
            if (s[i] != c1 && s[i] != c2){
                delta = 0;
                m.clear();
                m[0] = i;
            }
            else{
                delta += (s[i] == c1)? 1 : -1;
                if (m.find(delta) != m.end()) ans = max(ans, i - m[delta]);
                else m[delta] = i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        int c = 1;
        for (int i = 1; i < n; i++){
            if (s[i] == s[i-1]){
                c++;
                ans = max(ans, c);
            }
            else c = 1;
        }
        ans = max({ans, duo(s, 'a', 'b'), duo(s, 'a', 'c'), duo(s, 'b', 'c')});
        unordered_map<unsigned long long, int> m;
        int cnt[3] = {0};
        m[0] = -1;
        for (int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
            unsigned long long curr = (unsigned long long)((unsigned int)(cnt[1] - cnt[0])) << 32 | ((unsigned int)(cnt[2] - cnt[0]));
            if (m.find(curr) != m.end()) ans = max(ans, i - m[curr]);
            else m[curr] = i;
        }
        return ans;
    }
};

int main(){
    // string s = "abbac";
    // string s = "aabcc";
    // string s = "aba";
    string s = "acbab";
    Solution S;
    cout << S.longestBalanced(s) << endl;
    return 0;
}