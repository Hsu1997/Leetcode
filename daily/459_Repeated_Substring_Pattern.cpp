#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool subprob(string& s, int l){
        for (int i = l; i < s.length(); i++){
            if (s[i] != s[i%l]) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++){
            if (n % i == 0 && s[0] == s[i] && subprob(s, i)) return true; 
        }
        return false;
    }
};

int main(){
    string s = "abab";
    // string s = "aba";
    // string s = "abcabcabcabc";
    Solution S;
    cout << S.repeatedSubstringPattern(s) << endl;
    return 0;
}