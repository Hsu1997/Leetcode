#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        vector<int> count(26, 0);
        for (char c : s) count[c-'a']++;
        int odd = 0;
        for (int i : count) if (i % 2) odd++;
        return odd <= k;
    }
};

int main(){
    string s  = "annabelle";
    int k = 2;
    // string s  = "leetcode";
    // int k = 3;
    // string s  = "true";
    // int k = 4;
    Solution S;
    cout << S.canConstruct(s, k) << endl;
    return 0;
}