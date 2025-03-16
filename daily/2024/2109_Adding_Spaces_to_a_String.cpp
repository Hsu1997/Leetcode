#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        string ans(n + m, ' ');
        int idx = 0;
        int space_idx = 0;
        int ans_idx = 0;
        while(space_idx < m){
            int k = (space_idx == 0)? spaces[space_idx] : spaces[space_idx] - spaces[space_idx - 1];
            space_idx++;
            while(k--){
                ans[ans_idx++] = s[idx++];
            }
            ans_idx++;
        }
        while(idx < n) ans[ans_idx++] = s[idx++];
        return ans;
    }
};

int main(){
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8,13,15};
    // string s = "icodeinpython";
    // vector<int> spaces = {1,5,7,9};
    // string s = "spacing";
    // vector<int> spaces = {0,1,2,3,4,5,6};
    Solution S;
    cout << S.addSpaces(s, spaces) << endl;
    return 0;
}