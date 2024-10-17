#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> z_function(string& s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    int minStartingIndex(string s, string pattern) {
        int n = s.length();
        int m = pattern.length();
        if (n < m) return -1;
        string prefix = pattern + "#" + s;
        reverse(pattern.begin(), pattern.end());
        reverse(s.begin(), s.end());
        string suffix = pattern + "#" + s;
        vector<int> pre = z_function(prefix);
        // cout << prefix << endl;
        // for (int i : pre) cout << i;
        // cout << endl;
        vector<int> suf = z_function(suffix);
        // cout << suffix << endl;
        // for (int i : suf) cout << i;
        // cout << endl;
        pre = vector<int>(pre.begin() + m + 1, pre.end());
        suf = vector<int>(suf.begin() + m + 1, suf.end());
        reverse(suf.begin(), suf.end());
        // for (int i : pre) cout << i;
        // cout << endl;
        // for (int i : suf) cout << i;
        // cout << endl;
        for (int i = 0; i + m - 1 < n; i++){
            // cout << i << " : " << pre[i] << "+" << suf[i+m-1] << "+" << 1 << endl;
            if (pre[i] + suf[i+m-1] + 1 >= m) return i;
        }
        return -1;
    }

};

int main(){
    string s = "abcdefg";
    string pattern = "bcdffg";
    // string s = "ababbababa";
    // string pattern = "bacaba";
    // string s = "abcd";
    // string pattern = "dba";
    // string s = "dde";
    // string pattern = "d";
    // string s = "eeedededeedeedeeedeedddededeeddeedeedeeddededdddddedde";
    // string pattern = "deeddee";
    Solution S;
    cout << S.minStartingIndex(s, pattern) << endl;
    return 0;
}