#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int> m;
        vector<int> last_pos(n, n);
        for (int i = n-1; i >= 0; i--){
            if (m.find(s[i]) == m.end()) m[s[i]] = i;
            last_pos[i] = m[s[i]];
        }
        last_pos.push_back(n);
        vector<int> ans;
        int curr_start = 0;
        int curr_last = last_pos[0];
        for (int i = 0; i <= n; i++){
            if (i > curr_last){
                ans.push_back(i - curr_start);
                curr_start = i;
                curr_last = last_pos[i];
            }
            curr_last = max(curr_last, last_pos[i]);
        }
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