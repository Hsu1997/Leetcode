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
        int temp = m[s[0]];
        for (int i = 1; i < s.length(); i++){
            if (temp < m[s[i]]) temp = m[s[i]] - temp;
            else{
                // cout << temp << " ";
                ans += temp;
                temp = m[s[i]];
            }
        }
        ans += temp;
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