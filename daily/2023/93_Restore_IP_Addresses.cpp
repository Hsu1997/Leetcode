#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    string s;
    vector<string> ans;

    void dfs(vector<int>& position){
        // cout << "dfs " << position.size()+1 << endl;
        if (position.size() == 3) determine(position);
        else{
            for (int i = 1; i <= 3; i++){
                position.push_back(i);
                // for (auto i : position) cout << i << " ";
                // cout << endl;
                dfs(position);
                position.pop_back();
            }
        }
    }

    void determine(vector<int> position){
        int temp = n - position[0] - position[1] - position[2];
        if (temp < 1) return;
        position.push_back(temp);
        int p = 0;
        string ip;
        for (auto i : position){
            string t = s.substr(p,i);
            p += i;
            if (stoi(t) < 0 || stoi(t) > 255 || (t.length() != 1 && t[0] == '0')) return;
            ip += t + '.';
        }
        ip.pop_back();
        ans.push_back(ip);
        return;
    }

    vector<string> restoreIpAddresses(string _s) {
        s = _s;
        n = s.length();
        if (n < 4 || n > 12) return ans;
        vector<int> dot;
        dfs(dot);
        return ans;
    }
};

int main(){
    // string s = "25525511135";
    // string s = "0000";
    string s = "101023";
    Solution S;
    vector<string> ans = S.restoreIpAddresses(s);
    for (auto i : ans) cout << i << endl;
    return 0;
}