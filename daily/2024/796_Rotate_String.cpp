#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int n = goal.length();
        string f = goal + '#' + s + s;
        int w = f.length();
        vector<int> lps(w, 0);
        int len = 0;
        for (int i = 1; i < w; i++){
            while(len > 0 && f[i] != f[len]){
                len = lps[len-1];
            }
            if (f[i] == f[len]) len++;
            lps[i] = len;
            if (len == n) return true;
        }
        return false;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    // string s = "abcde";
    // string goal = "abced";
    // string s = "aa";
    // string goal = "a";
    Solution S;
    cout << S.rotateString(s, goal) << endl;
    return 0;
}