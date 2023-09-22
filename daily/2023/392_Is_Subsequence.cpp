#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < t.length()){
            if (s[i] == t[j]) i++, j++;
            else j++;
        }
        return (i == s.length());
    }
};

int main(){
    // string s = "abc";
    string s = "axc";
    string t = "ahbgdc";
    Solution S;
    cout << S.isSubsequence(s, t) << endl;
    return 0;
}