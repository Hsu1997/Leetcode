#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

class Solution {
public:
    bool two_string_equal(string& a, string& b){
        if (a.length() != b.length()) return false;
        for (int i = 0; i < a.length(); i++) if (a[i] != b[i] && a[i] != '?' && b[i] != '?') return false;
        return true;
    }

    bool all_done(string& a){
        for (int i = 0; i < a.length(); i++) if (a[i] != '?') return false;
        return true;
    }

    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int n = target.length();
        int m = stamp.length();
        bool find = true;

        while(find){
            find = false;
            for (int i = 0; i < n-m+1; i++){
                string temp = target.substr(i, m);
                // cout << temp << endl;
                if (all_done(temp)) continue;
                if (two_string_equal(temp, stamp)){
                    find = true;
                    for (int j = i; j < i+m; j++) target[j] = '?';
                    ans.push_back(i);
                    break;
                }
                // sleep(1);
            }
            // cout << target << endl;
        }

        if (!all_done(target)) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    // string stamp = "abc";
    // string target = "ababc";

    string stamp = "abca";
    string target = "aabcaca";

    Solution S;
    vector<int> ans = S.movesToStamp(stamp, target);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}