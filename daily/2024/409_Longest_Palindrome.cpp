#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int odd = false;
        unordered_map<char,int> m;
        for (int i = 0; i < s.length(); i++) m[s[i]]++;
        for (auto i : m){
            ans += i.second/2*2;
            odd |= i.second%2;
        }
        return ans + odd;
    }
};

int main(){
    string s = "abccccdd";
    // string s = "a";
    Solution S;
    cout << S.longestPalindrome(s) << endl;
    return 0;
}