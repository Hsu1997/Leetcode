#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (char c : s) if (c == '0') ans++;
        int curr = 0;
        int pos = 1;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '1'){
                curr += pos;
                if (curr > k) break;
                ans++;
            }
            if (pos > 1e9) break;
            pos *= 2;

        }
        return ans;
    }
};

int main(){
    string s = "1001010";
    int k = 5;
    // string s = "00101001";
    // int k = 1;
    // string s = "000101010011011001011101111000111111100001011000000100010000111100000011111001000111100111101001111001011101001011011101001011011001111111010011100011110111010000010000010111001001111101100001111";
    // int k = 300429827;
    Solution S;
    cout << S.longestSubsequence(s, k) << endl;
    return 0;
}