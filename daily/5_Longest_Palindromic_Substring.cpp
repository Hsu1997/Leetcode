#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans_head = 0;
        int ans_length = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n){
            j = i;
            k = i;
            while(j+1 < n && s[j] == s[j+1]) j++;
            // cout << "i = " << i << ", j = " << j << ", k = " << k;
            i = j+1;
            while(k-1 >= 0 && j+1 < n && s[k-1] == s[j+1]) k--,j++;
            // cout << " i = " << i << ", j = " << j << ", k = " << k;
            if (j - k + 1 > ans_length) ans_head = k, ans_length = j - k + 1;
            // cout << ", now is : " << ans_head << " " << ans_tail << endl;
        }
        
        return s.substr(ans_head, ans_length);
    }
};

int main(){
    string s = "babad";
    Solution S;
    cout << S.longestPalindrome(s) << endl;
    return 0;
}