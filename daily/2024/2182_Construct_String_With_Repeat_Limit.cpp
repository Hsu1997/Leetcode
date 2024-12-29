#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for (char c : s) count[c-'a']++;
        string ans;
        int curr_idx = 25;
        while(curr_idx >= 0){
            if (count[curr_idx] == 0){
                curr_idx--;
                continue;
            }
            char curr = 'a' + curr_idx;
            int used = min(count[curr_idx], repeatLimit);
            count[curr_idx] -= used;
            ans.append(used, curr);
            if (count[curr_idx]){
                int next_idx = curr_idx - 1;
                while(next_idx >= 0 && count[next_idx] == 0) next_idx--;
                if (next_idx == -1) break;
                char next = 'a' + next_idx;
                ans.append(1, next);
                count[next_idx]--;
            }
        }
        return ans;
    }
};

int main(){
    string s = "cczazcc";
    int repeatLimit = 3;
    // string s = "aababab";
    // int repeatLimit = 2;
    Solution S;
    cout << S.repeatLimitedString(s, repeatLimit) << endl;
    return 0;
}