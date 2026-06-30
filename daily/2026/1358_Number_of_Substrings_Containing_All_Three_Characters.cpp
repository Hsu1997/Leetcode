#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> cnt(26, 0);
        int ptr = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                cnt[s[ptr++] - 'a']--;
            }
            ans += ptr;
        }
        return ans;
    }
};

int main(){
    string s = "abcabc";
    // string s = "aaacb";
    // string s = "abc";
    Solution S;
    cout << S.numberOfSubstrings(s) << endl;
    return 0;
}