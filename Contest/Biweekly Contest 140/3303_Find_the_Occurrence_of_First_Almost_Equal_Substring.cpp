#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        int m = s.length();
        int n = pattern.length();
        if (m < n) return -1;
        unordered_map<char,int> curr;
        unordered_map<char,int> target;
        for (char c : pattern) target[c]++;
        int match = 0;
        for (int i = 0; i < n; i++){
            char temp = s[i];
            curr[temp]++;
            if (curr[temp] <= target[temp]) match++;
        }
        cout << match << endl;
        if (match >= n-1) return 0;
        for (int i = n; i < m; i++){
            char added = s[i];
            char del = s[i - n];
            curr[added]++;
            if (curr[added] <= target[added]) match++;
            curr[del]--;
            if (curr[del] < target[del]) match--;
            if (match >= n-1) return i - n + 1;
        }
        return -1;
    }
};

int main(){
    // string s = "abcdefg";
    // string pattern = "bcdffg";
    string s = "ababbababa";
    string pattern = "bacaba";
    // string s = "abcd";
    // string pattern = "dba";
    // string s = "dde";
    // string pattern = "d";
    Solution S;
    cout << S.minStartingIndex(s, pattern) << endl;
    return 0;
}