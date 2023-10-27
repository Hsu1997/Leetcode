#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int longest = 0;
        string ans;
        for (int i = 0; i < n; i++){
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                if (right-left+1 > longest){
                    longest = right-left+1;
                    ans = s.substr(left, longest);
                }
                left--, right++;
            }
        }
        for (int i = 0; i < n-1; i++){
            int left = i;
            int right = i+1;
            if (s[left] != s[right]) continue;
            while(left >= 0 && right < n && s[left] == s[right]){
                if (right-left+1 > longest){
                    longest = right-left+1;
                    ans = s.substr(left, longest);
                }
                left--, right++;
            }
        }
        return ans;
    }
};

int main(){
    // string s = "babad";
    // string s = "cbbd";
    // string s = "abb";
    string s = "aacabdkacaa";
    Solution S;
    cout << S.longestPalindrome(s) << endl;
    return 0;
}