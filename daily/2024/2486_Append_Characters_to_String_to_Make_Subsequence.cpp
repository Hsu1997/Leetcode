#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int ans = t.length();
        for (int i = 0; i < s.length(); i++){
            if (s[i] == t[j]) j++, ans--;
            if (j == t.length()) return 0;
        }
        return ans;
    }
};

int main(){
    string s = "coaching";
    string t = "coding";
    // string s = "abcde";
    // string t = "a";
    // string s = "z";
    // string t = "abcde";
    Solution S;
    cout << S.appendCharacters(s, t) << endl;
    return 0;
}