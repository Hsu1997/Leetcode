#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int start = 0;
        int ans = 0;
        vector<int> cnt(26);
        for (int end = 0; end < n; end++){
            int curr = s[end] - 'a';
            cnt[curr]++;
            while(start <= end && cnt[curr] > 2){
                cnt[s[start++] - 'a']--;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

int main(){
    string s = "bcbbbcba";
    // string s = "aaaa";
    Solution S;
    cout << S.maximumLengthSubstring(s) << endl;
    return 0;
}