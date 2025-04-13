#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c-'a']++;
        string ans;
        char middle;
        for (int i = 0; i < 26; i++){
            ans += string(count[i]/2, 'a' + i);
            if (count[i] % 2 == 1) middle = 'a' + i;
        }
        string tail = ans;
        reverse(tail.begin(), tail.end());
        if (n % 2 == 1) ans += string(1, middle);
        ans += tail;
        return ans;
    }
};

int main(){
    string s = "z";
    // string s = "babab";
    // string s = "daccad";
    Solution S;
    cout << S.smallestPalindrome(s) << endl;
    return 0;
}