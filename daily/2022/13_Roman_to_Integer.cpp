#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        if (s.length() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < s.length()-1; i++){
            if (m[s[i]] < m[s[i+1]]) ans -= m[s[i]];
            else ans += m[s[i]];
        }
        ans += m[s[s.length()-1]];
        return ans;
    }
};

int main(){
    // string s = "III";
    // string s = "LVIII";
    string s = "MCMXCIV";
    Solution S;
    cout << S.romanToInt(s) << endl;
    return 0;
}