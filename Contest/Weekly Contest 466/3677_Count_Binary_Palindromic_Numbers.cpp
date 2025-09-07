#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBinaryPalindromes(long long n) {
        if (n < 2) return n + 1;
        
        string s;
        long long x = n;
        while(x){
            s.push_back('0' + (x & 1));
            x /= 2;
        }
        reverse(s.begin(), s.end());
        // cout << s << endl;

        // total len = [2 : l-1], start with 1
        int l = s.length();
        int ans = 2;
        for (int i = 2; i < l; i++){
            ans += 1 << ((i + 1) / 2 - 1);
        }

        // len = l, start with 1
        // [ x | ~x ], x = [1......], count how many between x and [1000000]
        long long prefix = 0;
        for (int i = 0; i < (l + 1) / 2; i++){
            prefix |= (s[i] - '0') << ((l + 1) / 2 - 1 - i);
        }
        long long min_prefix = 1 << ((l + 1) / 2 - 1);
        ans += prefix - min_prefix;

        // Is [ x | ~x ] smaller than n?
        string left = s.substr(0, (l + 1) / 2);
        string right = left.substr(0, l / 2);
        reverse(right.begin(), right.end());
        string palindrome = left + right;
        if (palindrome <= s) ans++;

        return ans;        
    }
};

using namespace std;

int main(){
    // int n = 9;
    // int n = 0;
    int n = 10;
    Solution S;
    cout << S.countBinaryPalindromes(n) << endl;
    return 0;
}