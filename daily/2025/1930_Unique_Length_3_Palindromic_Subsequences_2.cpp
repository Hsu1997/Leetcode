#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++){
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i; 
        }
        int ans = 0;
        for (int k = 0; k < 26; k++){
            if (first[k] == last[k]) continue;
            int temp = 0;
            for (int j = first[k] + 1; j < last[k]; j++){
                temp |= (1 << (s[j] - 'a'));
            }
            ans += __builtin_popcount(temp);
        }
        return ans;
    }
};

int main(){
    string s = "aabca";
    // string s = "adc";
    // string s = "bbcbaba";
    Solution S;
    cout << S.countPalindromicSubsequence(s) << endl;
    return 0;
}