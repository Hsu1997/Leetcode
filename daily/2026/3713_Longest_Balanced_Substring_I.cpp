#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; i++){
            int cnt[26] = {0};
            int maxele = 0;
            int maxcnt = 0;
            for (int j = i; j < n; j++){
                int c = s[j] - 'a';
                cnt[c]++;
                if (cnt[c] > maxele){
                    maxele = cnt[c];
                    maxcnt = 1;
                }
                else if (cnt[c] == maxele) maxcnt++;
                else continue;
                if (j - i + 1 == maxele * maxcnt) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

int main(){
    string s = "abbac";
    // string s = "zzabccy";
    // string s = "aba";
    Solution S;
    cout << S.longestBalanced(s) << endl;
    return 0;
}