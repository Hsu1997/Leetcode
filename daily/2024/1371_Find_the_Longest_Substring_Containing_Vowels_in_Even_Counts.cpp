#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int char_to_index[26] = {0};
        char_to_index['a' - 'a'] = 1;
        char_to_index['e' - 'a'] = 2;
        char_to_index['i' - 'a'] = 4;
        char_to_index['o' - 'a'] = 8;
        char_to_index['u' - 'a'] = 16;
        int prefix = 0;
        vector<int> first_time_meet(32, -1);
        int ans = 0;
        // first_time_meet[0] = -1;
        for (int i = 0; i < s.length(); i++){
            prefix ^= char_to_index[s[i] - 'a'];
            if (first_time_meet[prefix] == -1 && prefix != 0) first_time_meet[prefix] = i;
            ans = max(ans, i - first_time_meet[prefix]);
        }
        return ans;
    }
};

int main(){
    string s = "eleetminicoworoep";
    // string s = "leetcodeisgreat";
    // string s = "bcbcbc";
    Solution S;
    cout << S.findTheLongestSubstring(s) << endl;
    return 0;
}