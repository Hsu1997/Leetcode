#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int last_pos[26];
        for (int i = 0; i < n; i++) last_pos[s[i] - 'a'] = i;
        vector<int> ans;
        int curr_start = 0;
        int curr_last = last_pos[s[0] - 'a'];
        for (int i = 0; i < n; i++){
            if (i > curr_last){
                ans.push_back(i - curr_start);
                curr_start = i;
                curr_last = last_pos[s[i] - 'a'];
            }
            curr_last = max(curr_last, last_pos[s[i] - 'a']);
        }
        ans.push_back(n - curr_start);
        return ans;
    }
};

int main(){
    string s = "ababcbacadefegdehijhklij";
    // string s = "eccbbbbdec";
    Solution S;
    vector<int> ans = S.partitionLabels(s);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}