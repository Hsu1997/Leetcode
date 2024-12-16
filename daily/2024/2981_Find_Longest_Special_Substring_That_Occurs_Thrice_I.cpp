#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> count(26, vector<int>(n+1, 0));
        char prev = s[0];
        int curr_len = 1;
        count[prev-'a'][curr_len] = 1;
        int ans = -1;
        for (int i = 1; i < n; i++){
            char curr = s[i];
            if (curr == prev){
                curr_len++;
                count[curr-'a'][curr_len]++;
            }
            else{
                prev = curr;
                curr_len = 1;
                count[prev-'a'][curr_len] += 1;
            }
        }
        for (int i = 0; i < 26; i++){
            for (int l = n-1; l > 0; l--){
                count[i][l] += count[i][l+1];
                if (count[i][l] >= 3){
                    ans = max(ans, l);
                    break;
                }
            }
        }
        return ans;
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