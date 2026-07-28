#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        sort(s.begin(), s.begin() + n / 2);
        sort(s.begin() + (n + 1) / 2, s.end(), greater<char>());
        return s;
    }
};

int main(){
    string s = "z";
    // string s = "babab";
    // string s = "daccad";
    // string s = "yey";
    Solution S;
    cout << S.smallestPalindrome(s) << endl;
    return 0;
}