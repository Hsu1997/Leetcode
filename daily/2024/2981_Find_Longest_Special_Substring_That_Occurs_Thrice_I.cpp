#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> count(26, vector<int>(53, 0));
        int l = s.length();
        char prev = s[0];
        int curr_len = 1;
        int ans = 0;
        for (int i = 1; i < l; i++){
            char curr = s[i];
            if (curr == prev) curr_len++;
            else{
                count[prev-'a'][curr_len]++;
                prev = curr;
                curr_len = 1;
            }
        }
        count[s[l-1]-'a'][curr_len]++;
        for (int c = 50; c >= 1; c--){
            for (int i = 0; i < 26; i++){
                if (count[i][c] >= 3 || count[i][c] && count[i][c+1] || count[i][c+1] >= 2 || count[i][c+2]) return c;
            }
        }
        return (ans == 0)? -1 : ans;
    }
};

int main(){
    string s = "aaaa";
    // string s = "abcdef";
    // string s = "abcaba";
    // string s = "acc";
    // string s = "lkwwdddddnnnnnynnnnl";
    // string s = "ceeeeeeeeeeeebmmmfffeeeeeeeeeeeewww";
    // string s = "uuuuonmdkgqqqqqquuuu";
    Solution S;
    cout << S.maximumLength(s) << endl;
    return 0;
}